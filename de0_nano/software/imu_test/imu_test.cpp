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

#include "MPU6050.h"
#include "dataType.h"

#define X_OFFSET 0
#define Y_OFFSET 0
#define Z_OFFSET 0

#define Z_OFFSET_A 0

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK task1_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      1

MPU6050 imu;

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata) {

	int16_t gx = 0;
	int16_t gy = 0;
	int16_t gz = 0;

	int16_t ax = 0;
	int16_t ay = 0;
	int16_t az = 0;

	imu.initialize();
	//True if every thing is good
	if (imu.testConnection()) {

	} else {
		//Error
		//TODO handle error
		printf("ERROR: No Connection\n");

	}

	while (1) {

		imu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);


//		roll = imu.getRotationX();
//		pitch = imu.getRotationY();
//		yaw = imu.getRotationZ();
//
		printf("gx: %x\n", gx & 0xFF);
//		printf("gy: %x\n", gy & 0xFF);
//		printf("gz: %x\n\n", gz & 0xFF);
////
//		accx = imu.getAccelerationX();
//		accy = imu.getAccelerationY();
//		accz = imu.getAccelerationZ();
//
//		printf("ax: %d\n", ax & 0xFF);
//		printf("ay: %d\n", ay & 0xFF);
//		printf("az: %d\n\n", az & 0xFF);
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
