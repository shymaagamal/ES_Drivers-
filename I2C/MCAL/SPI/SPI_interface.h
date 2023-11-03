/*
 * SPI_interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../LIB/std_types.h"
void SPI_masterInit(void);
void SPI_masterTransmit(uint8 data);
void SPI_slaveInit(void);
uint8 SPI_slaveRecive(void);
uint8 SPI_rx_tx(uint8 data);
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
