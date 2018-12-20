/*
 * My_5_3_EEPROM.c
 *
 * Created: 2018/12/20 18:17:11
 *  Author: Litthins
 */ 

#include <avr/io.h>
#include "../Headers/My_5_3_EEPROM.h"

void My_EEPROM_Write(unsigned char ucAdderss, unsigned char ucData)
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

unsigned char My_EEPROM_Read(unsigned int ucAdderss)
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