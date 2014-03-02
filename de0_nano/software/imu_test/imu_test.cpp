/*
 * imu_test.cpp
 *
 *  Created on: 2014-02-25
 *      Author: gdhunter
 */




//Lots of help was taken from https://github.com/grantdhunter/i2cdevlib/blob/master/Arduino/MPU6050/Examples/MPU6050_DMP6/MPU6050_DMP6.ino

#include <stdio.h>
#include "includes.h"
#include "system.h"

#include "MPU6050_6Axis_MotionApps20.h"
#include "I2Cdev.h"

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK task1_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      1

MPU6050 imu(IMU_BASE_ADDRESS);

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata) {
    
    uint8_t packetSize = 0;
    unit16_t fifocount = 0;
    unit8_t imuIntStatus;
    unint8_t data[64];
    Quaternion quat;
    VectorFloat gravity;
    float ypr[3];
    
    imu.initialize();
    //True if every thing is good
    if (imu.testConnection()) {
        
        //TODO set offsets to zero the IMU
        imu.setXGyroOffset(X_OFFSET);
        imu.setYGyroOffset(Y_OFFSET);
        imu.setZGyroOffset(Z_OFFSET);
        imu.setZAccelOffset(Z_OFFSET_A);
    } else {
        //Error
        //TODO handle error
    }
    
    //Zero id everything is good
    if (imu.dmpInitialize() == 0) {
        imu.setDMPEnabled(true);
        
        imuIntStatus = imu.getIntStatus();
        
        packetSize = imu.dmpGetFIFOPacketSize() 
    } else {
        //Error
        //TODO handle
    }
    
    
    while (1) {
        fifocount = mpu.getFIFOCount();
        
        if( imuIntStatus & 0x10 || fifocount == 1024){
            //overflow
            //TODO handle error
        } else if(imuIntStatus & 0x02) {
            while(fifocount < packetSize) {
                fifocount = mpu.getFIFOCount();
            }
            
             imu.getFIFOByte(data, packetSize);
             fifocount -= packetSize;
            
            imu.dmpGetQuaternion(&quat, data);
            imu.dmpGetGravity(&gravity, &quat);
            imu.dmp.GetYawPitchRoll(ypr, &quat, &gravity);
        }
       
        
        printf("IMU: %d\n", data);
        OSTimeDlyHMSM(0, 0, 3, 0);
    }
}

/* The main function creates two task and starts multi-tasking */
int main(void) {
    
    OSTaskCreateExt(task1, NULL, &task1_stk[TASK_STACKSIZE - 1], TASK1_PRIORITY,
                    TASK1_PRIORITY, task1_stk, TASK_STACKSIZE, NULL, 0);
    
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
