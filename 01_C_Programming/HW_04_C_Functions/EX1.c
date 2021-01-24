/*
 * EX1.c
 *
 *  Created on: Jan 24, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>
#include <math.h>

void print_prime_between(int start_interval, int end_interval);

int main(void)
{
	int start_int, end_int;

	printf("Enter two numbers(intervals): ");
	scanf("%d %d", &start_int, &end_int);

	print_prime_between(start_int, end_int);

	return 0;
}

void print_prime_between(int start_interval, int end_interval)
{
	int number, divisor, min_factor;

	printf("Prime numbers between %d and %d are: ", start_interval, end_interval);

	for(number = start_interval; number <= end_interval; number++)
	{
        /* Minimum factor of a number can not be greater than its square root */
		min_factor = sqrt(number);

		for(divisor = 2; divisor <= min_factor; divisor++)
		{
			if(number % divisor == 0)
				break;
		}

		if(divisor > min_factor)
			printf("%d ", number);
	}

	printf("\n");
}
