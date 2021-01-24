/*
 * EX4.c
 *
 *  Created on: Jan 25, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

int power(int base_number, unsigned int power_number);

int main(void)
{
	int base_number;
	unsigned int power_number;

	printf("Enter base number: ");
	scanf("%d", &base_number);

	printf("Enter power number(positive integer): ");
	scanf("%u", &power_number);

	printf("%d^%u = %d\n", base_number, power_number, power(base_number, power_number));

	return 0;
}

int power(int base_number, unsigned int power_number)
{
    /* Base Cases */
	if(base_number == 0)
		return 0; /* (0 ^ number) = 0 */
	else if((base_number == 1) || (power_number == 0))
		return 1; /* (1 ^ number) = (number ^ 0) = 1 */
	else if(power_number == 1)
		return base_number; /* (number ^ 1) = number */

	return base_number * power(base_number, power_number - 1);
}
