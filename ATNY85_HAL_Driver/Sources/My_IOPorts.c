/*
 * My_IOPorts.c
 *
 * Created: 2019/2/18 18:03:57
 *  Author: Litthins
 */ 

#include <avr/io.h>
#include "../Headers/My_IOPorts.h"

//PORTB5Ĭ��ΪRESET���ţ��ϵ��Ϊ�ߵ�ƽ����ͨ��������˿����Ĭ�����ã�����Ӱ��USBASP���ع��ܡ�
//����Ĭ�ϲ���PORTB5���κβ�����

/*Output������My_IOPorts_Output_Set_High()
 *Set PORTB PINs Output High
 */
void My_IOPorts_Output_Set_High()
{
	PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
	DDRB=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4);
}

/*Output������My_IOPorts_Output_Set_Low()
 *Set PORTB PINs Output Low
 */
void My_IOPorts_Output_Set_Low()
{
	PORTB=(0<<PB0)|(0<<PB1)|(0<<PB2)|(0<<PB3)|(0<<PB4);
	DDRB=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4);
}

/*Input������My_IOPorts_Read_Input()
 *Read PORTB PINs
 */
unsigned char My_IOPorts_Read_Input()
{
	unsigned char read_all_pins;
	//MCUCR=1<<PUD;//Pull-up Disable,������ѡ��
	PORTB=(0<<PB0)|(0<<PB1)|(0<<PB2)|(0<<PB3)|(0<<PB4);
	DDRB=(0<<DDB0)|(0<<DDB1)|(0<<DDB2)|(0<<DDB3)|(0<<DDB4);
	asm ("NOP");//����DatasheetҪ�󣬶�ȡPINs��Ҫ����һ��_NOP();
	read_all_pins=PINB&((1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3)|(1<<PINB4));//PINB0-PINB4Ϊ���õĺ궨�峣��
	return read_all_pins;
}