/*
 * IOPorts.c
 *
 * Created: 2019/2/18 18:03:57
 *  Author: Litthins
 */ 

#include <avr/io.h>
#include "../Headers/IOPorts.h"

//PORTB5默认为RESET引脚，上电后为高电平，可通过设置熔丝更改默认设置，但会影响USBASP下载功能。
//以下默认不对PORTB5做任何操作。

/*Output函数：IOPorts_Output_Set_High()
 *Set PORTB PINs Output High
 */
void IOPorts_Output_Set_High()
{
	PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
	DDRB=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4);
}

/*Output函数：IOPorts_Output_Set_Low()
 *Set PORTB PINs Output Low
 */
void IOPorts_Output_Set_Low()
{
	PORTB=(0<<PB0)|(0<<PB1)|(0<<PB2)|(0<<PB3)|(0<<PB4);
	DDRB=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4);
}

/*Input函数：IOPorts_Read_Input()
 *Read PORTB PINs
 */
unsigned char IOPorts_Read_Input()
{
	unsigned char read_all_pins;
	//MCUCR=1<<PUD;//Pull-up Disable,上拉可选项
	PORTB=(0<<PB0)|(0<<PB1)|(0<<PB2)|(0<<PB3)|(0<<PB4);
	DDRB=(0<<DDB0)|(0<<DDB1)|(0<<DDB2)|(0<<DDB3)|(0<<DDB4);
	asm ("NOP");//根据Datasheet要求，读取PINs需要放置一个_NOP();
	read_all_pins=PINB&((1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3)|(1<<PINB4));//PINB0-PINB4为可用的宏定义常量
	return read_all_pins;
}