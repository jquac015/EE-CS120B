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

enum Counter_States{Start, STANDBY, INC, DEC, INC_WAIT, DEC_WAIT, RESET}Counter_State;
unsigned char count;

void CounterSM(){
	switch(Counter_State){
		case Start:
			Counter_State = STANDBY;
			break;
		case STANDBY:
			if((PINA&0x01) && (count<0x09)){
				Counter_State = INC;
			}else if((PINA&0x02) && (count>0x00)){
				Counter_State = DEC;
			}else if((PINA&0x01) && (PINA&0x02)){
				Counter_State = RESET;
			}else{
				Counter_State = STANDBY;
			}
			break;
		case INC:
			Counter_State = INC_WAIT;
			break;
		case DEC:
			Counter_State = DEC_WAIT;
			break;
		case INC_WAIT:
			if(PINA == 0x03){
				Counter_State = RESET;
			}else if(PINA == 0x00){
				Counter_State = STANDBY;
			}else{
				Counter_State = INC_WAIT;
			}
			break;
		case DEC_WAIT:
			if(PINA == 0x03){
				Counter_State = RESET;
			}else if(PINA == 0x00){
				Counter_State = STANDBY;
			}else{
				Counter_State = DEC_WAIT;
			}
			break;
		case RESET:
			if(PINA == 0x00){
				Counter_State = STANDBY;
			}else{
				Counter_State = RESET;
			}
			break;
		default:
			Counter_State = Start;
			break;
	}
	switch(Counter_State){
		case Start:
			count = 0x07;
			break;
		case STANDBY:
			break;
		case INC:
			count = count+1;
			PORTC = count;
			break;
		case DEC:
			count = count-1;
			PORTC = count;
			break;
		case INC_WAIT:
			break;
		case DEC_WAIT:
			break;
		case RESET:
			count = 0x00;
			PORTC = count;
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00;
	PORTA = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	Counter_State = Start;
    while (1) {
	CounterSM();
    }
    return 0;
}
