/*
 * My_TimerCounter0.h
 *
 * Created: 2018/12/21 10:43:38
 *  Author: Litthins
 */ 


#ifndef MY_TIMERCOUNTER0_H_
#define MY_TIMERCOUNTER0_H_

/* Waveform Generation Mode:Normal;
 * Compare Output Mode:COM0B,Toggle;
 * Clock Select:clk(io),No prescaling;
 */
void My_TimerCounter0_Normal_Toggle();

/* Waveform Generation Mode:CTC;
 * Compare Output Mode:COM0A,Toggle;
 * Clock Select:clk(io),No prescaling;
 */
void My_TimerCounter0_CTC_Toggle();

/* Waveform Generation Mode:FastPWM;
 */
void My_TimerCounter0_FastPWM();

#endif /* MY_TIMERCOUNTER0_H_ */