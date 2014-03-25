// --------------------------------------------------------------------
// Copyright (c) 2007 by Terasic Technologies Inc.
// --------------------------------------------------------------------
//
// Permission:
//
//   Terasic grants permission to use and modify this code for use
//   in synthesis for all Terasic Development Boards and Altera Development
//   Kits made by Terasic.  Other use of this code, including the selling
//   ,duplication, or modification of any portion is strictly prohibited.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  Terasic provides no warranty regarding the use
//   or functionality of this code.
//
// --------------------------------------------------------------------
//
//                     Terasic Technologies Inc
//                     356 Fu-Shin E. Rd Sec. 1. JhuBei City,
//                     HsinChu County, Taiwan
//                     302
//
//                     web: http://www.terasic.com/
//                     email: support@terasic.com
//
// --------------------------------------------------------------------
// This code was modified by Daniel Fiske

#include "I2C.h"

#define SDA_DIR_IN(data_base)   IOWR_ALTERA_AVALON_PIO_DIRECTION(data_base,0)
#define SDA_DIR_OUT(data_base)  IOWR_ALTERA_AVALON_PIO_DIRECTION(data_base,1)

#define SDA_HIGH(data_base)     IOWR_ALTERA_AVALON_PIO_DATA(data_base, 1)
#define SDA_LOW(data_base)      IOWR_ALTERA_AVALON_PIO_DATA(data_base, 0)
#define SDA_READ(data_base)     IORD_ALTERA_AVALON_PIO_DATA(data_base)

#define SCL_HIGH(clk_base)      IOWR_ALTERA_AVALON_PIO_DATA(clk_base, 1)
#define SCL_LOW(clk_base)       IOWR_ALTERA_AVALON_PIO_DATA(clk_base, 0)
#define SCL_READ(clk_base)		IORD_ALTERA_AVALON_PIO_DATA(clk_base)

#define SCL_DELAY				usleep(CLK_DELAY_TIME)



// low level internal functions
void i2c_start(alt_u32 clk_base, alt_u32 data_base);
void i2c_stop(alt_u32 clk_base, alt_u32 data_base);
bool i2c_selectAddress(alt_u32 clk_base, alt_u32 data_base, alt_8 address);
bool i2c_write(alt_u32 clk_base, alt_u32 data_base, alt_u8 Data);
void i2c_read(alt_u32 clk_base, alt_u32 data_base, alt_u8 *pData, bool bAck);

/* Write an i2c start condition */
void I2C_Start(alt_u32 clk_base, alt_u32 data_base)
{
	i2c_start(clk_base, data_base);
}

/* Write an i2c stop condition */
void I2C_Stop(alt_u32 clk_base, alt_u32 data_base)
{
	i2c_stop(clk_base, data_base);
}

/* Write len bytes of data to specified device */
bool I2C_WriteToDevice(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr, alt_u8 *pData, alt_u16 len)
{
	int i;
	bool bSuccess = true;

	if (!i2c_selectAddress(clk_base, data_base, deviceAddr))
		return false;

	for (i = 0; i < len && bSuccess; i++)
	{
		bSuccess = i2c_write(clk_base, data_base, *pData);
		pData++;
	}

	if (!bSuccess)
	{
		printf("I2C Error: Data write to device 0x%02x failed\n", deviceAddr);
		return false;
	}

    return true;
}

/* Write len bytes of data to specified control register of specified device */
bool I2C_WriteToDeviceRegister(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr,
							   alt_u8 controlAddr, alt_u8 *pData, alt_u16 len)
{
	int i;
	bool bSuccess = true;

	if (!i2c_selectAddress(clk_base, data_base, deviceAddr))
		return false;

	if (!i2c_selectAddress(clk_base, data_base, controlAddr))
		return false;

	for (i = 0; i < len && bSuccess; i++)
	{
		bSuccess = i2c_write(clk_base, data_base, *pData);
		pData++;
	}

	if (!bSuccess)
	{
		printf("I2C Error: Data write to register 0x%02x on device 0x%02x failed\n", deviceAddr, controlAddr);
		return false;
	}

    return true;
}

/* Write len bytes of data to last address */
bool I2C_WriteMore(alt_u32 clk_base, alt_u32 data_base, alt_u8 *pData, alt_u16 len)
{
	int i;
	bool bSuccess = true;

	for (i = 0; i < len && bSuccess; i++)
	{
		bSuccess = i2c_write(clk_base, data_base, *pData);
		pData++;
	}

	if (!bSuccess)
	{
		printf("I2C Error: Additional data write failed\n");
		return false;
	}

    return true;
}

/* Read len bytes of data from specified device */
bool I2C_ReadFromDevice(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr, alt_u8 *pBuf, alt_u16 len, bool endRead)
{
    int i;
    deviceAddr |= 1; // Read address

	if (!i2c_selectAddress(clk_base, data_base, deviceAddr))
		return false;

	for (i = 0; i < len; i++)
	{
		if (i == (len - 1))
		{
			i2c_read(clk_base, data_base, pBuf, !endRead);  // last byte
		}
		else
		{
			i2c_read(clk_base, data_base, pBuf, true);  // read
			pBuf++;
		}
	}

	return true;
}

