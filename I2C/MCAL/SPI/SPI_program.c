/*
 * SPI_program.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Shaimaa Gamal
 */


#include "SPI_interface.h"
#include"SPI_registers.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "util/delay.h"


void SPI_masterInit(void)
{
	GPIO_SetupPin_Direction(MISO, PIN_INPUT);/*MISO*/
	GPIO_SetupPin_Direction(MOSI, PIN_OUTPUT);/*MOSI*/
	GPIO_SetupPin_Direction(SCK, PIN_OUTPUT);
	GPIO_SetupPin_Direction(SS, PIN_OUTPUT);/*MOSI*/


	SPCR_REG->MSTR=1; /*Master Slave Select*/
	SPCR_REG->SPR=0b01;
	SPSR_REG->SPI2X=0;
	SPCR_REG->SPE=1;
	_delay_ms(1000);
}

void SPI_masterTransmit(uint8 data)
{
	SPDR_REG=data;
	while(SPSR_REG->SPIF !=1);
}


void SPI_slaveInit(void)
{
	GPIO_SetupPin_Direction(MISO, PIN_OUTPUT);
	GPIO_SetupPin_Direction(MOSI, PIN_INPUT);
	GPIO_SetupPin_Direction(SCK, PIN_INPUT);
	GPIO_SetupPin_Direction(SS, PIN_INPUT);


	SPCR_REG->MSTR=0; /*Master Slave Select*/
	SPCR_REG->SPE=1;
}

uint8 SPI_slaveRecive(void)
{
	while(SPSR_REG->SPIF !=1);
	return SPDR_REG;
}

uint8 SPI_rx_tx(uint8 data)
{
	SPDR_REG=data;
	while(SPSR_REG->SPIF !=1);
	return SPDR_REG;
}
