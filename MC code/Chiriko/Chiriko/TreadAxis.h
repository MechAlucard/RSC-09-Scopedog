/*************************************************************************************************************
*	Filename: TreadAxis.h
*	Author:	Tyler Martin
*	Date: 11/03/2012
*	Description:	These functions control the treads based on input from PORTD
*					Opcode		|	Function
*					---------------------------------------		
*					xxxxx001b	|	Forward
*					xxxxx010b	|	Backward
*					xxxxx011b	|	Left
*					xxxxx100b	|	Right
*					xxxxx000b	|	Halt
*	
**************************************************************************************************************/
#ifndef TREADAXIS_H_
#define TREADAXIS_H_
#include <avr/io.h>

//Description: Picks up the parallel code and executes the function corresponding to the code
//Return:		error code of 0 for no error
int TreadAxisDecode();

//Description:	Drives motors forward
//Return:		error code of 0 for no error
int Forwards();

//Description:	Drives motors backwards
//Return:		error code of 0 for no error
int Backwards();

//Description:	Drives left bank forward and right bank backwards
//Return:		error code of 0 for no error
int Left();

//Description:	Drives right bank forward and the left bank backwards
//Return:		error code of 0 for no error
int Right();

//Description:	Disables all motors
//Return:		error code of 0 for no error
int Hold();

//Description:	PORTD set to inputs with pull ups
//				PORTA set to outputs for left motor bank
//				PORTB set to outputs for Right Motor bank
//Return:		error code of 0 for no error
int TreadAxisInit();
#endif