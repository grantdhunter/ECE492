/*
 * transmitterInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "transmitterInterface.h"
#include "altera_avalon_pio_regs.h"


/*
 * Transmitter interface object constructor. Takes four base address
 * for GPIO pins that are connected to a transmitter.
 * TODO correct the Base address names and types
 */
transmitterInterface::transmitterInterface(int* addrForward,int* addrBack,int* addrRight,int* addrLeft) {
	// TODO Auto-generated constructor stub
	forwardPin = addrForward;
	backwardPin = addrBack;
	leftPin = addrLeft;
	rightPin = addrRight;

}
/**
 *
 */
transmitterInterface::~transmitterInterface() {
	// TODO Auto-generated destructor stub
}

/**
 *
 */
void transmitterInterface::turnLeftOn() {
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, ON);
}

/**
 *
 */
void transmitterInterface::turnRightOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, ON);
}

/**
 *
 */
void transmitterInterface::moveForwardOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, ON);
}

/**
 *
 */
void transmitterInterface::moveBackwardOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, ON);
}

/**
 *
 */
void transmitterInterface::turnLeftOff() {
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, OFF);
}

/**
 *
 */
void transmitterInterface::turnRightOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, OFF);
}

/**
 *
 */
void transmitterInterface::moveForwardOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, OFF);
}

/**
 *
 */
void transmitterInterface::moveBackwardOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, OFF);
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
