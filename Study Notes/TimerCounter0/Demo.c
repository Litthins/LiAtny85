/*
 * Demo.c
 *
 * Created: 2018/12/21 10:40:37
 * Author : Litthins
 */ 

#include <avr/io.h>
#include "Headers/TimerCounter0.h"

int main(void)
{
	/* Waveform Generation Mode:Normal;
    * Compare Output Mode:COM0B,Toggle;
    * Clock Select:clk(io),No prescaling;
    */
	TimerCounter0_Normal_Toggle(0XDD);
	
	/* Waveform Generation Mode:CTC;
    * Compare Output Mode:COM0A,Toggle;
    * Clock Select:clk(io),No prescaling;
    */
	TimerCounter0_CTC_Toggle(0X00);
	
    while (1) {}
}