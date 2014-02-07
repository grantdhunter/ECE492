/*
 * EmgInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef EMGINTERFACE_H_
#define EMGINTERFACE_H_

class EmgInterface {
	int* BaseAddress;
public:
	/*
	 * EMG sensor software interface constructor. Takes the base address of the
	 * pin that the EMG sensor is connected to.
	 */
	EmgInterface(int*);

	/*
	 * Destructor for the emgIterface object
	 */
	virtual ~EmgInterface();

	/*
	 * Read data from the EMG sensor.
	 */
	long EmgInterface::rawRead();

	/*
	 * Determing if data from the EMG sensor is greater than a set threshold.
	 * Takes the threshold value and the raw EMG data.
	 */
	bool EmgInterface::isOverThreshold(long, long);
};

#endif /* EMGINTERFACE_H_ */
