/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mahmoud Hamdy
 * @brief          : Unit6 Lesson3 Lab2 - Ex2
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

// EX2
typedef volatile unsigned int vuint32;

// GPIO
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH (*(vuint32 *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR (*(vuint32 *)(GPIOA_BASE + 0x0C))

// GPIOA_CRH pins
#define MODE13 20 // Mode of Pin 13

// GPIOA_ODR pins
#define ODR13 13 // Position of pin 13
//--------------------------------------------------

// RCC
#define RCC_BASE 0x40021000
#define RCC_CR 		(*(vuint32 *)(RCC_BASE + 0x00))
#define RCC_CFGR 	(*(vuint32 *)(RCC_BASE + 0x04))
#define RCC_APB2ENR (*(vuint32 *)(RCC_BASE + 0x18))

// RCC_CR pins
#define PLLON 24 // PLL enable
// 0: PLL OFF
// 1: PLL ON

// RCC_CFGR pins
#define SW 0 // System clock switch
// 00: HSI selected as system clock
// 01: HSE selected as system clock
// 10: PLL selected as system clock
// 11: not allowed

#define PPRE1 8 // APB low-speed prescaler (APB1)
// 0xx: HCLK not divided
// 100: HCLK divided by 2
// 101: HCLK divided by 4
// 110: HCLK divided by 8
// 111: HCLK divided by 16

#define PPRE2 11 // APB high-speed prescaler (APB2)
// 0xx: HCLK not divided
// 100: HCLK divided by 2
// 101: HCLK divided by 4
// 110: HCLK divided by 8
// 111: HCLK divided by 16

#define PLLMUL 18 // PLL multiplication factor
// 0000: PLL input clock x 2
// 0001: PLL input clock x 3
// 0010: PLL input clock x 4
// 0011: PLL input clock x 5
// 0100: PLL input clock x 6
// 0101: PLL input clock x 7
// 0110: PLL input clock x 8
// ...

// RCC_APB2ENR pins
#define IOPAEN 2 // Enable PortA pin
//--------------------------------------------------

int main(void)
{
	vuint32 i;

	// PLL (HSI/2) * 8 = 32 MHz
	RCC_CFGR |= (0b0110 << PLLMUL);

	// Enable PLL clock
	RCC_CR |= (1 << PLLON);

	// Choose system clock to be PLL
	RCC_CFGR |= (0b10 << SW);

	// Setup clock for APB1 (32 / 2 = 16)
	RCC_CFGR |= (0b100 << PPRE1);

	// Setup clock for APB2 (32 / 4 = 8)
	RCC_CFGR |= (0b101 << PPRE2);

	// Enable clock for IO PortA
	RCC_APB2ENR |= (1 << IOPAEN);

	// GPIOA settings
	GPIOA_CRH &= ~(0xF << MODE13);
	GPIOA_CRH |= (0x2 << MODE13);


	while(1)
	{

		GPIOA_ODR |= (1 << ODR13); // High state
		for(i = 0; i < 10000; i++); // Delay
		GPIOA_ODR &= ~(1 << ODR13); // Low state
		for(i = 0; i < 10000; i++); // Delay
	}

	return 0;
}

