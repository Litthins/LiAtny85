/*
 * EEPROM.c
 *
 * Created: 2018/12/20 18:17:11
 *  Author: Litthins
 */ 

#include "../Headers/BASE_REG.h"
#include "../Headers/EEPROM.h"

/*EEPROM写函数：EEPROM_Write(unsigned char ucAdderss, unsigned char ucData)
 */
void EEPROM_Write(unsigned char ucAdderss, unsigned char ucData)
{
	//Wait last write//
	while(EECR & (1<<EEPE));
	//Set write mode//
	EECR = (0<<EEPM1)|(0<<EEPM0);
	//Set address and data//
	EEARL = ucAdderss;
	EEDR = ucData;
	//Enable EEPE//
	EECR = EECR | (1<<EEMPE);
	//Perform write operation//
	EECR = EECR | (1<<EEPE);
}

/*EEPROM读函数：EEPROM_Read(unsigned int ucAdderss)
 */
unsigned char EEPROM_Read(unsigned int ucAdderss)
{
	//Wait last write//
	while(EECR & (1<<EEPE));
	//Set write mode//
	EECR = (0<<EEPM1)|(0<<EEPM0);
	//Set address//
	EEAR = ucAdderss;
	//Enable EEPE//
	EECR = EECR | (1<<EERE);
	//Perform read operation//
	return EEDR;
}