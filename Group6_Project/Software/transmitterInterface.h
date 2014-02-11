/*
 * transmitterInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef TRANSMITTERINTERFACE_H_
#define TRANSMITTERINTERFACE_H_
#define ON 1;
#define OFF 0;
class transmitterInterface {

	int* forwardPin;
	int* backwardPin;
	int* leftPin;
	int* rightPin;

public:
	/*
	 * Constructor which takes the base address to the four pins that lead to
	 * the transmitter. One pin for each left turn, right turn, forward and backwards
	 */
	transmitterInterface(int*, int*, int*, int*);

	/*
	 * Destructor for the transmitterInterface object.
	 */
	virtual ~transmitterInterface();

	/**
	 * Send turn left signal to transmitter.
	 */
	void turnLeftOn();
	/**
	 * Send turn right signal to transmitter.
	 */
	void turnRightOn();
	/**
	 * Send go forward signal to transmitter.
	 */
	void moveForwardOn();
	/**
	 * Send reverse signal to transmitter.
	 */
	void moveBackwardOn();
	/**
	 * Send stop turning left signal to transmitter.
	 */
	void turnLeftOff();
	/**
	 * Send stop turning right signal to transmitter.
	 */
	void turnRightOff();
	/**
	 * Send stop moving forwards signal to transmitter.
	 */
	void moveForwardOff();
	/**
	 * Send stop moving backwards signal to transmitter.
	 */
	void moveBackwardOff();
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
