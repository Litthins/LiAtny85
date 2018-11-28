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
    }
}

void My_EEPROM_Write(unsigned char ucAdderss, unsigned char ucData)
{
	//等待上一个写操作完成//
	while(EECR & (1<<EEPE));
	//设置工作模式//
	EECR = (0<<EEPM1)|(0<<EEPM0);
	//设置目标地址和目标数据//
	EEARL = ucAdderss;
	EEDR = ucData;
	//EEMPE写1，使EEPE写1有效//
	EECR = EECR | (1<<EEMPE);
	//EEPE写1，开始写EEPROM//
	EECR = EECR | (1<<EEPE);
}

unsigned char My_EEPROM_Read(unsigned int ucAdderss)
{
	//等待上一个写操作完成//
	while(EECR & (1<<EEPE));
	//设置工作模式//
	EECR = (0<<EEPM1)|(0<<EEPM0);
	//设置目标地址//
	EEAR = ucAdderss;
	//EERE写1，开始读EEPROM//
	EECR = EECR | (1<<EERE);
	//从数据寄存器返回读到的数据//
	return EEDR;
}