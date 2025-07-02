#include "LED.h"

void LED_vintial(u8 PORT_NO, u8 PIN_NO)
{
	DIO_Set_Pin_Direction(PORT_NO,PIN_NO,OUTPUT);
}
void LED_ON(u8 PORT_NO, u8 PIN_NO)
{
	DIO_Write_Pin(PORT_NO,PIN_NO,LED__ON);
}
void LED_OFF(u8 PORT_NO, u8 PIN_NO)
{
	DIO_Write_Pin(PORT_NO,PIN_NO,LED__OFF);
}
void LED_Toggle(u8 PORT_NO, u8 PIN_NO)
{
	DIO_TogglePin(PORT_NO,PIN_NO);
}
u8 LED_u8ReadStatus(u8 PORT_NO, u8 PIN_NO)
{
	return DIO_u8ReadPin(PORT_NO,PIN_NO);
}
//-------------------------------------------------------------------
// ****** HAL Driver ******\\
// -- Second Driver Done -- \\
