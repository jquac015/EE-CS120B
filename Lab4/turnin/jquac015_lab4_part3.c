/*	Author: Justin Quach jquac015@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 4  Exercise 2
 *	Exercise Description: Increment and decrement with PA0 and PA1 respectively, reset with both
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum LockStates{Start, STANDBY, S1_WAIT, S1, S2}Lock_State;

void LockSM(){
	switch(Lock_State){
		case Start:
			Lock_State = STANDBY;
			break;
		case STANDBY:
			if((PINA&0x04) && !(PINA&0xFB)){
				Lock_State = S1_WAIT;
			}else{
				Lock_State = STANDBY;
			}
			break;
		case S1_WAIT:
			if((PINA&0x04) && !(PINA&0xFB)){
				Lock_State = S1_WAIT;
			}else if(PINA==0x00){
				Lock_State = S1;
			}else{
				Lock_State = STANDBY;
			}
			break;
		case S1:
			if((PINA&0x02) && !(PINA&0xFD)){
				Lock_State = S2;
			}else if(PINA==0x00){
				Lock_State = S1;
			}else{
				Lock_State = STANDBY;
			}
			break;
		case S2:
			if((PINA&0x80) && !(PINA&0x7F)){
				Lock_State = STANDBY;
			}else{
				Lock_State = S2;
			}
			break;
		default:
			Lock_State = Start;
			break;
	}
	switch(Lock_State){
		case STANDBY:
			PORTB = 0x00;
			PORTC = 0x01;
			break;
		case S1_WAIT:
			PORTC = 0x02;
			break;
		case S1:
			PORTC = 0x03;
			break;
		case S2:
			PORTB = 0x01;
			PORTC = 0x04;
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00;
	PORTA = 0x00;
	DDRB = 0x00;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	Lock_State = Start;
    while (1) {
	LockSM();
    }
    return 0;
}
