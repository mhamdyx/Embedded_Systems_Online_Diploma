/*
 * main.c
 *
 *  Created on: Sep 16, 2021
 *      Author: MahmoudH
 */

#include "hw_access.h"

// RCC module base address
#define RCC_BASE 0x40021000
// Register inside RCC module
#define RCC_APB2ENR IO_RW_REG32(RCC_BASE + 0x18)
// Pin2 in RCC_APB2ENR register
#define IOPAEN 2

// GPIO Port A base address
#define GPIOA_BASE 0x40010800
// CRH register inside GPIOA module
#define GPIOA_CRH IO_RW_REG32(GPIOA_BASE + 0x04)
// ODR register inside GPIOA module
#define GPIOA_ODR IO_RW_REG32(GPIOA_BASE + 0x0C)
// Pin13 in ODR register
#define ODR13 13 // Position of pin 13
// Pin20 in CRH register
#define MODE13 20 // Mode of Pin 13

extern void Default_Handler(void);

extern void NMI_Handler(void)
{
	Default_Handler();
}

extern void Bus_Fault_Handler(void)
{
	Default_Handler();
}


// Extra GPIOA_ODR Register Access Method
typedef union
{
	volatile uint32 reg_value;
	struct
	{
		volatile uint32 reserved: 13;
		volatile uint32 pin13: 1;
	} bit;
} ODR_ut;

ODR_ut *GPIOA_ODR_bf = ((ODR_ut *)(&GPIOA_ODR));

// Extra variables
uint8 g_variables[3] = {1, 2, 3};
const uint8 const_variables[3] = {1, 2, 3};

int main(void)
{
	uint32 i;
	RCC_APB2ENR |= (1 << IOPAEN);
	GPIOA_CRH &= ~(0xF << MODE13);
	GPIOA_CRH |= (0x2 << MODE13);

	while(1)
	{
		//GPIOA_ODR |= (1 << ODR13);
		GPIOA_ODR_bf->bit.pin13 = 1;
		for(i = 0; i < 100000; i++);
		
		//GPIOA_ODR &= ~(1 << ODR13);
		GPIOA_ODR_bf->bit.pin13 = 0;
		for(i = 0; i < 100000; i++);
	}

	return 0;
}
