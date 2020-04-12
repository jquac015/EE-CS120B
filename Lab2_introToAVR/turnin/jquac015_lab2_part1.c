/*	Author: Justin Quach  jquac015@ucr.edu
 *	Lab Section: 025
 *	Assignment: Lab 2 Introduction to AVR
 *	Exercise Description: Introductory AVR lab. Compilation, simulation, wtc.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0x00;
	DDRB = 0x00;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */	
	while(1){
		if(!(PINA&0x02)&(PINA&0x01)){
			PORTB = 0x01;
		}else{
			PORTB = 0x00;
		}
	}
	return 1;
}
