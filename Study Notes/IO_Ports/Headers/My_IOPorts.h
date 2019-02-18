/*
 * My_IOPorts.h
 *
 * Created: 2019/2/18 18:03:38
 *  Author: Litthins
 */ 


#ifndef MY_IOPORTS_H_
#define MY_IOPORTS_H_

/*Output函数：My_IOPorts_Output_Set_High()
 *Set PORTB0 Output High
 */
void My_IOPorts_Output_Set_High();

/*Output函数：My_IOPorts_Output_Set_Low()
 *Set PORTB0 Output Low
 */
void My_IOPorts_Output_Set_Low();

/*Input函数：My_IOPorts_Read_Input()
 *Read PORTB PINs
 */
unsigned char My_IOPorts_Read_Input();

#endif /* MY_IOPORTS_H_ */