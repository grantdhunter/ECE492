/*
 * main.cpp
 *
 * Very early draft
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include <stdio.h>
#include <stdlib.h>
#include "TransmitterInterface.h"
#include "EmgInterface.h"
#include "StatusLED.h"
#include "system.h"

/*Definition of Task Stacks */
#define TASK_STACKSIZE        2048
OS_STK task_move_stk[TASK_STACKSIZE];
OS_STK task_turn_stk[TASK_STACKSIZE];
OS_STK task_startup_stk[TASK_STACKSIZE];

/*Definition of Task priorities*/
#define  TASK_MOVE_PRIORITY 1
#define  TASK_TURN_PRIORITY 2
#define  TASK_STARTUP_PRIORITY 3

//emg thresholds move
#define EMG_STOP_THRESHOLD 			10
#define EMG_FORWARD_THRESHOLD	150
#define EMG_BACKWARD_THRESHOLD	65

#define EMG_DELAY_MSEC_DRIVE		5
#define WINDOW_SIZE_DRIVE 	50
#define SAMPLE_ERROR_DRIVE 	5

//emg threshold turn
#define EMG_STOP_TURN_THRESHOLD 20
#define EMG_RIGHT_THRESHOLD		150
#define EMG_LEFT_THRESHOLD		65

#define EMG_DELAY_MSEC_TURN		5
#define WINDOW_SIZE_TURN 	50
#define SAMPLE_ERROR_TURN 	5

//global interface objects
TransmitterInterface transmitter((Addr) TRANSMITTER_BASE);
EmgInterface emg(DE0_NANO_ADC_0_NAME);
StatusLED led((Addr) PIO_LED_GREEN_BASE);

//Collect EMG data from channel 0
//Return the average value over WINDOW_SIZE_DRIVE
uint16_t collectSampleChannel_0() {

	uint16_t emgData = 0;
	int i = 0;

	while (i != WINDOW_SIZE_DRIVE) {
		i++;
		//Read analogue data from EMG sensor
		emgData += emg.readChannel_0();

		OSTimeDlyHMSM(0, 0, 0, EMG_DELAY_MSEC_DRIVE);
	}
	
	emgData = emgData / WINDOW_SIZE_DRIVE;
	emgData = emgData / 16;
	
	return emgData;
}

//Collect EMG data from channel 1
//Return the average value over WINDOW_SIZE_TURN
uint16_t collectSampleChannel_1() {

	uint16_t emgData = 0;
	int i = 0;

	while (i != WINDOW_SIZE_TURN) {
		i++;
		//Read analogue data from EMG sensor

		emgData += emg.readChannel_1();
		

		OSTimeDlyHMSM(0, 0, 0, EMG_DELAY_MSEC_TURN);
	}

	emgData = emgData / WINDOW_SIZE_TURN;
	emgData = emgData / 16;

	return emgData;
}

//When a forward signal has been received send move forward to the transmitter
//then poll the emg for the stop signal.
void forwardCommand() {

	uint16_t emgData = 0;

	printf("Forward\n");
	transmitter.moveForward();
	led.forward();
    
    //wait for signal to drop bellow stop threshold
	while (1) {
		emgData = collectSampleChannel_0();

		if (emgData < EMG_STOP_THRESHOLD) {

			printf("Stop\n");
			transmitter.moveOff();
			led.turnOff();
			break;
		}
	}
}

//When a reverse signal has been received send move backwards to the transmitter
//then poll the emg for the stop signal.
void backwardCommand() {

	uint16_t emgData = 0;

	printf("Reverse\n");
	transmitter.moveReverse();
	led.backward();
    //wait for signal to drop bellow stop threshold
	while (1) {
		emgData = collectSampleChannel_0();

		if (emgData < EMG_STOP_THRESHOLD) {

			printf("Stop\n");
			transmitter.moveOff();
			led.moveOff();
			break;
		}
	}
}

//When a left turn signal has been received send turn left to the transmitter
//then poll the emg for the stop signal.
void leftCommand() {

	uint16_t emgData = 0;

	printf("Left\n");
	transmitter.turnLeft();
	led.left();
    
    //wait for signal to drop bellow stop threshold
	while (1) {
		emgData = collectSampleChannel_1();

		if (emgData < EMG_STOP_TURN_THRESHOLD) {

			printf("Stop\n");
			transmitter.turnOff();
			led.turnOff();
			break;
		}
	}
}

