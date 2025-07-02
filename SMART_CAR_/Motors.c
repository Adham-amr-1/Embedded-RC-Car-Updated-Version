#include "Motors.h"

void DC_Motors_vInit(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Set_High_Nibble_Direction(MOTORS_PORT, OUTPUT);
		break;
	case LOW:
		DIO_Set_Low_Nibble_Direction(MOTORS_PORT, OUTPUT);
		break;
	}
}

void DC_Move_Forward(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void DC_Move_Backward(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE){
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, HIGH);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, HIGH);
		break;
	}
}

void DC_Move_Right(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, HIGH);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, HIGH);
		break;
	}
}

void DC_Move_Left(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 6, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 2, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void DC_Drift_Left(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void DC_Drift_Right(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void DC_Drift_Back_Right(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, HIGH);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void DC_Drift_Back_Left(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, HIGH);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, HIGH);
		break;
	}
}

void DC_STOP(u8 MOTORS_PORT, u8 NIBBLE)
{
	switch(NIBBLE)
	{
	case HIGH:
		DIO_Write_Pin(MOTORS_PORT, 4, LOW);
		DIO_Write_Pin(MOTORS_PORT, 5, LOW);
		DIO_Write_Pin(MOTORS_PORT, 6, LOW);
		DIO_Write_Pin(MOTORS_PORT, 7, LOW);
		break;
	case LOW:
		DIO_Write_Pin(MOTORS_PORT, 0, LOW);
		DIO_Write_Pin(MOTORS_PORT, 1, LOW);
		DIO_Write_Pin(MOTORS_PORT, 2, LOW);
		DIO_Write_Pin(MOTORS_PORT, 3, LOW);
		break;
	}
}

void Servo_vInit_Pin_OC1A()
{
	DIO_Set_Pin_Direction(PORT_D, PIN_NO_5, OUTPUT);
}
void Servo_vInit_Pin_OC1B()
{
	DIO_Set_Pin_Direction(PORT_D, PIN_NO_4, OUTPUT);
}

void Servo_Direction_Pin_OC1A(double DEGREE)
{
	/* select fast PWM mode */
	CLEAR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);
	/* load a value in OCR1A, ICR1 */
	OCR1A = 1000 + (DEGREE*1000)/180;
	ICR1 = 20000;

	/* select timer clock, Divide by 8 , F_timer1 = 1 MHZ */
	CLEAR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);

	/* clear OC1A on compare match, set OC1A at BOTTOM (non-inverting mode) */
	CLEAR_BIT(TCCR1A, COM1A0);
	SET_BIT(TCCR1A, COM1A1);
}
void Servo_Direction_Pin_OC1B(double DEGREE)
{
	/* select fast PWM mode */
	CLEAR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);
	/* load a value in OCR1B, ICR1 */
	OCR1B = 1000 + (DEGREE*1000)/180;
	ICR1 = 20000;

	/* select timer clock, Divide by 8 , F_timer1 = 1 MHZ */
	CLEAR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);

	/* clear OC1A on compare match, set OC1A at BOTTOM (non-inverting mode) */
	CLEAR_BIT(TCCR1A, COM1B0);
	SET_BIT(TCCR1A, COM1B1);
}

void Servo_vInit_Pin_OC0()
{
	DIO_Set_Pin_Direction(PORT_B,PIN_NO_3,OUTPUT);
}

void Servo_Direction_Pin_OC0(u8 DEGREE) {
	switch(DEGREE)
	{
	case 0:
		Timer0_Set_FastPWM_Mode(6);
		break;
	case 90:
		Timer0_Set_FastPWM_Mode(11);
		break;
	case 180:
		Timer0_Set_FastPWM_Mode(16);
		break;
	}
}



















