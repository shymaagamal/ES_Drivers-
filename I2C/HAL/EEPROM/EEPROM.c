/*
 * EEPROM_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_EEPROM_EEPROM_PROGRAM_C_
#define MCAL_EEPROM_EEPROM_PROGRAM_C_

#include "EEPROM.h"

void EEPROM_init(void)
{
	I2C_voidInit();

}

void EEPROM_write(uint16 address, uint8 data)
{
	I2C_ERROR_STATUS I2C_Starterror=I2C_sendStartCondation();
	uint8 addr_l=(address>>8) & 0x03;
	I2C_masterSendSlaveAddressWrite(addr_l|0x50);

	I2C_ERROR_STATUS I2C_AdressError=I2C_masterSendByte((uint8 )address);
	I2C_ERROR_STATUS I2C_DataError	=I2C_masterSendByte((uint8 )data);
	I2C_masterStopCondation();

}

void EEPROM_read(uint16 address,uint8 *data)
{
	I2C_ERROR_STATUS I2C_Starterror=I2C_sendStartCondation();
	uint8 addr_l=(address>>8)&0x03;

	I2C_masterSendSlaveAddressWrite(addr_l|0x50);
	I2C_ERROR_STATUS I2C_AdressError=I2C_masterSendByte((uint8 )address);
	I2C_ERROR_STATUS I2C_DataError=I2C_masteReadByte((uint8 )data);
	I2C_masterStopCondation();

}
#endif /* MCAL_EEPROM_EEPROM_PROGRAM_C_ */
