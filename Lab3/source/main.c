/*	Author: jquac015 
 *	Lab Section: 025
 *	Assignment: Lab 3 Exercise 5
 *	Exercise Description: 
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
	DDRB = 0xFE;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	DDRD = 0x00;
	PORTD = 0x0;
	unsigned char led = 0x00;
    while (1) {
	if(PIND>=0x23){
		led = led | 0x02;
	}else{
		led = led & 0xFD;
	}
	if((PIND<0x23) && (PIND>=0x03)){
		led = led | 0x04;
	}else{
		led = led & 0xFB;
	}
	PORTB = led;
    }
    return 1;
}
