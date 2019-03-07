/*
 * IOPorts.h
 *
 * Created: 2019/2/18 18:03:38
 *  Author: Litthins
 */ 


#ifndef IOPORTS_H_
#define IOPORTS_H_

/*Output函数：IOPorts_Output_Set_High()
 *Set PORTB0 Output High
 */
void IOPorts_Output_Set_High();

/*Output函数：IOPorts_Output_Set_Low()
 *Set PORTB0 Output Low
 */
void IOPorts_Output_Set_Low();

/*Input函数：IOPorts_Read_Input()
 *Read PORTB PINs
 */
unsigned char IOPorts_Read_Input();

#endif /* IOPORTS_H_ */