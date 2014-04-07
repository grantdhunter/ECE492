#include <stdio.h>
#include "includes.h"
#include "altera_up_avalon_de0_nano_adc.h"



int main(void){
	alt_up_de0_nano_adc_dev * adc;
	unsigned int data;
	int channel, count;

	/* Initialize all the variables */
	data = 0;
	channel = 0;
	count = 0;

	/* Add address specified by system.h */
	adc = alt_up_de0_nano_adc_open_dev("/dev/ADC");

	while (adc != NULL)
	{
		count++;
		alt_up_de0_nano_adc_update(adc);

		/* Obtain the data and mask the first 12 bits */
		data = alt_up_de0_nano_adc_read(adc,channel) & 0xFFF;

		data = data / 16;

		if(count == 1)
			printf("Channel %d has value %d \n", channel, data);

		if(count == 5000){
			count = 0;
			channel++;
		} else if (channel > 8) {
			channel = 0;
			count = 0;
		}
	}

	return 0;

}
