/*
 * EEPROM_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_EEPROM_EEPROM_PROGRAM_C_
#define MCAL_EEPROM_EEPROM_PROGRAM_C_

#include "EEPROM.h"
#include "../../MCAL/I2C/I2C_interface.h"
void EEPROM_init(void)
{
	I2C_masterInit();

}

void EEPROM_write(uint16 address, uint8 data)
{
	I2C_ERROR_STATUS I2C_Starterror=I2C_masterSendStartCondation();
	uint8 addr_l=(address>>8) & 0x03;
	I2C_masterSendSlaveAddressWrite(addr_l|0x50);

	I2C_ERROR_STATUS I2C_AdressError=I2C_masterSendByte((uint8 )address);
	I2C_ERROR_STATUS I2C_DataError	=I2C_masterSendByte((uint8 )data);
	I2C_masterStopCondation();

}

void EEPROM_read(uint16 address,uint8 *data)
{
	I2C_ERROR_STATUS I2C_Starterror=I2C_masterSendStartCondation();
	uint8 addr_l=0x10100000;

	I2C_masterSendSlaveAddressWrite(addr_l);
	I2C_ERROR_STATUS I2C_AdressError=I2C_masterSendByte((uint8 )address);

	I2C_ERROR_STATUS I2C_RepeatedStartError=I2C_masterSendRepeatedStart();

	I2C_ERROR_STATUS I2C_AddressReadError=I2C_masterSendSlaveAddressRead((uint8 )data);

	I2C_ERROR_STATUS I2C_DataReadError= I2C_masteReadByte(data);

	I2C_masterStopCondation();

}
#endif /* MCAL_EEPROM_EEPROM_PROGRAM_C_ */
