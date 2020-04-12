/*	Author: jquac015 
 *	Lab Section: 025
 *	Assignment: Lab 3 Exercise 3
 *	Exercise Description: PC7 should light a "Fasten seatbelt" icon if a key is in the ignition, the driver is seated, but the belt is not fastened.
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
	unsigned char led = 0x00;
	unsigned char temp;
    while (1) {
	if(((PINA>>4)&0x01) & ((PINA>>5)&0x01) & !((PINA>>6)&0x01)){
		led = led | 0x80;
	}else{
		led = led & 0x7F;
	}
	temp = PINA & 0x0F;
	if(temp<=0x04){
		led = led | 0x40;
	}else{
		led = led & 0xBF;
	}
	if(temp>=0x01){
		led = led | 0x20;
	}
	if(temp>=0x03){
		led = led | 0x10;
	}
	if(temp>=0x05){
		led = led | 0x08;
	}
	if(temp>=0x07){
		led = led | 0x04;
	} 
	if(temp>=0x0A){
		led = led | 0x02;
	} 
	if(temp>=0x0D){
		led = led | 0x01;
	}
	PORTC = led;
    }
    return 1;
}
