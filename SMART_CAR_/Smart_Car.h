/*
 * Smart_Car.h
 *
 *  Created on: Sep 9, 2024
 *      Author: ADHam
 */
/*===================================== DRIVERS =====================================*/
#include "LCD.h"
#include "UltraSonic.h"
#include "USART.h"
#include "STD_Types.h"
#include "DIO.h"
#include "External_Interrupt.h"
#include "Timers.h"
#include "Motors.h"
#include "LED.h"
#include "BUTTON.h"
/*===================================== Manual Choices =====================================*/
#define FORWARD                  	  	  'F'
#define BACKWARD                	 	  'B'
#define STOP                     	  	  'S'
#define LEFT                     	  	  'L'
#define RIGHT                   	  	  'R'
#define DRIFT_RIGHT              	 	  'r'
#define DRIFT_LEFT               	  	  'l'
#define DRIFT_BACK_RIGHT        	 	  'o'
#define DRIFT_BACK_LEFT          	  	  'x'

#define AUTOMATIC_SWITCH        	  	  'T'
#define MANUAL_SWITCH          	      	  't'
#define SET_MAXIMUM_SPEED       	  	  'M'
#define SET_MINIMUM_SPEED        	  	  'N'
#define SET_AVERAGE_SPEED       	  	  'A'
#define START_SPEED_CHANGE           	  'G'
#define CAR_MOVEMENT_USING_ULTRASONIC_IN  'U'
#define CAR_MOVEMENT_USING_ULTRASONIC_OUT 'u'

#define AVERAGE_SPEED            70
#define MAXIMUM_SPEED            90
#define MINIMUM_SPEED            50
#define CAR_DEFAULT_SPEED        80
#define AUTOMATIC_SPEED          30 // Changes using UltraSonic Reading

#define MAX_DISTANCE             40
/*===================================== Macros =====================================*/
// UltraSonic Sensor
#define TRIGGER_PORT_1    PORT_D
#define TRIGGER_PIN_1     PIN_NO_5
// Leds
#define GREEN_LED_PORT    PORT_C
#define GREEN_LED_PIN     PIN_NO_3
#define RED_LED_PORT      PORT_C
#define RED_LED_PIN       PIN_NO_2
// Buttons
#define START_BUTTON_PORT PORT_A
#define START_BUTTON_PIN  PIN_NO_0
/*=================================== VARIABLES ===================================*/
u16 Ultra_Distance_Front;
u16 Ultra_Distance_Right;
u16 Ultra_Distance_Left;
u8 Automatic_1 = LOW;
u8 i;
u8 Choice;
u8 Current_Car_Speed = CAR_DEFAULT_SPEED;
u8 Car_Start = LOW;
u8 First_Num;
u8 Second_Num;
u32 Ultra_Distance;
u8 Speed_Control_Using_UltraSonic = LOW;
/*=================================== Functions ProtoType ===================================*/
#ifndef CAR_FUNCTIONS_H_
#define CAR_FUNCTIONS_H_


void Setup();

void Manual();

void Automatic_Mode_1();

void Check_Collision();

void Show_Car_Speed_On_LCD();

void Show_UltraSonic_Distance_On_LCD();

void Start_Car();

void Show_Car_Engine_Status();

void Car_Control_Speed_Using_UltraSonic();

void Show_Car_Movement();

#endif /* CAR_FUNCTIONS_H_ */


