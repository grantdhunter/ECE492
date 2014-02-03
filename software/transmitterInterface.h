/*
 * transmitterInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef TRANSMITTERINTERFACE_H_
#define TRANSMITTERINTERFACE_H_
#define ON 1;
#define OFF 0;
class transmitterInterface {

	int* forwardPin;
	int* backwardPin;
	int* leftPin;
	int* rightPin;

public:
	/*
	 * Constructor which takes the base address to the four pins that lead to
	 * the transmitter. One pin for each left turn, right turn, forward and backwards
	 */
	transmitterInterface(int*, int*, int*, int*);

	/*
	 * Destructor for the transmitterInterface object.
	 */
	virtual ~transmitterInterface();

	/**
	 * Send turn left signal to transmitter.
	 */
	void turnLeftOn();
	/**
	 * Send turn right signal to transmitter.
	 */
	void turnRightOn();
	/**
	 * Send go forward signal to transmitter.
	 */
	void moveForwardOn();
	/**
	 * Send reverse signal to transmitter.
	 */
	void moveBackwardOn();
	/**
	 * Send stop turning left signal to transmitter.
	 */
	void turnLeftOff();
	/**
	 * Send stop turning right signal to transmitter.
	 */
	void turnRightOff();
	/**
	 * Send stop moving forwards signal to transmitter.
	 */
	void moveForwardOff();
	/**
	 * Send stop moving backwards signal to transmitter.
	 */
	void moveBackwardOff();
};

#endif /* TRANSMITTERINTERFACE_H_ */
