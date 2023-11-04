/*
 * I2C_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_I2C_I2C_PROGRAM_C_
#define MCAL_I2C_I2C_PROGRAM_C_

#include "I2C_registers.h"
#include "I2C_config.h"
#include "I2C_private.h"
#include "I2C_interface.h"


void I2C_masterPreScaler()
{
#if(PRESCALER== PRESCALIN_1)

	CLEAR_BIT(TWSR_REG,0);
	CLEAR_BIT(TWSR_REG,1);
#elif(PRESCALER== PRESCALIN_4)
	SET_BIT(TWSR_REG,0);
	CLEAR_BIT(TWSR_REG,1);
#elif(PRESCALER== PRESCALIN_16)
	CLEAR_BIT(TWSR_REG,0);
	SET_BIT(TWSR_REG,1);
#elif(PRESCALER== PRESCALIN_64)
	SET_BIT(TWSR_REG,0);
	SET_BIT(TWSR_REG,1);

#endif

}

void I2C_masterInit()
{

	I2C_masterPreScaler();
	TWBR_REG=0X02;
	TWCR_REG->TWEN=1;
	TWCR_REG->TWEA=1;
}
I2C_ERROR_STATUS I2C_masterSendStartCondation(void)
{
	I2C_ERROR_STATUS local_error=NO_ERROR;
	TWCR_REG->TWSTA=1;
	TWCR_REG->TWINT=1;
	while(TWCR_REG->TWINT !=1 );
	if((TWSR_REG & 0xf8) != 0x08)
	{
		local_error= START_ERROR;
	}
	return local_error;

}
I2C_ERROR_STATUS  I2C_masterSendRepeatedStart(void)
{
	I2C_ERROR_STATUS local_error=NO_ERROR;
		TWCR_REG->TWSTA=1;
		TWCR_REG->TWINT=1;
		while(TWCR_REG->TWINT !=1 );
		if((TWSR_REG & 0xf8) != 0x10)
		{
			local_error= START_ERROR;
		}
		return local_error;
}
I2C_ERROR_STATUS I2C_masterSendSlaveAddressWrite(uint8 address)
{
	I2C_ERROR_STATUS local_error=NO_ERROR;
	TWDR_REG=(address<<1);

	CLEAR_BIT(TWDR_REG,0);
	TWCR_REG->TWSTA=0;
	TWCR_REG->TWINT=1;

	while(TWCR_REG->TWINT !=1 );

	if((TWSR_REG & 0xf8) != 0x18)
	{
		local_error= SLAVE_ADDRESS_WRITE_ERROR;
	}
	return local_error;
}
I2C_ERROR_STATUS I2C_masterSendSlaveAddressRead(uint8 address)
{
	I2C_ERROR_STATUS local_error=NO_ERROR;
	TWDR_REG=(address<<1) | 0x01;

	CLEAR_BIT(TWDR_REG,0);
	TWCR_REG->TWSTA=0;
	TWCR_REG->TWINT=1;

	while(TWCR_REG->TWINT !=1 );

	if((TWSR_REG & 0xf8) != 0x40)
	{
		local_error= SLAVE_ADDRESS_READ_ERROR;
	}
	return local_error;
}
I2C_ERROR_STATUS I2C_masterSendByte(uint8 data)
{
	I2C_ERROR_STATUS local_error=NO_ERROR;
	TWDR_REG=data;
	TWCR_REG->TWINT=1;
	TWCR_REG->TWEN=1;

	while(TWCR_REG->TWINT !=1 );
	if((TWSR_REG & 0xf8) != 0x28)
	{
		local_error= SEND_BYTE_ERROR;
	}
	return local_error;
}

I2C_ERROR_STATUS I2C_masteReadByte(uint8 *I2C_DATA)
{
	I2C_ERROR_STATUS local_error=NO_ERROR;
	TWCR_REG->TWINT=1;/*Clear Flag*/
	I2C_DATA=TWDR_REG;

	while(TWCR_REG->TWINT !=1 );
	if((TWSR_REG & 0xf8) != 0x50)
	{
		 local_error=READ_BYTE_ERROR;
	}
	return local_error;
}

void I2C_masterStopCondation(void)
{
	TWCR_REG->TWINT=1;
	TWCR_REG->TWSTO=1;
	TWCR_REG->TWEN=1;
}
#endif /* MCAL_I2C_I2C_PROGRAM_C_ */
