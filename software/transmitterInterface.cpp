/*
 * transmitterInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "transmitterInterface.h"
#include "altera_avalon_pio_regs.h"


/*
 * Transmitter interface object constructor. Takes four base address
 * for GPIO pins that are connected to a transmitter.
 * TODO correct the Base address names and types
 */
transmitterInterface::transmitterInterface(int* addrForward,int* addrBack,int* addrRight,int* addrLeft) {
	// TODO Auto-generated constructor stub
	forwardPin = addrForward;
	backwardPin = addrBack;
	leftPin = addrLeft;
	rightPin = addrRight;

}
/**
 *
 */
transmitterInterface::~transmitterInterface() {
	// TODO Auto-generated destructor stub
}

/**
 *
 */
void transmitterInterface::turnLeftOn() {
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, ON);
}

/**
 *
 */
void transmitterInterface::turnRightOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, ON);
}

/**
 *
 */
void transmitterInterface::moveForwardOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, ON);
}

/**
 *
 */
void transmitterInterface::moveBackwardOn() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, ON);
}

/**
 *
 */
void transmitterInterface::turnLeftOff() {
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(leftPin, OFF);
}

/**
 *
 */
void transmitterInterface::turnRightOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(rightPin, OFF);
}

/**
 *
 */
void transmitterInterface::moveForwardOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(forwardPin, OFF);
}

/**
 *
 */
void transmitterInterface::moveBackwardOff() {
	IOWR_ALTERA_AVALON_PIO_DIRECTION(backwardPin, OFF);
}
