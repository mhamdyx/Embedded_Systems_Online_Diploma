/*
 * EX7.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	int n, i;
	unsigned int factorial = 1;

	printf("Enter an integer: ");
	scanf("%d", &n);

	if(n < 0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.\n");
	}
	else
	{
		for(i = 2; i <= n; i++)
		{
			factorial *= i;
		}

		printf("Factorial = %u\n", factorial);
	}

	return 0;
}
