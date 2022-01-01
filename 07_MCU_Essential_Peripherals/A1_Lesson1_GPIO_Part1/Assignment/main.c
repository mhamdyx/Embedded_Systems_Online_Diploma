/*
 * Unit7_Lesson1_Assignment.c
 *
 * Created: 12/31/2021 5:32:50 PM
 * Author : MahmoudH
 */ 

typedef volatile unsigned char vuint8;

// GPIOD registers
#define DDRD	(*(vuint8 *)(0x31))
#define PORTD	(*(vuint8 *)(0x32))

// GPIOD pins
#define PD4	4
#define PD5	5
#define PD6	6
#define PD7	7

// Hardware abstraction pins
#define BUZZER	PD4
#define LED0	PD5
#define LED1	PD6
#define LED2	PD7

// Function-like macros
#define SET_BIT(reg, bit) ((reg) |= (1 << (bit)))
#define CLR_BIT(reg, bit) ((reg) &= ~(1 << (bit)))

// Prototypes
void delay(unsigned int count);

// Delay periods
#define LED_DELAY	1000
#define BUZZ_DELAY	500

int main(void)
{
    // Initialize Port D pins as output
	DDRD |= (1 << BUZZER) | (1 << LED0) | (1 << LED1) | (1 << LED2);
    
	while (1) 
    {
		// Step 1
		CLR_BIT(PORTD, BUZZER);
		CLR_BIT(PORTD, LED2);
		SET_BIT(PORTD, LED0);
		delay(LED_DELAY);
		
		// Step 2
		CLR_BIT(PORTD, LED0);
		SET_BIT(PORTD, LED1);
		delay(LED_DELAY);
		
		// Step 3
		CLR_BIT(PORTD, LED1);
		SET_BIT(PORTD, LED2);
		delay(LED_DELAY);
		
		// Step 4
		SET_BIT(PORTD, BUZZER);
		delay(BUZZ_DELAY);
    }
	
	return 0;
}


void delay(unsigned int count)
{
	vuint8 i;
	
	while(count--)
	{
		for(i = 0; i < 255; i++);
	}
}

