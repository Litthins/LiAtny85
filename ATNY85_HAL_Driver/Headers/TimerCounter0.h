/*
 * TimerCounter0.h
 *
 * Created: 2018/12/21 10:43:38
 *  Author: Litthins
 */ 


#ifndef TIMERCOUNTER0_H_
#define TIMERCOUNTER0_H_

/* Waveform Generation Mode:Normal;
 * Compare Output Mode:COM0B,Toggle;
 * Clock Select:clk(io),No prescaling;
 */
void TimerCounter0_Normal_Toggle(uint8_t OCR0B_Init_Value);

/* Waveform Generation Mode:CTC;
 * Compare Output Mode:COM0A,Toggle;
 * Clock Select:clk(io),No prescaling;
 */
void TimerCounter0_CTC_Toggle(uint8_t OCR0A_Init_Value);

/* Waveform Generation Mode:FastPWM;
 */
void TimerCounter0_FastPWM();

#endif /* TIMERCOUNTER0_H_ */