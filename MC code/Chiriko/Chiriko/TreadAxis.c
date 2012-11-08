#include "TreadAxis.h"
#define TREAD_MASK 0x07
#define FORWARD 0x01
#define	BACKWARD 0x02
#define LEFT 0x03
#define RIGHT 0x04
#define HALT 0x00
//Description: Picks up code on PORTD and executes the function corresponding to the code
//Return:		error code of 0 for no error
int TreadAxisDecode()
{
	unsigned char cmd = 0;
	cmd = PIND;
	if(FORWARD == (cmd & TREAD_MASK))
		Forwards();
	else if(BACKWARD == (cmd & TREAD_MASK))
		Backwards();
	else if(LEFT == (cmd & TREAD_MASK))
		Left();
	else if(RIGHT == (cmd & TREAD_MASK))
		Right();
	else if(HALT == (cmd & TREAD_MASK))
		Hold();
	else
		Hold();
	return 0;
}

//Description:	Drives motors forward
//Return:		error code of 0 for no error
int Forwards()
{
	//Drive Left Bank forwards
	PORTA = (1<<PORTA0)|(1<<PORTA1)|(1<<PORTA3);
	//Drive Right Bank Forwards
	PORTB = (1<<PORTB0)|(1<<PORTB1)|(1<<PORTB3);
	return 0;
}

//Description:	Drives motors backwards
//Return:		error code of 0 for no error
int Backwards()
{
	//Drive Left Bank backwards
	PORTA = (1<<PORTA0)|(1<<PORTA2)|(1<<PORTA4);
	//Drive Right Bank Backwards
	PORTB = (1<<PORTB0)|(1<<PORTB2)|(1<<PORTB4);
	return 0;
}

//Description:	Drives left bank forward and right bank backwards
//Return:		error code of 0 for no error
int Left()
{
	//Drive Left Bank forwards
	PORTA = (1<<PORTA0)|(1<<PORTA1)|(1<<PORTA3);
	//Drive Right Bank Backwards
	PORTB = (1<<PORTB0)|(1<<PORTB2)|(1<<PORTB4);
	return 0;
}

//Description:	Drives right bank forward and the left bank backwards
//Return:		error code of 0 for no error
int Right()
{
	//Drive Left Bank backwards
	PORTA = (1<<PORTA0)|(1<<PORTA2)|(1<<PORTA4);
	//Drive Right Bank Forwards
	PORTB = (1<<PORTB0)|(1<<PORTB1)|(1<<PORTB3);
	return 0;
}

//Description:	Disables all motors
//Return:		error code of 0 for no error
int Hold()
{
	PORTA = HALT;
	PORTB = HALT;
	return 0;
}
//Description:	PORTD set to inputs with disabled pull ups
//				PORTA set to outputs for left motor bank
//				PORTB set to outputs for Right Motor bank
//Return:		error code of 0 for no error
int TreadAxisInit()
{
	//set PORTD to inputs with no pullups
	PORTD = 0x00;
	DDRD = 0x00;
	//set PORTA as outputs
	PORTA = HALT;
	DDRA = (1<<DDRA0)|(1<<DDRA1)|(1<<DDRA2)|(1<<DDRA3)|(1<<DDRA4);
	//set PORTB as outputs
	PORTB = HALT;
	DDRB = (1<<DDRB0)|(1<<DDRB1)|(1<<DDRB2)|(1<<DDRB3)|(1<<DDRB4);
	return 0;
}