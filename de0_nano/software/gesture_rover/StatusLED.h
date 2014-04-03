/*
 * StatusLED.h
 *
 *  Created on: 2014-04-03
 *      Author: gdhunter
 */

#ifndef STATUSLED_H_
#define STATUSLED_H_
#include "ucos_ii.h"
#include "dataType.h"
#include <ctype.h>

#define STARTUP_DELAY_MSEC 500

#define START_UP_1 127
#define START_UP_2 62
#define START_UP_3 28
#define START_UP_4 8
#define START_UP_CLEAR 0


#define LED_FORWARD	8
#define LED_BACKWARD 20
#define LED_LEFT	3
#define LED_RIGHT	96

#define CLEAR_TURN_STATUS 28
#define CLEAR_MOVE_STATUS 99

class StatusLED {
public:
	StatusLED(Addr);
	virtual ~StatusLED();

	void startingUp();
	void forward();
	void backward();
	void left();
	void right();
	void turnOff();
	void moveOff();
private:
	volatile Addr baseAddress;
	OS_EVENT* led_lock;
	INT8U err;

	int8_t validateTurnStatus(int8_t);
	int8_t validateMoveStatus(int8_t);
};

#endif /* STATUSLED_H_ */



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
