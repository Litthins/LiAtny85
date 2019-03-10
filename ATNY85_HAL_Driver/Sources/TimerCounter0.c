/*
 * TimerCounter0.c
 *
 * Created: 2018/12/21 10:43:53
 *  Author: Litthins
 */ 

#include <avr/io.h>
#include "../Headers/TimerCounter0.h"

/* Waveform Generation Mode:Normal;
 * Compare Output Mode:COM0B,Toggle;
 * Clock Select:clk(io),No prescaling;
 */
void TimerCounter0_Normal_Toggle()
{
	PORTB=(1<<PB1);
	DDRB=(1<<DDB1);
	
	GTCCR=(1<<TSM);
	GTCCR=(1<<PSR0);
	
	TCCR0A=(0<<COM0A1)|(0<<COM0A0)|(0<<COM0B1)|(1<<COM0B0)|(0<<WGM01)|(0<<WGM00);
	TCCR0B=(0<<WGM02)|(0<<CS02)|(0<<CS01)|(1<<CS00);
	
	GTCCR=(0<<TSM);
}

/* Waveform Generation Mode:CTC;
 * Compare Output Mode:COM0A,Toggle;
 * Clock Select:clk(io),No prescaling;
 */
void TimerCounter0_CTC_Toggle()
{
	PORTB=(1<<PB0);
	DDRB=(1<<DDB0);
	
	GTCCR=(1<<TSM);
	GTCCR=(1<<PSR0);
	
	OCR0A=0X00;//Check The clk(io) Frequency.
	
	TCCR0A=(0<<COM0A1)|(1<<COM0A0)|(0<<COM0B1)|(0<<COM0B0)|(1<<WGM01)|(0<<WGM00);
	TCCR0B=(0<<WGM02)|(0<<CS02)|(0<<CS01)|(1<<CS00);
	
	GTCCR=(0<<TSM);
}