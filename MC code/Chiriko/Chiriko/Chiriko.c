/*
 * Chiriko.cpp
 *
 * Created: 11/2/2012 11:48:19 PM
 *  Author: Tyler
 *	Description:	this is the driver program that controls the RSC09's camera bracket
 *					and treads
 */ 

#include <avr/io.h>
#include "TreadAxis.h"
#include "CameraAxis.h"
//#define F_CPU 16000000UL

int main(void)
{
	TreadAxisInit();
	CameraAxisInit();
	
	DDRC = 0xff; //(1<<DDRC0)|(1<<DDRC1)|(1<<DDRC7);
	PORTC = 0x00;
	int count;
    while(1)
    {
		TreadAxisDecode();
		CameraAxisDecode();
			_delay_ms(151);
    }
}