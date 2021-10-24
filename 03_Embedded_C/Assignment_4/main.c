/*
 * main.c
 *
 *  Created on: Sep 21, 2021
 *      Author: MahmoudH
 */

#include "hw_access.h"

// System control module base address
#define SYSCTL_BASE 0x400FE000
// Register inside SYSCTL module
#define SYSCTL_RCGC2_R IO_RW_REG32(SYSCTL_BASE + 0x108)

// GPIO Port F base address
#define GPIOF_BASE 0x40025000
// Data inside GPIOF module
#define GPIO_PORTF_DATA_R IO_RW_REG32(GPIOF_BASE + 0x3FC)
// Direction register inside GPIOF module
#define GPIO_PORTF_DIR_R IO_RW_REG32(GPIOF_BASE + 0x400)
// Digital enable register register inside GPIOF module
#define GPIO_PORTF_DEN_R IO_RW_REG32(GPIOF_BASE + 0x51C)

// Bit manipulation macros
#define SET_BIT(reg, bit_num) (reg) |= (1 << (bit_num))
#define CLR_BIT(reg, bit_num) (reg) &= ~(1 << (bit_num))

// Software delay macro
#define SW_DELAY(counter, count) SW_DELAY2((counter), (count))
#define SW_DELAY2(counter, count) \
for(counter = 0; counter < count; counter++)

int main(void)
{
	volatile uint32 delay_count;
	SYSCTL_RCGC2_R = 0x00000020;
	SW_DELAY(delay_count, 200);
	SET_BIT(GPIO_PORTF_DIR_R, 3);
	SET_BIT(GPIO_PORTF_DEN_R, 3);

	while(1)
	{
		SET_BIT(GPIO_PORTF_DATA_R, 3);
		SW_DELAY(delay_count, 200000);
		
		CLR_BIT(GPIO_PORTF_DATA_R, 3);
		SW_DELAY(delay_count, 200000);
	}

	return 0;
}
