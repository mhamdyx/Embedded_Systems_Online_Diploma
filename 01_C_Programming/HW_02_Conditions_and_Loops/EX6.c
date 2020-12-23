/*
 * EX6.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	unsigned int n, sum = 0;

	printf("Enter an integer: ");
	scanf("%u", &n);

	while(n > 0)
	{
		sum += n;
		n--;
	}

	printf("Sum = %u\n", sum);

	return 0;
}
