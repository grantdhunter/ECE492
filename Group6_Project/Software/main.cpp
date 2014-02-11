#include <stdio.h>
#include "includes.h"

/*Definition of Task Stacks */
#define TASK_STACKSIZE        2048
OS_STK  task_emg_stk[TASK_STACKSIZE];
OS_STK  tast_gyro_stk[TASK_STACKSIZE];

/*Definition of Task priorities*/
#define  TASK_EMG_PRIORITY 1
#define  TASK_GYRO_PRIORITY 2



EmgInterface emg;
TransmitterInterface transmitter;


void init()
{
  //Intialize the emg and transmitter for use.
  //TODO get correct address variable names.
  emg = new EmgInterface(EMG_BASE_ADDRESS);
  transmitter = new TranmitterInterface(TRANSMITTER_BASE_ADRRESS);

  //Initialize the Gyorscope, MPU6050
  MPU6050 gyro();
  gyro.initialize();

  if(!gyro.testConnection())
    {
      //TODO add error
    }
}


/*Task that polls EMG Sensor, processes the information and relays it to the transmitter*/
void taskEmg(void* pdata)
{
  long emgData;

  //Read analogue data from EMG sensor

  //Convert data to usable information

  //Compare EMG to threshold value. Either raw signal or frequency.

  //Send the appropriate signal determined by the threshold.
  //Signal could be Forward or Reverse.
  //Otherwise do nothing

}


/*Task that polls Gyro Sensor, processes the information and relays it to the transmitter*/
void taskGyro(void* pdata)
{
   //Read digital data from the IMU. Data has already been processed

   //Compare gyroscope values to thresholds

  //Send the appropriate signal determined by the threshold.
  //Signal could be left or right.
  //Otherwise do nothing


}


int main(void)
{

//Start EMG Task
    OSTaskCreateExt(taskEmg,
		NULL,
		(void *)&task_emg_stk[TASK_STACKSIZE-1],
		TASK_EMG_PRIORITY,
		TASK_EMG_PRIORITY,
		task_emg_stk,
		TASK_STACKSIZE,
		NULL,
		0);

//Start Gyro Task   
   OSTaskCreateExt(taskGyro,
		NULL,
		(void *)&task_gryo_stk[TASK_STACKSIZE-1],
		TASK_GYRO_PRIORITY,
		TASK_GRYO_PRIORITY,
		task_gryo_stk,
		TASK_STACKSIZE,
		NULL,
		0);


	OSStart();
	return 0;

}