//When a right turn signal has been received send turn right to the transmitter
//then poll the emg for the stop signal.
void rightCommand() {

	uint16_t emgData = 0;

	printf("Right\n");
	transmitter.turnRight();
	led.right();
    
    //wait for signal to drop bellow stop threshold
	while (1) {
		emgData = collectSampleChannel_1();

		if (emgData < EMG_STOP_TURN_THRESHOLD) {

			printf("Stop\n");
			transmitter.turnOff();
			led.turnOff();
			break;
		}
	}
}

/*Task that polls EMG Sensor, processes the information and relays it to the transmitter*/
void taskMove(void* pdata) {

	int16_t emgData1;
	int16_t emgData2;

	printf("Starting drive control\n");

	emgData1 = collectSampleChannel_0();
	while (1) {

        //collect data
		emgData2 = collectSampleChannel_0();

        //check if data is increasing
		if (emgData2 > emgData1 - SAMPLE_ERROR_DRIVE) {

            //check if greater than threshold
			if (emgData2 > EMG_FORWARD_THRESHOLD) {
				forwardCommand();
				emgData1 = collectSampleChannel_0();
			} else {
				emgData1 = emgData2;
			}

		} else {

			//check for forward command
			if (emgData2 > EMG_FORWARD_THRESHOLD) {
				forwardCommand();

				//check for reverse command
			} else if (emgData2 > EMG_STOP_THRESHOLD
					&& emgData2 < EMG_FORWARD_THRESHOLD) {

				backwardCommand();
			} else {
				emgData1 = emgData2;
			}
		}

		OSTimeDlyHMSM(0, 0, 0, EMG_DELAY_MSEC_DRIVE);
		//printf("emg: %d\n",emgData);

	}
}

/*Task that polls emg to get turn instructions to send to the transmitter*/
void taskTurn(void* pdata) {

	int16_t emgData1;
	int16_t emgData2;

	printf("Starting turn control\n");

	emgData1 = collectSampleChannel_1();
	while (1) {

		emgData2 = collectSampleChannel_1();


        //check if data is increaseing
		if (emgData2 > emgData1 - SAMPLE_ERROR_TURN) {

            //check if right command
			if (emgData2 > EMG_RIGHT_THRESHOLD) {
				rightCommand();
				emgData1 = collectSampleChannel_1();
			} else {
				emgData1 = emgData2;
			}

		} else {

			//check for right command
			if (emgData2 > EMG_RIGHT_THRESHOLD) {
				rightCommand();

				//check for left command
			} else if (emgData2 > EMG_STOP_TURN_THRESHOLD
					&& emgData2 < EMG_RIGHT_THRESHOLD) {

				leftCommand();
			} else {
				emgData1 = emgData2;
			}
		}

		OSTimeDlyHMSM(0, 0, 0, EMG_DELAY_MSEC_TURN);
		//printf("emg: %d\n",emgData);
	}
}

//super awesome led status!
void startupTask(void* pdata){
	//Trollllaalalalala
	led.startingUp();
}

int main(void) {


	//Start startup Task
	OSTaskCreateExt(startupTask, NULL, &task_startup_stk[TASK_STACKSIZE - 1],
			TASK_STARTUP_PRIORITY, TASK_STARTUP_PRIORITY, task_startup_stk,
			TASK_STACKSIZE, NULL, 0);

	//Start move Task
	OSTaskCreateExt(taskMove, NULL, &task_move_stk[TASK_STACKSIZE - 1],
			TASK_MOVE_PRIORITY, TASK_MOVE_PRIORITY, task_move_stk,
			TASK_STACKSIZE, NULL, 0);

	//Start turn Task
	OSTaskCreateExt(taskTurn, NULL, &task_turn_stk[TASK_STACKSIZE - 1],
			TASK_TURN_PRIORITY, TASK_TURN_PRIORITY, task_turn_stk,
			TASK_STACKSIZE, NULL, 0);

	OSStart();
	return 0;

}
//The MIT License (MIT)
//
//Copyright (c) 2014 Grant Hunter and Emil Jafarli
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
