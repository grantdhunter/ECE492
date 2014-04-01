/*
 * emgInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "EmgInterface.h"
#include "dataType.h"
#include "system.h"
#include "ucos_ii.h"
#include <stdio.h>
extern "C"{
	#include "altera_up_avalon_de0_nano_adc.h"
}


/*
 * EMG sensor software interface constructor. Takes the base address of the
 * pin that the EMG sensor is connected to.
 */
EmgInterface::EmgInterface(char* emgName ) {

	emg_lock =  OSSemCreate(1);

	OSSemPend(emg_lock,0,&err);

	adc = alt_up_de0_nano_adc_open_dev(emgName);
	//alt_up_de0_nano_adc_auto_enable(adc);
	OSSemPost(emg_lock);
}

/*
 * Destructor for the emgIterface object
 */
EmgInterface::~EmgInterface() {

}

/*
 * Read data from the EMG sensor.
 */
uint16_t EmgInterface::readChannel_0() {
	uint16_t rawData;

	OSSemPend(emg_lock,0,&err);

	alt_up_de0_nano_adc_update (adc);
	rawData = alt_up_de0_nano_adc_read (adc, 0);

	OSSemPost(emg_lock);

	return rawData;
}
/*
 * Read data from the EMG sensor.
 */
uint16_t EmgInterface::readChannel_1() {

	uint16_t rawData =0;

	OSSemPend(emg_lock,0,&err);


	//*((int*)DE0_NANO_ADC_0_BASE) = 0;
	//rawData1 = *((int*)DE0_NANO_ADC_0_BASE+1);
	alt_up_de0_nano_adc_update (adc);
	rawData = alt_up_de0_nano_adc_read (adc, 1);
	rawData = rawData & 0xFFF;
	OSSemPost(emg_lock);
	return rawData;
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

