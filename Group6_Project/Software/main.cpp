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

  emgData = emg.

}


/*Task that polls Gyro Sensor, processes the information and relays it to the transmitter*/
void taskGyro(void* pdata)
{


}


int main(void)
{


}
