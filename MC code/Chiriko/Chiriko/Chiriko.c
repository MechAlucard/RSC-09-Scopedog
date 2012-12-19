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

int main(void)
{
	TreadAxisInit();
	CameraAxisInit();
    while(1)
    {
		TreadAxisDecode();
		CameraAxisDecode();
		_delay_ms(20);
    }
}