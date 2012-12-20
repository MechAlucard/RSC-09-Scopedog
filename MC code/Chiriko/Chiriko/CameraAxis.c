/*
 * CameraAxis.c
 *
 * Created: 11/4/2012 4:37:46 PM
 *  Author: Tyler
 */ 
//Description:	starts the PWM and set pan and tilt to neutral positions, LED setup
//				puts LED in off
//Return:		error code of 0 for no error
#include "CameraAxis.h"
#define MAX_TILT 400
#define MID_TILT 296
#define MIN_TILT 191
#define MAX_PAN 430
#define MID_PAN 310
#define MIN_PAN 191
static unsigned int tilt_pos;
static unsigned int pan_pos;
int CameraAxisInit()
{
	//set PORTD to inputs with no pullups
	PORTD = 0x00;
	DDRD = 0x00;
	//set PORTC[0:2] to outputs and initialize to zero
	DDRC = 0xff; //(1<<DDRC0)|(1<<DDRC1)|(1<<DDRC7);
	PORTC = 0x00;//(0<<PAN_BIT)|(0<<TILT_BIT)|(0<<PORTC2);
	tilt_pos = MID_TILT;
	pan_pos = MID_PAN;//650;
	return 0;
}

//Description:	changes the axises by one or maintains the axis and outputs a PW
//Return:		error code of 0 for no error
int CameraAxisDecode()
{
	//update LED
	volatile unsigned char code = 0;
	code = PIND;
	if(0x08 == (code & 0x08))
	{
		LED_On();
	}		
	else if(0x00 == (code & 0x08))
	{
		LED_Off();
	}		
	//update tilt axis	
	if(0x30 == (code & 0x30))
	{
		TiltInc();
	}	
	else if (0x20 == (code & 0x30))
	{
		TiltDec();
	}	
	//update pan axis	
	if(0xC0 == (code & 0xC0))
	{
		PanInc();
	}	
	else if(0x80 == (code & 0xC0))
	{
		PanDec();
	}	
	//make PW times
	//volatile unsigned int pan_count = pan_pos;
	//volatile unsigned int tilt_count = tilt_pos;
	volatile unsigned int delay = 440;
	//Min PW for pan
	PORTC |= ((1<<0)|(1<<1));
	//pan PWM
	while(delay--)
	{	
		_delay_us(1);
	}
	
	delay = 430;
	while(delay--)
	{
		if(pan_pos >= delay)
			PORTC &= ~(1<<0);
		if(tilt_pos >= delay)
			PORTC &= ~(1<<1);
		_delay_us(1);
	}
	PORTC &=~((1<<1)|(1<<0));
	
	return 0;
}

//Description:	increases the tilt PW by 1us up to 2ms
//Return:		error code of 0 for no error, -1 for limit reached
int TiltInc()
{
	int ret = 0;
	if(tilt_pos >= MAX_TILT)
		ret = -1;
	else
		tilt_pos++;
	return ret;
}

//Description:	decreases the tilt PW by 1us down to 1ms
//Return:		error code of 0 for no error, -1 for limit reached
int TiltDec()
{
	int ret = 0;
	if(tilt_pos <= MIN_TILT)
		ret = -1;
	else
		tilt_pos--;
	return ret;
}

//Description:	increases the pan PW by 1us down to 1ms
//Return:		error code of 0 for no error, -1 for limit reached
int PanInc()
{
	int ret = 0;
	if(pan_pos >= MAX_PAN)
		ret = -1;
	else
		pan_pos++;
	return ret;
}

//Description:	decreases the pan PW by 1us down to 1ms
//Return:		error code of 0 for no error, -1 for limit reached
int PanDec()
{
	int ret = 0;
	if(pan_pos <= MIN_PAN)
		ret = -1;
	else
		pan_pos++;
	return ret;
}

//Description:	Turns LED on
//Return:		error code of 0 for no error
int LED_On()
{
	PORTC |= (1<<PORTC7);
	return 0;
}

//Description:	Turns LED off
//Return:		error code of 0 for no error
int LED_Off()
{
	PORTC = PORTC & ((1<<PORTC7) ^ 0xff);
	return 0;
}
//Description:	gets the current tilt position from 0 to 255
//Return:		tilt percentage
unsigned char GetTilt()
{
	return tilt_pos;
}

//Description:	gets the current pan position from 0 to 255
//Return:		pan percentage
unsigned char GetPan()
{
	return pan_pos;
}