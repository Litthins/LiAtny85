/*
 * SystemClock.h
 *
 * Created: 2019/3/8 9:12:08
 *  Author: Litthins
 */ 


#ifndef SYSTEMCLOCK_H_
#define SYSTEMCLOCK_H_

/*系统时钟设置函数：SystemClock_Set()
 *该函数调用时需要到SystemClock.c中设置，
 *否则默认为8MHz,with CKDIV8 unprogramed=1
 */
void SystemClock_Set();

#endif /* SYSTEMCLOCK_H_ */