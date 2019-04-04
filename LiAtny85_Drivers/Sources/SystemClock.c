/*
 * SystemClock.c
 *
 * Created: 2019/3/8 9:12:31
 *  Author: Litthins
 */ 

#include "../Headers/BASE_REG.h"
#include "../Headers/SystemClock.h"

void SystemClock_Set()
{
	//8MHz,with CKDIV8 unprogramed=1
	OSCCAL=0x49;
	//1MHz,with CKDIV8 programed=0
	//OSCCAL=0X4A;

	//写CLKPR操作由以下两步完成，CLKPS决定预分频因子
	CLKPR=(1<<CLKPCE);
	CLKPR=(0<<CLKPCE)|(0<<CLKPS3)|(0<<CLKPS2)|(1<<CLKPS1)|(1<<CLKPS0);
}