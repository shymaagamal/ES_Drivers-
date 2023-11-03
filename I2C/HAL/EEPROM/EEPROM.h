/*
 * EEPROM_config.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_EEPROM_EEPROM_CONFIG_H_
#define MCAL_EEPROM_EEPROM_CONFIG_H_


#include"../../MCAL/I2C/I2C_interface.h"



void EEPROM_init(void);
void EEPROM_write(uint16 address, uint8 data);
#endif /* MCAL_EEPROM_EEPROM_CONFIG_H_ */
