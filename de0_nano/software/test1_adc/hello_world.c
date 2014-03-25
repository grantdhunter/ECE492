#include <stdlib.h>
#include <stdio.h>


#define ADC_ADDR 0x04011000
#define LED_ADDR 0x04011020
int main (void){
volatile int * adc = (int*)(ADC_ADDR);
volatile int * led = (int*)(LED_ADDR);
unsigned int data;
int count;
//int biggest_value_obtained=0;
int channel;
int forward_motion = 0;
data = 0;
count = 0;
channel = 0;
while (1){
*(adc) = 0; //Start the ADC read
count += 1;
data = *(adc+channel); //Get the value of the selected channel
data = data/16; //Ignore the lowest 4 bits
*(led) = data; //Display the value on the LEDs
if ( data > 170)
    forward_motion=1;

if (count == 50000){
printf("50000 samples passed\n");
count=0;
if (forward_motion == 1) {
    count=0;
    printf("Forward motion detecded \n");
    forward_motion = 0;}
}
}

return 0;

}
