// --------------------------------------------------------------------
// Copyright (c) 2008 by Terasic Technologies Inc.
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

#ifndef I2C_H_
#define I2C_H_

#include "terasic_includes.h"

#define CLK_DELAY_TIME		10 // microseconds

bool I2C_WriteToDevice(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr, alt_u8 *pData, alt_u16 len);
bool I2C_WriteToDeviceRegister(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr,
							   alt_u8 controlAddr, alt_u8 *pData, alt_u16 len);
bool I2C_WriteMore(alt_u32 clk_base, alt_u32 data_base, alt_u8 *pData, alt_u16 len);
bool I2C_ReadFromDevice(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr, alt_u8 *pBuf, alt_u16 len, bool endRead);
bool I2C_ReadFromDeviceRegister(alt_u32 clk_base, alt_u32 data_base, alt_8 deviceAddr,
								alt_u8 controlAddr, alt_u8 *pBuf, alt_u16 len, bool endRead);
void I2C_ReadMore(alt_u32 clk_base, alt_u32 data_base, alt_u8 *pBuf, alt_u16 len, bool endRead);
void I2C_Start(alt_u32 clk_base, alt_u32 data_base);
void I2C_Stop(alt_u32 clk_base, alt_u32 data_base);

#endif /*I2C_H_*/
