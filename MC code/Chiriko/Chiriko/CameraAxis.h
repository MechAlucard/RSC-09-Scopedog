/*
 * CameraAxis.h
 *
 * Created: 11/4/2012 3:04:05 PM
 *  Author: Tyler
 *	Description:  Sets up a PWM RC servo motor controller with a period of 20ms
 *					PW of 1.5ms for neutral pulse, 2ms for max pulse, 1ms for min pulse.
 * 					Opcode		|	Function
 *					---------------------------------------		
 *					1100xxxb	|	Pan Left
 *					10xxxxxb	|	Pan Right
 *					xx11xxxb	|	Tilt Up
 *					xx10xxxb	|	Tilt Down
 *					0000xxxb	|	Stop Camera
 *					XXXX1xxxb	|	 LED on
  *					XXXX0xxxb	|	 LED off
 */

#ifndef CAMERAAXIS_H_
#define CAMERAAXIS_H_
#include <avr/io.h>
#include <util/delay.h>
#include <avr/cpufunc.h>
//Description:	starts the PWM and set pan and tilt to neutral positions, LED setup
//				puts LED in off
//Return:		error code of 0 for no error
int CameraAxisInit();

//Description:	changes the axises by one or maintains the axis and outputs a PW
//Return:		error code of 0 for no error
int CameraAxisDecode();

//Description:	increases the tilt PW by 1us up to 2ms
//Return:		error code of 0 for no error, -1 for limit reached
int TiltInc();

//Description:	decreases the tilt PW by 1us down to 1ms
//Return:		error code of 0 for no error, -1 for limit reached
int TiltDec();

//Description:	increases the pan PW by 1us down to 1ms
//Return:		error code of 0 for no error, -1 for limit reached
int PanInc();

//Description:	decreases the pan PW by 1us down to 1ms
//Return:		error code of 0 for no error, -1 for limit reached
int PanDec();

//Description:	Turns LED on
//Return:		error code of 0 for no error
int LED_On();

//Description:	Turns LED off
//Return:		error code of 0 for no error
int LED_Off();

//Description:	gets the current tilt position from 0 to 255
//Return:		tilt percentage
unsigned char GetTilt();

//Description:	gets the current pan position from 0 to 255
//Return:		pan percentage
unsigned char GetPan();
#endif /* CAMERAAXIS_H_ */