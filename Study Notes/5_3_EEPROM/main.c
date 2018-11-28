/*
 * 5_3_EEPROM.c
 *
 * Created: 2018/11/27 20:31:28
 * Author : Litthins
 */ 

#include <avr/io.h>

void My_EEPROM_Write(unsigned char ucAdderss, unsigned char ucData);
unsigned char My_EEPROM_Read(unsigned int ucAdderss);

int main(void)
{
	unsigned char ucBaseAdderss = 0x00;
	unsigned int  uiBaseAdderss = 0x0000;
	unsigned char ucBaseData = 0x00;
	unsigned int  timer = 0x0000;
	
	for (ucBaseAdderss = 0x00;ucBaseAdderss < 0xff;ucBaseAdderss++)
	{
		My_EEPROM_Write(ucBaseAdderss,ucBaseData);
		ucBaseData++;
	}
	
	while(EECR & (1<<EEPE));
	EEARH=0x01;
	
	for (ucBaseAdderss = 0x00;ucBaseAdderss < 0xff;ucBaseAdderss++)
	{
		My_EEPROM_Write(ucBaseAdderss,ucBaseData);
		ucBaseData--;
	}
	
	uiBaseAdderss = 0x00;
    while (1) 
    {
		DDRB=(1<<DDB4);
		PORTB=(1<<PB4);
		for (timer=0x0000;timer<0x0032;timer++);
		PORTB=(0<<PB4);
		for (timer=0x0000;timer<16*My_EEPROM_Read(uiBaseAdderss);timer++);
		uiBaseAdderss++;
    }
}

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
	//Éset address//
	EEAR = ucAdderss;
	//Enable EEPE//
	EECR = EECR | (1<<EERE);
	//Perform read operation//
	return EEDR;
}