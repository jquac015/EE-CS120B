/*	Author: Justin Quach jquac015@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 4  Exercise 1
 *	Exercise Description: Push Button FSM
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum Push_States{PB_Start, PB0_ON, PB0_WAIT, PB1_ON, PB1_WAIT}Push_State;

void ButtonSM(){
	switch(Push_State){
		case PB_Start:
			Push_State = PB0_ON;
			break;
		case PB0_ON:
			if(PINA&0x01){
				Push_State = PB1_WAIT;
			}else{
				Push_State = PB0_ON;
			}
			break;
		case PB1_WAIT:
			if(!(PINA&0x01)){
				Push_State = PB1_ON;
			}else{
				Push_State = PB1_WAIT;
			}
			break;
		case PB1_ON:
			if(PINA&0x01){
				Push_State = PB0_WAIT;
			}else{
				Push_State = PB1_ON;
			}
			break;
		case PB0_WAIT:
			if(!(PINA&0x01)){
				Push_State = PB0_ON;
			}else{
				Push_State = PB0_WAIT;
			}
			break;
		default:
			Push_State = PB0_ON;
			break;
	}
	switch(Push_State){
		case PB0_ON:
			PORTB = 0x01;
			break;
		case PB1_WAIT:
			PORTB = 0x02;
			break;
		case PB1_ON:
			PORTB = 0x02;
			break;
		case PB0_WAIT:
			PORTB = 0x01;
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00;
	PORTA = 0x00;
	DDRB = 0xFF;
	PORTB = 0x00;
	Push_State = PB_Start;
    while (1) {
	ButtonSM();	
    }
    return 0;
}
