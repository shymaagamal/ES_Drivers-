/*
 * 12C_interface.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_


#include "../../LIB/BIT_Math.h"
#include"../../LIB/std_types.h"

typedef enum
{
	NO_ERROR=1,
	START_ERROR,
	REPEATED_STSRT_ERROR,
	SLAVE_ADDRESS_WRITE_ERROR,
	SLAVE_ADDRESS_READ_ERROR,
	SEND_BYTE_ERROR,
	READ_BYTE_ERROR

}I2C_ERROR_STATUS;


void I2C_masterPreScaler();
void I2C_masterInit();
I2C_ERROR_STATUS I2C_masterSendStartCondation(void);
I2C_ERROR_STATUS  I2C_masterSendRepeatedStart(void);
I2C_ERROR_STATUS I2C_masterSendSlaveAddressWrite(uint8 address);
I2C_ERROR_STATUS I2C_masterSendSlaveAddressRead(uint8 address);
I2C_ERROR_STATUS I2C_masterSendByte(uint8 data);
void I2C_masterStopCondation(void);
I2C_ERROR_STATUS I2C_masteReadByte(uint8 *I2C_DATA);
#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
