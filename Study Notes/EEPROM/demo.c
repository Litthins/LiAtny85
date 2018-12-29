/*
 * Demo.c
 *
 * Created: 2018/11/27 20:31:28
 * Author : Litthins
 */ 

#include <avr/io.h>
#include "Headers/My_EEPROM.h"

int main(void)
{
    /* Replace with your application code */
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
		//if (ucBaseAdderss > 0x0200) ucBaseAdderss = 0x0000;
    }
}
