/*
 * transmitterInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "TransmitterInterface.h"
#include "altera_avalon_pio_regs.h"


/*
 * Transmitter interface object constructor. Takes four base address
 * for GPIO pins that are connected to a transmitter.
 * TODO correct the Base address names and types
 */
TransmitterInterface::TransmitterInterface(int* addrForward,int* addrBack,int* addrRight,int* addrLeft) {
 // TODO Auto-generated constructor stub
 forwardPin = addrForward;
 backwardPin = addrBack;
 leftPin = addrLeft;
 rightPin = addrRight;


/*
 * Destructor for the transmitterInterface object.
 */
TransmitterInterface::~TransmitterInterface() {
 // TODO Auto-generated destructor stub
}
/*
 * Send turn right signal to transmitter. * Send turn left signal to transmitter.
 */ 
void TransmitterInterface::turnLeftOn() {
  IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, ON);
}

/**
 * Send go forward signal to transmitter.
 */
void TransmitterInterface::turnRightOn() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, ON);
}

/**
 * Send reverse signal to transmitter.
 */
void TransmitterInterface::moveForwardOn() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, ON);
}

/**
 * Send stop turning left signal to transmitter.
 */
void TransmitterInterface::moveBackwardOn() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, ON);
}

/**
 * Send stop turning right signal to transmitter.
 */
void TransmitterInterface::turnLeftOff() {
  IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, OFF);
}




void TransmitterInterface::turnRightOff() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, OFF);
}

/**
 * Send stop moving forwards signal to transmitter.
 */
void TransmitterInterface::moveForwardOff() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, OFF);
}

/**
 * Send stop moving backwards signal to transmitter.
 */
void TransmitterInterface::moveBackwardOff() {
 IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, OFF);
}

