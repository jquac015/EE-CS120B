/*	Author: jquac015 
 *	Lab Section: 025
 *	Assignment: Lab 3 Exercise 4
 *	Exercise Description: upper nibble of PINA and map it to the lower nibble of PORTB, likewise take the lower nibble of PINA and map it to the upper nibble of PORTC
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA= 0x00;
	PORTA = 0x00;
	DDRB = 0x00;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char lowerA;
	unsigned char upperA;
    while (1) {
	lowerA = PINA<<4;
	upperA = PINA>>4;
	PORTB = upperA;
	PORTC = lowerA;
    }
    return 1;
}
