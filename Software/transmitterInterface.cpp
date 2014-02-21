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
TransmitterInterface::TransmitterInterface(int* baseAddr) {
 // TODO Auto-generated constructor stub
 forwardPin = baseAddr;
 backwardPin = baseAddr+1;
 leftPin = baseAddr+2;
 rightPin = baseAddr+3;
}

/*
 * Transmitter interface object constructor. Takes four base address
 * for GPIO pins that are connected to a transmitter.
 * TODO correct the Base address names and types
 */
TransmitterInterface::TransmitterInterface(int* addrForward,int* addrBack,int* addrRight,int* addrLeft) {
 // TODO Auto-generated constructor stub
 forwardPin = addrForward;
 backwardPin = addrBack;
 leftPin = addrLeft;
 rightPin = addrRight;
}

/*
 * Destructor for the transmitterInterface object.
 */
TransmitterInterface::~TransmitterInterface() {
 // TODO Auto-generated destructor stub
}

/*
 * Send turn left signal to transmitter.
 */ 
void TransmitterInterface::turnLeftOn() {
  IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, ON);
}

/**
 *  Send turn right signal to transmitter.
 */
void TransmitterInterface::turnRightOn() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, ON);
}

/**
 * Send forward signal to transmitter.
 */
void TransmitterInterface::moveForwardOn() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, ON);
}

/**
 * Send reverse signal to transmitter.
 */
void TransmitterInterface::moveBackwardOn() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, ON);
}

/**
 * Send stop turning left signal to transmitter.
 */
void TransmitterInterface::turnLeftOff() {
  IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, OFF);
}

/**
 * Send stop turning right signal to transmitter.
 */
void TransmitterInterface::turnRightOff() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, OFF);
}

/**
 * Send stop moving forwards signal to transmitter.
 */
void TransmitterInterface::moveForwardOff() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, OFF);
}

/**
 * Send stop moving backwards signal to transmitter.
 */
void TransmitterInterface::moveBackwardOff() {
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
