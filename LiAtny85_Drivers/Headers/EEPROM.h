/*
 * EEPROM.h
 *
 * Created: 2018/12/20 18:16:12
 *  Author: Litthins
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

/*EEPROM写函数：EEPROM_Write(unsigned char ucAdderss, unsigned char ucData)
 */
void EEPROM_Write(unsigned char ucAdderss, unsigned char ucData);

/*EEPROM读函数：EEPROM_Read(unsigned int ucAdderss)
 */
unsigned char EEPROM_Read(unsigned int ucAdderss);


#endif /* EEPROM_H_ */