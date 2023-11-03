/*
 * SPI_registers.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_SPI_SPI_REGISTERS_H_
#define MCAL_SPI_SPI_REGISTERS_H_
#include "../../LIB/std_types.h"
/***********************************************************************************************************
 *										SPCR Register
 **********************************************************************************************************/
typedef struct
{
	uint8 SPR:2;  /*SPI Clock Rate Select 1 and 0*/
	uint8 CPHA:1; /*Clock phase */
	uint8 CPOL:1; /*Clock Polarity */
	uint8 MSTR:1; /*Master Slave Select */
	uint8 DORO:1; /*Data Order*/
	uint8 SPE:1;  /*SPI ENABLE*/
	uint8 SPIE:1;  /*SPI Interrupt Enable*/
}SPCR;

#define SPCR_REG				((volatile SPCR *)0x2D)
/***********************************************************************************************************
 *									SPSR Register
 ***********************************************************************************************************/
typedef struct
{
uint8 SPI2X:1;
uint8 	  :5;
uint8 WCOL:1;
uint8 SPIF:1;
}SPSR;
#define SPSR_REG				((volatile SPSR *)0x2E)
/***********************************************************************************************************
 *									SPDR Register
 ***********************************************************************************************************/
#define SPDR_REG				*((volatile uint8 *)0x2F) /*Data Register*/
#endif /* MCAL_SPI_SPI_REGISTERS_H_ */
