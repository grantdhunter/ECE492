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
	uint16_t rawData0 =0;
	uint16_t rawData1 =0;
	uint16_t rawData2 =0;
	uint16_t rawData3 =0;
	uint16_t rawData4 =0;
	uint16_t rawData5 =0;
	uint16_t rawData6 =0;
	uint16_t rawData7 =0;
	uint16_t rawData8 =0;
	OSSemPend(emg_lock,0,&err);

	alt_up_de0_nano_adc_update (adc);

	rawData0 = alt_up_de0_nano_adc_read (adc, 0);
	rawData1 = alt_up_de0_nano_adc_read (adc, 1);
	rawData2 = alt_up_de0_nano_adc_read (adc, 2);
	rawData3 = alt_up_de0_nano_adc_read (adc, 3);
	rawData4 = alt_up_de0_nano_adc_read (adc, 4);
	rawData5 = alt_up_de0_nano_adc_read (adc, 5);
	rawData6 = alt_up_de0_nano_adc_read (adc, 6);
	rawData7 = alt_up_de0_nano_adc_read (adc, 7);

	printf("channel 0: %d\n",rawData0 );
	printf("channel 1: %d\n",rawData1);
	printf("channel 2: %d\n",rawData2);
	printf("channel 3: %d\n",rawData3);
	printf("channel 4: %d\n",rawData4);
	printf("channel 5: %d\n",rawData5);
	printf("channel 6: %d\n",rawData6 );
	printf("channel 7: %d\n",rawData7 );



	OSSemPost(emg_lock);
	return rawData0;
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

