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
#define CAM_MASK 0x07
#define PAN_BIT PORTC0
#define TILT_BIT PORTC1
#define LED_BIT PORTC2
#define TILT_UP 0x30
#define TILT_DN 0x20
#define PAN_LEFT 0xC0
#define PAN_RIGHT 0x80
#define HALT 0x00
#define LED_ON 0x08
#define LED_OFF 0x00
#define AXIS_MASK 0xF0
#define TILT_MASK 0x30
#define	PAN_MASK 0xC0
#define LED_MASK 0x08
#define MAX_TILT 250
#define MIN_TILT 0
#define MAX_PAN 250
#define MIN_PAN 0

static unsigned char tilt_pos = 127;
static unsigned char pan_pos = 127;
int CameraAxisInit()
{
	//set PORTD to inputs with no pullups
	PORTD = 0x00;
	DDRD = 0x00;
	//set PORTC[0:2] to outputs and initialize to zero
	DDRC = (1<<DDRC0)|(1<<DDRC1)|(1<<DDRC2);
	PORTC = (0<<PAN_BIT)|(0<<TILT_BIT)|(0<<LED_BIT);
	tilt_pos = 125;
	pan_pos = 125;
	return 0;
}

//Description:	changes the axises by one or maintains the axis and outputs a PW
//Return:		error code of 0 for no error
int CameraAxisDecode()
{
	//update LED
	unsigned char code = (PIND & (LED_MASK | AXIS_MASK));
	if(LED_ON == (code & LED_MASK))
		LED_On();
	else
		LED_Off();
	//update tilt axis	
	if(TILT_UP == code & TILT_MASK)
		TiltInc();
	else if (TILT_DN == code & TILT_MASK)
		TiltDec();
	//update pan axis	
	if(PAN_LEFT == code & PAN_MASK)
		PanInc();
	else if(PAN_RIGHT == code & PAN_MASK)
		PanDec();
	//make PW
	int pan_count = pan_pos;
	int tilt_count = tilt_pos;
	int remainder = 0;
	if(tilt_count > pan_count)
		remainder = MAX_TILT - tilt_count;
	else
		remainder = MAX_PAN - pan_count;
	int min_delay = 1000;
	//Min PW of 1ms
	PORTC |= (1<<PAN_BIT)|(1<<TILT_BIT);
	for(min_delay = 1000; min_delay > 0;min_delay--)
	{
		_delay_us(1);
	}
	//remainder PW, up to 1ms
	while((pan_count > 0)||(tilt_count > 0))
	{
		_delay_us(4);
		if(pan_count != 0)
		{
			if(--pan_count == 0)
			{
				PORTC &= (~(1<<PAN_BIT));  
			}
		}
		if(tilt_count != 0)
		{
			if(--tilt_count == 0)
			{
				PORTC &= (~(1<<TILT_BIT));
			}
		}	
				
	}
	while(remainder--)
	{
		_delay_us(4);
	}
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
	PORTC = (1<<LED_BIT);
	return 0;
}

//Description:	Turns LED off
//Return:		error code of 0 for no error
int LED_Off()
{
	PORTC = (0<<LED_BIT);
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