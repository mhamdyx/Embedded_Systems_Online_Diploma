/*
 * Unit6_Lesson4_Lab3.c
 *
 * Created: 12/14/2021
 * Author : MahmoudH
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned char uint8;
#define RW volatile
#define IO_BASE 0x20
#define IO_SREG (*(RW uint8 *)(IO_BASE + 0x3F))
#define I 7

#define LED0 PD5
#define LED1 PD6
#define LED2 PD7
#define LEDS_MASK ((1 << LED0) | (1 << LED1) | (1 << LED2))


void GPIO_init(void);
void EXT_INT_init(void);

int main(void)
{
	// Initialize LED pins
    GPIO_init();
	
	// Initialize external interrupt module
	EXT_INT_init();
	
    while (1) 
    {
		// Turn all LEDs off
		PORTD &= ~LEDS_MASK;
    }
}

ISR(INT0_vect)
{
	// Turn LED0 on
	PORTD |= (1 << LED0);
	
	// Wait 1 second
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	// Turn LED1 on
	PORTD |= (1 << LED1);
	
	// Wait 1 second
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	// Turn LED2 on
	PORTD |= (1 << LED2);
	
	// Wait 1 second
	_delay_ms(1000);
}

void GPIO_init(void)
{
	// Port D -> Pin 5, Pin 6, Pin 7 -> Output
	DDRD |= LEDS_MASK;
}

void EXT_INT_init(void)
{
	// Configure Interrupt Sense Control
	// INT0 -> Any logical change
	// INT1 -> Rising edge
	// INT2 -> Falling edge
	MCUCR |= (1 << ISC11) | (1 << ISC10) | (1 << ISC00);
	
	// External Interrupt Request Enable
	GICR |= (1 << INT1) | (1 << INT0) | (1 << INT2);
	
	// Global interrupt enable
	IO_SREG |= (1 << I);
}
