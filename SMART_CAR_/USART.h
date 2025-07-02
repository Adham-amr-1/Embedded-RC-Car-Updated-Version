/*
 * USART.h
 *
 *  Created on: Aug 30, 2024
 *      Author: ADHam
 */
#define F_CPU 8000000UL
#include "DIO.h"
#include "STD_Types.h"
#include "STD_Macros.h"
#include "Registers.h"
#include <avr/delay.h>
#define NORMAL_SPEED
//#define HIGH_SPEED


#ifndef USART_H_
#define USART_H_

/*
	Function Name        : UART_vInit
	Function Returns     : void
	Function Arguments   : u32 BAUD_RATE
	Function Description : Set the UART Communication.
*/
void UART_vInit(u32 BAUD_RATE);

/*
	Function Name        : UART_Send_Data
	Function Returns     : void
	Function Arguments   : u8 DATA
	Function Description : Send Data Through TX pin.
*/
void UART_Send_Data(u8 DATA);

/*
	Function Name        : UART_Send_String
	Function Returns     : void
	Function Arguments   : u8* DATA
	Function Description : Send Whole String.
*/
void UART_Send_String(u8* DATA);

/*
	Function Name        : UART_u8Receive_Data
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Receive Data From RX Pin.
*/
u8 UART_u8Receive_Data();

/*
	Function Name        : UART_DOR_Check
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Check if there's data exist in RXB and a data come from RX Pin .
*/
u8 UART_DOR_Check();

/*
	Function Name        : UART_PE_Check
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Check the Parity Error.
*/
u8 UART_PE_Check();

/*
	Function Name        : UART_FE_Check
	Function Returns     : void
	Function Arguments   : void
	Function Description : Check the Frame Error.
*/
u8 UART_FE_Check();

/*
	Function Name        : Set_Normal_Asynchronous_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set UART To be Normal speed Asynchronous Mode.
*/
void Set_Normal_Asynchronous_Mode();

/*
	Function Name        : Set_Double_Speed_Asynchronous_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set UART To be double speed Asynchronous Mode.
*/
void Set_Double_Speed_Asynchronous_Mode();

/*
	Function Name        : Set_UARTRX_Interrupt
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set Interrupt of UART RX.
*/
void Set_UARTRX_Interrupt();

/*
	Function Name        : Clear_UARTRX_Interrupt
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear Interrupt of UART RX.
*/
void Clear_UARTRX_Interrupt();
#endif /* USART_H_ */
