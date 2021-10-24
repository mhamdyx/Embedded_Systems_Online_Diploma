/*
 * EX4.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include  <stdio.h>

int main(void)
{
	float n;

	printf("Enter a number: ");
	scanf("%f", &n);

	if(n > 0)
	{
		printf("%.2f is positive\n", n);
	}
	else if(n < 0)
	{
		printf("%.2f is negative\n", n);
	}
	else
	{
		printf("You entered zero\n");
	}

	return 0;
}
