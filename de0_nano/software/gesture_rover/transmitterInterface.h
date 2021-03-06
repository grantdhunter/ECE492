/*
 * TransmitterInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef TRANSMITTERINTERFACE_H_
#define TRANSMITTERINTERFACE_H_
#include "ucos_ii.h"
#include "dataType.h"
#include <ctype.h>





const int8_t FORWARD_CMD = 0x8;
const int8_t REVERSE_CMD = 0x4;
const int8_t LEFT_CMD =	 0x2;
const int8_t RIGHT_CMD =	 0x1;
const int8_t OFF_CMD =	 0x0;
const int8_t CLEAR_TURN =  0xC;
const int8_t CLEAR_MOVE =  0x3;


class TransmitterInterface {


	
public:
	
	/*
	 * Constructor for if the addresses are adjacent to each other
	 */
	TransmitterInterface(Addr);

	/*
	 * Destructor for the transmitterInterface object.
	 */
	virtual ~TransmitterInterface();

	/**
	 * Send turn left signal to transmitter.
	 */
	void turnLeft();
	/**
	 * Send turn right signal to transmitter.
	 */
	void turnRight();
	/**
	 * Send go forward signal to transmitter.
	 */
	void moveForward();
	/**
	 * Send reverse signal to transmitter.
	 */
	void moveReverse();
	/**
	 * Send stop turning signal to transmitter.
	 */
	void turnOff();
	/*
	 * Send stop moving  signal to transmitter.
	 */
	void moveOff();
	
private:
	
	volatile Addr baseAddress;
	OS_EVENT* transmitter_lock;
	INT8U err;
	/*
	 *Check the register to see what the previous command is and compare to the 
	 *new command to ensure no illogical commands get sent to the transmitter.
	 *i.e turn left and right
	 */
	int8_t validateTurn(int8_t, int8_t);
	/*
	 *Check the register to see what the previous command is and compare to the 
	 *new command to ensure no illogical commands get sent to the transmitter.
	 *i.e move forward and reverse
	 */
	int8_t validateMove( int8_t, int8_t);

};

#endif /* TRANSMITTERINTERFACE_H_ */


// The MIT License (MIT)
// 
// Copyright (c) 2014 Grant Hunter
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
