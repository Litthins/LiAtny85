/*
 * Demo.c
 *
 * Created: 2019/2/18 18:01:17
 * Author : Litthins
 */ 

#include <avr/io.h>
#include "Headers/My_IOPorts.h"


int main(void)
{
	unsigned char read_all_pins;
	PORTB=(0<<PB0)|(0<<PB1);
	DDRB=(0<<DDB0)|(1<<DDB1);
	while(1)
	{
		asm ("NOP");
		read_all_pins=PINB&(1<<PINB0);//PINB0-PINB4为可用的宏定义常量
		if (read_all_pins==1)	PORTB=PORTB|(1<<PB1);
		if (read_all_pins!=1)	PORTB=PORTB&(0<<PB1);
	}
}

