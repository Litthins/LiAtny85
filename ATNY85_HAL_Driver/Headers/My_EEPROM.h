/*
 * EEPROM.h
 *
 * Created: 2018/12/20 18:16:12
 *  Author: Litthins
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


void EEPROM_Write(unsigned char ucAdderss, unsigned char ucData);
unsigned char EEPROM_Read(unsigned int ucAdderss);


#endif /* EEPROM_H_ */