/*	Author: jquac015 
 *	Lab Section: 025
 *	Assignment: Lab 3 Exercise 1
 *	Exercise Description: Count the number of 1s on ports A and B and output that number on port C. 
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
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;

    while (1) {
	tempA = (PINA&0x01) + ((PINA>>1)&0x01) + ((PINA>>2)&0x01) + ((PINA>>3)&0x01) + ((PINA>>4)&0x01)+ ((PINA>>5)&0x01) + ((PINA>>6)&0x01) + ((PINA>>7)&0x01);
        tempB = (PINB&0x01) + ((PINB>>1)&0x01) + ((PINB>>2)&0x01) + ((PINB>>3)&0x01) + ((PINB>>4)&0x01)+ ((PINB>>5)&0x01) + ((PINB>>6)&0x01) + ((PINB>>7)&0x01);
	PORTC = tempA + tempB;
    }
    return 1;
}
