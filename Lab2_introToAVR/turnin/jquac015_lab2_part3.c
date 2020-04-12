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
	unsigned char cntavail;
	while(1){
                cntavail = (PINA>>3 & 0x01) + (PINA>>2 & 0x01) + (PINA>>1 & 0x01) + (PINA & 0x01);
		if(cntavail == 0x04){
			cntavail = cntavail | 0x80;
		}
		PORTC = 0x04-cntavail;
	}
	return 1;
}
