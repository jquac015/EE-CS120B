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
	DDRC = 0x00;
	PORTC = 0x00;
	DDRD = 0xFF;
	PORTD = 0x00;
	unsigned char error = 0x00;
	unsigned char weight;
	while(1){
		weight = PINA+PINB+PINC;
		if(weight <= 0x8C){
			error = error & 0x00;
		}else{
			error = error | 0x01;
		}
		if(PINA>PINC){
			if((PINA-PINC)>0x50){
				error = error | 0x02;
			}
		}
		if(PINA<PINC){
			if((PINC-PINA)>0x50){
				error = error | 0x02;
			}
		}
		weight = weight & 0xFC;
		PORTD = weight | error;
	}
	return 1;
}
