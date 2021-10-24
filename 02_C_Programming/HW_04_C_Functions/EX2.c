/*
 * EX2.c
 *
 *  Created on: Jan 25, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

unsigned int factorial(unsigned int n);

int main(void)
{
	unsigned int n;
    
	printf("Enter a positive integer: ");
	scanf("%u", &n);

	printf("\nFactorial of %u = %u\n", n, factorial(n));

	return 0;
}

unsigned int factorial(unsigned int n)
{
    /* Base Case: Factorial(1) = Factorial(0) = 1 */
	if(n <= 1)
		return 1;

	return n * factorial(n - 1);
}
