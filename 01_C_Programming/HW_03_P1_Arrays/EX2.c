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

	// Computing the size of the dataset
	printf("Enter the numbers of data: ");
	scanf("%d", &n);

	// Reading the dataset from the user
	for(i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i + 1);
		scanf("%f", &input);

		sum += input; // Computing the total value
	}

	// Computing average given a valid size 
	printf("Average = %.2f\n", (n > 0) ? (sum / n) : 0);

	return 0;
}
