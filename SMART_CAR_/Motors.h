/*
 * Motors.h
 *
 *  Created on: Aug 24, 2024
 *      Author: ADHam
 */
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO.h"
#include "STD_Types.h"
#include "STD_Macros.h"
#include "Registers.h"
#include "Timers.h"

#ifndef MOTORS_H_
#define MOTORS_H_

/*
	Function Name        : DC_Motors_vInit
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Set Up Motor Pins.
*/
void DC_Motors_vInit(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Move_Forward
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors forward.
*/
void DC_Move_Forward(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Move_Backward
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors backward.
*/
void DC_Move_Backward(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Move_Left
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors Left.
*/
void DC_Move_Left(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Move_Right
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Move Motors right.
*/
void DC_Move_Right(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_STOP
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Stop Car Movement.
*/
void DC_STOP(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Drift_Right
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Drift Motors Right.
*/
void DC_Drift_Right(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Drift_Left
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Drift Motors Left.
*/
void DC_Drift_Left(u8 MOTORS_PORT, u8 NIBBLE);


/*
	Function Name        : DC_Drift_Back_Right
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Drift Motors Back Right.
*/
void DC_Drift_Back_Right(u8 MOTORS_PORT, u8 NIBBLE);

/*
	Function Name        : DC_Drift_Back_Left
	Function Returns     : void
	Function Arguments   : u8 MOTORS_PORT, u8 NIBBLE
	Function Description : Drift Motors Back left.
*/
void DC_Drift_Back_Left(u8 MOTORS_PORT, u8 NIBBLE);



/*
	Function Name        : Servo_vInit_Pin_OC1A
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set servo pin ( OCR1A )
*/
void Servo_vInit_Pin_OC1A();

/*
	Function Name        : Servo_vInit_Pin_OC1B
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set servo pin ( OCR1B )
*/
void Servo_vInit_Pin_OC1B();

/*
	Function Name        : Servo_Direction_Pin_OC1A
	Function Returns     : void
	Function Arguments   : u8 DEGREE
	Function Description : Move the servo to the degree that entered.
*/
void Servo_Direction_Pin_OC1A(double DEGREE);

/*
	Function Name        : Servo_Direction_Pin_OC1B
	Function Returns     : void
	Function Arguments   : u8 DEGREE
	Function Description : Move the servo to the degree that entered.
*/
void Servo_Direction_Pin_OC1B(double DEGREE);


void Servo_vInit_Pin_OC0();

void Servo_Direction_Pin_OC0(u8 DEGREE);
#endif /* MOTORS_H_ */
