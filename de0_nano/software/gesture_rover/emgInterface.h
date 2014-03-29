/*
 * EmgInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef EMGINTERFACE_H_
#define EMGINTERFACE_H_

#include "dataType.h"
#include "system.h"
#include "ucos_ii.h"

extern "C" {
	#include "altera_up_avalon_de0_nano_adc.h"
}


//#define CHANNEL_0 0
//#define CHANNEL_1 1

class EmgInterface {

public:
	/*
	 * EMG sensor software interface constructor. Takes the base address of the
	 * pin that the EMG sensor is connected to.
	 */
	EmgInterface(char*);

	/*
	 * Destructor for the emgIterface object
	 */
	virtual ~EmgInterface();

	/*
	 * Read data from the EMG sensor.
	 */
	uint16_t readChannel_0();
	uint16_t readChannel_1();


private:
	INT8U err;
	alt_up_de0_nano_adc_dev * adc;
	OS_EVENT* emg_lock;
};

#endif /* EMGINTERFACE_H_ */
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
