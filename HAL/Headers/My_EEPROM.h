/*
 * My_EEPROM.h
 *
 * Created: 2018/12/20 18:16:12
 *  Author: Litthins
 */ 


#ifndef MY_EEPROM_H_
#define MY_EEPROM_H_


void My_EEPROM_Write(unsigned char ucAdderss, unsigned char ucData);
unsigned char My_EEPROM_Read(unsigned int ucAdderss);


#endif /* MY_EEPROM_H_ */