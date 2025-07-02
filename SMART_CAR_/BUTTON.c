/*
 *	BUTTON.c
 *
 * Created: 4 / 8 / 2024 2:36:16 AM
 *  Author: Adham Amr
 */ 
#include "BUTTON.h"

void Button_vintial(u8 PORT_NO, u8 PIN_NO)
{
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,INPUT);
}
u8 Button_u8read(u8 PORT_NO, u8 PIN_NO)
{
	return DIO_u8ReadPin(PORT_NO,PIN_NO);
}
void Button_Set_PullUp(u8 PORT_NO, u8 PIN_NO)
{
	DIO_PullUp_Active(PORT_NO, PIN_NO);
}
//-------------------------------------------------------------------
// ****** HAL Driver ******\\
// -- Forth Driver Done -- \\
