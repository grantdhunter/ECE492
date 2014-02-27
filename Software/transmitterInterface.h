/*
 * TransmitterInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef TRANSMITTERINTERFACE_H_
#define TRANSMITTERINTERFACE_H_


#define FORWARD_CMD 0x1000;
#define REVERSE_CMD 0x0100;
#define LEFT_CMD 	0x0010;
#define RIGHT_CMD	0x0001;
#define OFF_CMD 	0x0000;
#define CLEAR_TURN  0x1100;
#define CLEAR_MOVE  0x0011;

typedef void* Addr;
typedef unsigned char Byte;
class TransmitterInterface {

	Addr baseAddress;

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
	/*
	 *Check the register to see what the previous command is and compare to the 
	 *new command to ensure no illogical commands get sent to the transmitter.
	 *i.e turn left and right
	 */
	Byte validateTurn(Byte, Byte);
	/*
	 *Check the register to see what the previous command is and compare to the 
	 *new command to ensure no illogical commands get sent to the transmitter.
	 *i.e move forward and reverse
	 */
	Byte validateMove( Byte, Byte);

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
