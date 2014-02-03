/*
 * emgInterface.h
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#ifndef EMGINTERFACE_H_
#define EMGINTERFACE_H_

class emgInterface {
	int* BaseAddress;
public:
	/*
	 * EMG sensor software interface constructor. Takes the base address of the
	 * pin that the EMG sensor is connected to.
	 */
	emgInterface(int*);

	/*
	 * Destructor for the emgIterface object
	 */
	virtual ~emgInterface();

	/*
	 * Read data from the EMG sensor.
	 */
	long emgInterface::rawRead();

	/*
	 * Determing if data from the EMG sensor is greater than a set threshold.
	 * Takes the threshold value and the raw EMG data.
	 */
	bool emgInterface::isOverThreshold(long, long);
};

#endif /* EMGINTERFACE_H_ */
