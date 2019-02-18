/*
 * Demo.c
 *
 * Created: 2018/12/21 10:40:37
 * Author : Litthins
 */ 

#include <avr/io.h>
#include "Headers/My_TimerCounter0.h"

int main(void)
{
	/* Waveform Generation Mode:Normal;
    * Compare Output Mode:COM0B,Toggle;
    * Clock Select:clk(io),No prescaling;
    */
	My_TimerCounter0_Normal_Toggle();
	
	/* Waveform Generation Mode:CTC;
    * Compare Output Mode:COM0A,Toggle;
    * Clock Select:clk(io),No prescaling;
    */
	My_TimerCounter0_CTC_Toggle();
	
    while (1) {}
}