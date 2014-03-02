/*
 * main.cpp
 *
 * Very early draft
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */


#include <stdio.h>
#include "TransmitterInterface.h"
#include "EmgInterface.h"
#include "i2cdevlib.h"

/*Definition of Task Stacks */
#define TASK_STACKSIZE        2048
OS_STK  task_emg_stk[TASK_STACKSIZE];
OS_STK  tast_gyro_stk[TASK_STACKSIZE];

/*Definition of Task priorities*/
#define  TASK_EMG_PRIORITY 1
#define  TASK_GYRO_PRIORITY 2


//emg thresholds
#define EMG_THRESHOLD_TOP 
#define EMG_THRESHOLD_BOTTOM

EmgInterface emg(EMG_BASE_ADDRESS);

TransmitterInterface transmitter(TRANSMITTER_BASE_ADDRESS);

MPU6050 imu(IMU_BASE_ADDRESS);

/*Task that polls EMG Sensor, processes the information and relays it to the transmitter*/
void taskEmg(void* pdata)
{
    
    
    long emgData;
    while(1){  
         
        //Read analogue data from EMG sensor
        emgData = emg.readData();

        //Convert data to usable information
       	//SmoothEMGData(&emgData);

        //Compare EMG to threshold value. Either raw signal or frequency.
        //Send the appropriate signal determined by the threshold.
        //Signal could be Forward or Reverse.
        //Otherwise do nothing

        if (emgData > EMG_THRESHOLD_TOP )
        {
            transmitter.moveForward();
        } else if ( emgData < EMG_THRESHOLD_BOTTOM)
        {
            transmitter.moveReverse();
        } else {
            transmitter.moveOff();
        }

    }
}


/*Task that polls Gyro Sensor, processes the information and relays it to the transmitter*/
void taskGyro(void* pdata)
{
   
    long gyroAngle;

    imu.initialize();

    //True if every thing is good
    if (imu.testConnection()) {

        //TODO set offsets to zero the IMU
        imu.setXGyroOffset();
        imu.setYGyroOffset();
        imu.setZGyroOffset();
        imu.setZAccelOffset();
    }else {
        //Error
        //TODO handle error
    }

    //Zero id everything is good
    if(imu.dmpInitialize() == 0) {
        imu.setDMPEnabled(true);

    } else {
        //Error
        //TODO handle
    }

    while(1) {
        //Read digital data from the IMU. Data has already been processed
        
            //TODO read data
        
        //Compare gyroscope values to thresholds
        //Send the appropriate signal determined by the threshold.
        //Signal could be left or right.
        //Otherwise do nothing
       
	if (gyroAngle > LEFT_ANGLE_THRESHOLD )
        {
            transmitter.turnLeft();
        } else if ( emgData < RIGHT_ANGLE_THRESHOLD)
        {
            transmitter.turnRight();
        } else {
            transmitter.turnOff();
        }

    }
}


int main(void)
{

    //Start EMG Task
    OSTaskCreateExt(taskEmg,
                    NULL,
                    (void *)&task_emg_stk[TASK_STACKSIZE-1],
                    TASK_EMG_PRIORITY,
                    TASK_EMG_PRIORITY,
                    task_emg_stk,
                    TASK_STACKSIZE,
                    NULL,
                    0);

    //Start Gyro Task   
    OSTaskCreateExt(taskGyro,
                    NULL,
                    (void *)&task_gryo_stk[TASK_STACKSIZE-1],
                    TASK_GYRO_PRIORITY,
                    TASK_GRYO_PRIORITY,
                    task_gryo_stk,
                    TASK_STACKSIZE,
                    NULL,
                    0);


    OSStart();
    return 0;

}
//The MIT License (MIT)
//
//Copyright (c) 2014 Grant Hunter
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.
