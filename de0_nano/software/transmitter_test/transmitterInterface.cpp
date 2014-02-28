/*
 * transmitterInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "transmitterInterface"


#include "altera_avalon_pio_regs.h"

typedef unsigned char Byte;
/********Public Functions*************/

/*
 * Transmitter interface object constructor. Takes four base address
 * for GPIO pins that are connected to a transmitter.
 * TODO correct the Base address names and types
 */
TransmitterInterface::TransmitterInterface(Addr baseAddr) {
	
	baseAddress = baseAddr;
}

/*
 * Destructor for the transmitterInterface object.
 */
TransmitterInterface::~TransmitterInterface() {
	// TODO Auto-generated destructor stub
}

/*
 * Send turn left signal to transmitter.
 */
void TransmitterInterface::turnLeft() {
	Byte oldReg = 0;
	Byte newReg = 0;
	
	//Read current status of the register
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);
	
	//Create new valid turn command with out changing the other movement
	newReg = validateTurn(oldReg,LEFT_CMD);
	
	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
}

/**
 *  Send turn right signal to transmitter.
 */
void TransmitterInterface::turnRight() {
	Byte oldReg = 0;
	Byte newReg = 0;
	
	//Read current status of the register
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);
	
	//Create new valid turn command with out changing the other movement
	newReg = validateTurn(oldReg,RIGHT_CMD);
	
	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
}

/**
 * Send forward signal to transmitter.
 */
void TransmitterInterface::moveForward() {
	Byte oldReg = 0;
	Byte newReg = 0;
	
	//Read current status of the register
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);
	
	//Create new valid movement command with out changing the turning property
	newReg = validateMove(oldReg,FORWARD_CMD);
	
	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
}

/**
 * Send reverse signal to transmitter.
 */
void TransmitterInterface::moveReverse() {
	Byte oldReg = 0;
	Byte newReg = 0;
	
	//Read current status of the register
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);
	
	//Create new valid movement command with out changing the turning property
	newReg = validateMove(oldReg,REVERSE_CMD);
	
	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
}

/**
 * Send stop turning signal to transmitter.
 */
void TransmitterInterface::turnOff() {
	Byte oldReg = 0;
	Byte newReg = 0;
	
	//Read current status of the register
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);
	
	//Create new valid turn command with out changing the other movement
	newReg = validateTurn(oldReg,OFF_CMD);
	
	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
}


/**
 * Send stop moving forwards signal to transmitter.
 */
void TransmitterInterface::moveOff() {
	Byte oldReg = 0;
	Byte newReg = 0;
	
	//Read current status of the register
	oldReg = IORD_ALTERA_AVALON_PIO_DATA(baseAddress);
	
	//Create new valid movement command with out changing the turning property
	newReg = validateMove(oldReg,OFF_CMD);
	
	//Write the new command to the register
	IOWR_ALTERA_AVALON_PIO_DATA(baseAddress, newReg);
}



/********Private Functions*************/

/*
 *Check the register to see what the previous command is and compare to the 
 *new command to ensure no illogical commands get sent to the transmitter.
 *i.e turn left and right
 */
Byte validateTurn( Byte currentReg, Byte command) {
	
	//Clear previous turn commands.
	Byte newReg = currentReg & CLEAR_TURN;
	
	//Set the new turn command.
	newReg = newReg | command;
	
	return newReg;
}
/*
 *Check the register to see what the previous command is and compare to the 
 *new command to ensure no illogical commands get sent to the transmitter.
 *i.e move forward and reverse
 */
Byte validateMove( Byte currentReg, Byte command) {
	
	//Clear previous movement commands.
	Byte newReg = currentReg & CLEAR_MOVE;
	
	//Set the new movement command.
	newReg = newReg | command;
	
	return newReg;
}

//The MIT License (MIT)
//
//Copyright (c) 2014 Grant Hunter
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.
