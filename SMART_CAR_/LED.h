/*
 * LED.h
 *
 * Created: 4 / 7 / 2024 10:36:16 PM
 *  Author: Adham Amr
 */ 

#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"

#ifndef LED_H_
#define LED_H_

/*
	Function Name        : LED_vintial
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Initialize the pin as an output pin to connect the led.
*/
void LED_vintial(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : LED_ON
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Turn on the led connected to the given pin and port.
*/
void LED_ON(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : LED_OFF
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Turn off the led connected to the given pin and port.
*/
void LED_OFF(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : LED_Toggle
	Function Returns     : void
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Toggle the led connected to the given pin and port.
*/
void LED_Toggle(u8 PORT_NO, u8 PIN_NO);

/*
	Function Name        : LED_u8ReadStatus
	Function Returns     : u8
	Function Arguments   : u8 PORT_NO, u8 PIN_NO
	Function Description : Return the status of LED ( ON { 1 } or OFF { 0 } ).
*/
u8 LED_u8ReadStatus(u8 PORT_NO, u8 PIN_NO);
#endif /* LED_H_ */
