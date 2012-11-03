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

int main(void)
{
	InitTreads();
    while(1)
    {
        DecodeTread();
    }
}