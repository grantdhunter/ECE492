/*
 * StatusLED.cpp
 *
 *  Created on: 2014-04-03
 *      Author: gdhunter
 */

#include "StatusLED.h"
#include "altera_avalon_pio_regs.h"

StatusLED::StatusLED(Addr baseAddr) {
	// TODO Auto-generated constructor stub
	baseAddress = baseAddr;
	led_lock = OSSemCreate(1);
}

StatusLED::~StatusLED() {
	// TODO Auto-generated destructor stub
}

void StatusLED::startingUp() {
	OSSemPend(led_lock, 0, &err);


	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, START_UP_1);
	OSTimeDlyHMSM(0, 0, 0, STARTUP_DELAY_MSEC);

	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, START_UP_2);
	OSTimeDlyHMSM(0, 0, 0, STARTUP_DELAY_MSEC);

	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, START_UP_3);
	OSTimeDlyHMSM(0, 0, 0, STARTUP_DELAY_MSEC);

	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, START_UP_4);
	OSTimeDlyHMSM(0, 0, 0, STARTUP_DELAY_MSEC);

	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, START_UP_CLEAR);
	OSTimeDlyHMSM(0, 0, 0, STARTUP_DELAY_MSEC);

	OSSemPost(led_lock);
}

void StatusLED::forward() {
	OSSemPend(led_lock, 0, &err);
	int8_t newReg = 0;
	newReg = validateMoveStatus(LED_FORWARD);

	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
	OSSemPost(led_lock);
}

void StatusLED::backward() {
	OSSemPend(led_lock, 0, &err);
	int8_t newReg = 0;
	newReg = validateMoveStatus(LED_BACKWARD);

	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
	OSSemPost(led_lock);
}

void StatusLED::left() {
	OSSemPend(led_lock, 0, &err);
	int8_t newReg = 0;
	newReg = validateTurnStatus(LED_LEFT);

	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
	OSSemPost(led_lock);
}

void StatusLED::right() {
	OSSemPend(led_lock, 0, &err);
	int8_t newReg = 0;
	newReg = validateTurnStatus(LED_RIGHT);

	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
	OSSemPost(led_lock);
}

void StatusLED::turnOff() {
	OSSemPend(led_lock, 0, &err);
	int8_t newReg = 0;
	newReg = validateTurnStatus(CLEAR_TURN_STATUS);

	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
	OSSemPost(led_lock);
}


void StatusLED::moveOff() {
	OSSemPend(led_lock, 0, &err);
	int8_t newReg = 0;
	newReg = validateMoveStatus(CLEAR_MOVE_STATUS);

	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
	OSSemPost(led_lock);
}

int8_t StatusLED::validateTurnStatus(int8_t status) {

	int8_t oldReg = 0;
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);

	//Clear previous turn commands.
	int8_t newReg = oldReg & CLEAR_TURN_STATUS;

	//Set the new turn command.
	newReg = newReg | status;

	return newReg;
}

int8_t StatusLED::validateMoveStatus(int8_t status) {
	int8_t oldReg = 0;
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);

	//Clear previous movement commands.
	int8_t newReg = oldReg & CLEAR_MOVE_STATUS;

	//Set the new movement command.
	newReg = newReg | status;

	return newReg;
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
