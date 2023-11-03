/*
 * SPI_config.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#include "../GPIO/GPIO_Config.h"

#define MOSI    PORTB_ID, 5
#define SCK		PORTB_ID,7
#define SS  PORTB_ID,4
#define MISO       PORTB_ID,6

#define PRESCALER   F_64D
#endif /* MCAL_SPI_SPI_CONFIG_H_ */