/* Read len bytes of data from specified control register of specified device */
bool I2C_ReadFromDeviceRegister(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr,
								alt_u8 controlAddr, alt_u8 *pBuf, alt_u16 len, bool endRead)
{
    int i;

	if (!i2c_selectAddress(clk_base, data_base, deviceAddr))
		return false;

	if (!i2c_selectAddress(clk_base, data_base, controlAddr))
		return false;

    i2c_start(clk_base, data_base);  // restart
    deviceAddr |= 1; // Read address

	if (!i2c_selectAddress(clk_base, data_base, deviceAddr))
		return false;

	for (i = 0; i < len; i++)
	{
		if (i == (len - 1))
		{
			i2c_read(clk_base, data_base, pBuf, !endRead);  // last byte
		}
		else
		{
			i2c_read(clk_base, data_base, pBuf, true);  // read
			pBuf++;
		}
	}

	return true;
}

/* Read len bytes of data from last address */
void I2C_ReadMore(alt_u32 clk_base, alt_u32 data_base, alt_u8 *pBuf, alt_u16 len, bool endRead)
{
    int i;

	for (i = 0; i < len; i++)
	{
		if (i == (len - 1))
		{
			i2c_read(clk_base, data_base, pBuf, !endRead);  // last byte
		}
		else
		{
			i2c_read(clk_base, data_base, pBuf, true);  // read
			pBuf++;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
///////////// Internal functions (i2c_XXX) body //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// write the given address on the i2c bus
bool i2c_selectAddress(alt_u32 clk_base, alt_u32 data_base, alt_8 address)
{
    if (!i2c_write(clk_base, data_base, address))
    {
		printf("I2C Error: Address write to device 0x%02x failed\n", address);
    	return false;
    }

    return true;
}

//SDA 1->0 while SCL=1
void i2c_start(alt_u32 clk_base, alt_u32 data_base)
{
    // make sure it is in normal state
    SDA_DIR_OUT(data_base);  // data output enabled

    // start condition
    SDA_HIGH(data_base); // data high
    SCL_HIGH(clk_base);
    SCL_DELAY;
    SDA_LOW(data_base); // data low
    SCL_DELAY;
    SCL_LOW(clk_base); // clock low
    SCL_DELAY;
}

// SDA 0->1 while SCL=1
void i2c_stop(alt_u32 clk_base, alt_u32 data_base)
{
    // assume SCL = 0

    SDA_DIR_OUT(data_base);  // data output enabled
    SDA_LOW(data_base); // Data Low
    //SCL_DELAY;
    SCL_HIGH(clk_base);  // clock high
    SCL_DELAY; // clock high long delay
    SDA_HIGH(data_base); // data high
    SCL_DELAY; // data high delay
}

// return true if device response ack
bool i2c_write(alt_u32 clk_base, alt_u32 data_base, alt_u8 Data)
{
    alt_u8 Mask = 0x80;
    bool bAck;
    int i;

    // assume, SCL = 0

    SDA_DIR_OUT(data_base);  // data write mode

    for (i = 0; i < 8; i++)
    {
        SCL_LOW(clk_base);  // new, make sure data change at clk low
        // output data on bus
        if (Data & Mask)
        { // there is a delay in this command
            SDA_HIGH(data_base);
        }
        else
        {
            SDA_LOW(data_base);
        }
        Mask >>= 1; // there is a delay in this command
        // clock high
        SCL_HIGH(clk_base);
        while (SCL_READ(clk_base) == 0); // clock stretching
        SCL_DELAY;
        SCL_LOW(clk_base);
        SCL_DELAY;
    }

    //===== get ack
    SDA_DIR_IN(data_base);  // data read mode
    //SCL_DELAY;
    // clock high
    SCL_HIGH(clk_base);  // clock high
    while (SCL_READ(clk_base) == 0); // clock stretching
    SCL_DELAY;  // clock high delay
    bAck = SDA_READ(data_base)?false:true;  // get ack
    //SCL_DELAY;
    //SDA_DIR_OUT;
    SCL_LOW(clk_base); // clock low
    SCL_DELAY; // clock low delay
    return bAck;
}

// return true if device response ack
void i2c_read(alt_u32 clk_base, alt_u32 data_base, alt_u8 *pData, bool bAck)
{
    alt_u8 Data = 0;
    int i;

    // assume SCL = low

    SDA_DIR_IN(data_base);  // set data read mode
    SCL_LOW(clk_base); // clock low
    SCL_DELAY; // clock low delay

    for (i = 0; i < 8; i++)
    {
        Data <<= 1;
        SCL_HIGH(clk_base);  // clock high
        while (SCL_READ(clk_base) == 0); // clock stretching
        SCL_DELAY;
        if (SDA_READ(data_base))  // read data
        {
            Data |= 0x01;
            //printf("1");
        }
        else
        {
        	//printf("0");
        }

        SCL_LOW(clk_base);  // clock low
        SCL_DELAY;
    }
    //printf("\n");
    // send ACK
    SCL_LOW(clk_base);  // new, make sure data change at clk low
    SDA_DIR_OUT(data_base);  // set data write mode
    if (bAck)
        SDA_LOW(data_base);
    else
        SDA_HIGH(data_base);
    SCL_HIGH(clk_base); // clock high
    while (SCL_READ(clk_base) == 0); // clock stretching
    SCL_DELAY; // clock high  delay
    SCL_LOW(clk_base); // clock low
    SCL_DELAY; // clock low delay
    SDA_LOW(data_base);  // data low
    SCL_DELAY; // data low delay
//    SDA_DIR_IN;  // set data read mode

    *pData = Data;
}
