/*
 * emgInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "EmgInterface.h"
#include "dataType.h"
#include "system.h"

extern "C"{
	#include "altera_up_avalon_de0_nano_adc.h"
}


/*
 * EMG sensor software interface constructor. Takes the base address of the
 * pin that the EMG sensor is connected to.
 */
EmgInterface::EmgInterface(char* emgName, int16_t chnl) {

	adc = alt_up_de0_nano_adc_open_dev(emgName);
	channel = chnl;
}

/*
 * Destructor for the emgIterface object
 */
EmgInterface::~EmgInterface() {

}

/*
 * Read data from the EMG sensor.
 */
uint16_t EmgInterface::rawRead() {
	uint16_t rawData;

	alt_up_de0_nano_adc_update (adc);
	rawData = alt_up_de0_nano_adc_read (adc, channel);

	return rawData;
}

/*
 * Determing if data from the EMG sensor is greater than a set threshold.
 * Takes the threshold value and the raw EMG data.
 */
bool EmgInterface::isOverThreshold(uint16_t threshold, uint16_t rawData) {
	if (threshold < rawData) {
		return true;
	} else {
		return false;
	}
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

