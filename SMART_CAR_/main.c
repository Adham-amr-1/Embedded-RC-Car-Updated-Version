/*
 * Smart_Car.c
 *
 *  Created on: Oct 9, 2024
 *      Author: ADHam
 */
#include "Smart_Car.h"
/*===================================== Main =====================================*/
int main(void)
{
	/*===================================== Initializing =====================================*/
	Setup();
	Start_Car();
	/*===================================== Program Loop =====================================*/
	while(1)
	{
		Show_Car_Speed_On_LCD();
		Show_UltraSonic_Distance_On_LCD();
		Manual();
		Check_Collision();
		Car_Control_Speed_Using_UltraSonic();
		Automatic_Mode_1();
	}
}
/*===================================== Set MC Pins =====================================*/
void Setup()
{
	Set_Global_Interrupt();
	UART_vInit(9600);
	LCD_vInit();
	LCD_DiplayON_CursorOff();
	UltraSonic_vint(TRIGGER_PORT_1, TRIGGER_PIN_1);
	// Set Motor Pins
	DC_Motors_vInit(PORT_A,HIGH);
	// Set Motor Speed
	PWM_Timer2_Generate(CAR_DEFAULT_SPEED);
	// Led To Indicate car collision
	LED_vintial(RED_LED_PORT,RED_LED_PIN);
	// Led To Indicate car can move
	LED_vintial(GREEN_LED_PORT,GREEN_LED_PIN);
	// Start Engine Button
	Button_vintial(START_BUTTON_PORT,START_BUTTON_PIN);
	Button_Set_PullUp(START_BUTTON_PORT,START_BUTTON_PIN);
}
/*===================================== Car Manual =====================================*/
void Manual()
{
	Choice = UART_u8Receive_Data();
	switch(Choice)
	{
	case FORWARD:
		DC_Move_Forward(PORT_A,HIGH);
		break;
	case BACKWARD:
		DC_Move_Backward(PORT_A,HIGH);
		break;
	case RIGHT:
		DC_Move_Right(PORT_A,HIGH);
		break;
	case LEFT:
		DC_Move_Left(PORT_A,HIGH);
		break;
	case DRIFT_RIGHT:
		DC_Drift_Right(PORT_A,HIGH);
		break;
	case DRIFT_BACK_RIGHT:
		DC_Drift_Back_Right(PORT_A,HIGH);
		break;
	case DRIFT_BACK_LEFT:
		DC_Drift_Back_Left(PORT_A,HIGH);
		break;
	case DRIFT_LEFT:
		DC_Drift_Left(PORT_A,HIGH);
		break;
	case STOP:
		DC_STOP(PORT_A,HIGH);
		break;
	case SET_MAXIMUM_SPEED:
		Current_Car_Speed = MAXIMUM_SPEED;
		PWM_Timer2_Generate(MAXIMUM_SPEED);
		break;
	case SET_MINIMUM_SPEED:
		Current_Car_Speed = MINIMUM_SPEED;
		PWM_Timer2_Generate(MINIMUM_SPEED);
		break;
	case SET_AVERAGE_SPEED:
		Current_Car_Speed = AVERAGE_SPEED;
		PWM_Timer2_Generate(AVERAGE_SPEED);
		break;
	case AUTOMATIC_SWITCH:
		Automatic_1 = HIGH;
		break;
	case CAR_MOVEMENT_USING_ULTRASONIC_IN:
		Speed_Control_Using_UltraSonic = HIGH;
		break;
		// Control Car Speed Using Slider in Mobile App
	case START_SPEED_CHANGE:
		if(Choice >= 0 || Choice <= 90)
		{
			First_Num = UART_u8Receive_Data();
			Second_Num = UART_u8Receive_Data();
			Current_Car_Speed = (First_Num-48)*10 + (Second_Num-48);
			PWM_Timer2_Generate(Current_Car_Speed);
		}
		break;
	}
}
/*===================================== Auto Car Using 1-Ultra-Sonic =====================================*/
void Automatic_Mode_1()
{
	if(Automatic_1)
	{
		LCD_Clear_Screen();
		LCD_vSendString(" Automatic Mode ");
		PWM_Timer2_Generate(AUTOMATIC_SPEED);
	}
	while(Automatic_1)
	{
		Ultra_Distance_Front = UltraSonic_ICR_Read(TRIGGER_PORT_1,TRIGGER_PIN_1);
		if(Ultra_Distance_Front >= MAX_DISTANCE)
		{
			DC_Move_Forward(PORT_A,HIGH);
		}
		else
		{
			DC_Move_Right(PORT_A,HIGH);
			_delay_ms(250);
			Ultra_Distance_Right = UltraSonic_ICR_Read(TRIGGER_PORT_1,TRIGGER_PIN_1);
			if(Ultra_Distance_Right >= MAX_DISTANCE)
			{
				DC_Move_Forward(PORT_A,HIGH);
			}
			else
			{
				DC_Move_Right(PORT_A,HIGH);
				_delay_ms(500);
				Ultra_Distance_Left = UltraSonic_ICR_Read(TRIGGER_PORT_1,TRIGGER_PIN_1);
				if(Ultra_Distance_Left >= MAX_DISTANCE)
				{
					DC_Move_Forward(PORT_A,HIGH);
				}
				else
				{
					DC_Drift_Back_Left(PORT_A,HIGH);
					_delay_ms(150);
				}
			}
		}
		if(READ_BIT(UCSRA,RXC) == HIGH)
		{
			if(UDR == MANUAL_SWITCH)
			{
				Automatic_1 = LOW;
				DC_STOP(PORT_A,HIGH);
				LCD_Clear_Screen();
				LCD_Move_Cursor(1,1);
				LCD_vSendString("Car Speed : ");
				LCD_Move_Cursor(2,1);
				LCD_vSendString("Front Dist : ");
				PWM_Timer2_Generate(AVERAGE_SPEED);
			}
		}
	}
}
/*===================================== LCD Display =====================================*/
void Show_Car_Speed_On_LCD()
{
	LCD_Move_Cursor(1,13);
	LCD_vSendChar(((Current_Car_Speed/10)%10) + 48);
	LCD_vSendChar((Current_Car_Speed%10) + 48);
	LCD_vSendChar(' ');
}
void Show_UltraSonic_Distance_On_LCD()
{
	LCD_Move_Cursor(2,14);
	LCD_vSendChar(((Ultra_Distance_Front/100)%10) + 48);
	LCD_vSendChar(((Ultra_Distance_Front/10)%10) + 48);
	LCD_vSendChar((Ultra_Distance_Front%10) + 48);
	LCD_vSendChar(' ');
}
void Show_Car_Engine_Status()
{
	switch(Car_Start)
	{
	case 0:
		LCD_Move_Cursor(1,1);
		LCD_vSendString("Engine On Hold");
		LED_ON(RED_LED_PORT,RED_LED_PIN);
		LED_OFF(GREEN_LED_PORT,GREEN_LED_PIN);
		break;
	case 1:
		LCD_Move_Cursor(1,1);
		LCD_vSendString("Starting Engine");
		LED_ON(GREEN_LED_PORT,GREEN_LED_PIN);
		LED_OFF(RED_LED_PORT,RED_LED_PIN);
		_delay_ms(1000);
		break;
	}
}
/*===================================== Check Car front from any Obstacle =====================================*/
void Check_Collision()
{
	Ultra_Distance_Front = UltraSonic_ICR_Read(TRIGGER_PORT_1,TRIGGER_PIN_1);
	if((Ultra_Distance_Front <= 40) && (Choice == FORWARD))
	{
		DC_STOP(PORT_A,HIGH);
		LED_ON(RED_LED_PORT,RED_LED_PIN);
		LED_OFF(GREEN_LED_PORT,GREEN_LED_PIN);
	}
	else
	{
		LED_OFF(RED_LED_PORT,RED_LED_PIN);
		LED_ON(GREEN_LED_PORT,GREEN_LED_PIN);
	}
}
/*===================================== Car Start =====================================*/
void Start_Car()
{
	while(!Car_Start)
	{
		switch (Button_u8read(START_BUTTON_PORT,START_BUTTON_PIN))
		{
		case 0:
			Car_Start = 1;
			break;
		}
		Show_Car_Engine_Status();
	}
	LCD_Move_Cursor(1,1);
	LCD_vSendString("Car Speed : ");
	LCD_Move_Cursor(2,1);
	LCD_vSendString("Front Dist : ");
}
/*===================================== Car Speed Controlled Using UltraSonic =====================================*/
void Car_Control_Speed_Using_UltraSonic()
{
	if(Speed_Control_Using_UltraSonic)
	{
		LCD_Clear_Screen();
		LCD_vSendString(" Control Speed ");
		LCD_Move_Cursor(2,1);
		LCD_vSendString(" By UltraSonic ");
		_delay_ms(1000);
		PWM_Timer0_Generate(AUTOMATIC_SPEED);
	}
	while(Speed_Control_Using_UltraSonic)
	{
		Ultra_Distance = UltraSonic_ICR_Read(TRIGGER_PORT_1,TRIGGER_PIN_1);
		DC_Move_Forward(PORT_A,HIGH);
		if(Ultra_Distance >= 95)
		{
			PWM_Timer2_Generate(90);
		}
		else if (Ultra_Distance <= 15)
		{
			DC_STOP(PORT_A,HIGH);
		}
		else
		{
			PWM_Timer2_Generate(Ultra_Distance);
		}
		_delay_ms(25);
		if(READ_BIT(UCSRA,RXC) == HIGH)
		{
			if(UDR == CAR_MOVEMENT_USING_ULTRASONIC_OUT)
			{
				Speed_Control_Using_UltraSonic = LOW;
				DC_STOP(PORT_A,HIGH);
				LCD_Clear_Screen();
				LCD_Move_Cursor(1,1);
				LCD_vSendString("Car Speed : ");
				LCD_Move_Cursor(2,1);
				LCD_vSendString("Front Dist : ");
				PWM_Timer2_Generate(AVERAGE_SPEED);
			}
		}
	}
}
