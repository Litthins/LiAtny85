/*
 * 11_7_TimerCounter0.c
 *
 * Created: 2018/12/21 10:40:37
 * Author : Litthins
 */ 

#include <avr/io.h>
#include "Headers/My_11_7_TimerCounter0.h"

int main(void)
{
	//My_TimerCounter0_Normal_Toggle();
	My_TimerCounter0_CTC_Toggle();
    while (1) {}
}