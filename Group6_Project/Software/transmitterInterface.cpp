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

}
/**
 *
 */
TransmitterInterface::~TransmitterInterface() {
	// TODO Auto-generated destructor stub
}

/**
 *
 */
void TransmitterInterface::turnLeftOn() {
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, ON);
}

/**
 *
 */
void TransmitterInterface::turnRightOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, ON);
}

/**
 *
 */
void TransmitterInterface::moveForwardOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, ON);
}

/**
 *
 */
void TransmitterInterface::moveBackwardOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, ON);
}

/**
 *
 */
void TransmitterInterface::turnLeftOff() {
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, OFF);
}

/**
 *
 */
void TransmitterInterface::turnRightOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, OFF);
}

/**
 *
 */
void TransmitterInterface::moveForwardOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, OFF);
}

/**
 *
 */
void TransmitterInterface::moveBackwardOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, OFF);
}
