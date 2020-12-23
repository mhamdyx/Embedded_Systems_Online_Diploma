/*
 * EX2.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	int n, i;
	float input, sum = 0;

	printf("Enter the numbers of data: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i + 1);
		scanf("%f", &input);

		sum += input;
	}

	printf("Average = %.2f\n", (n != 0) ? (sum / n) : 0);

	return 0;
}
