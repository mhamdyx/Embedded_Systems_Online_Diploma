/*
 * EX1.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	// Matrices of 2 rows and 2 columns
	float first_matrix[2][2], second_matrix[2][2];
	
	// Used as indicies
	int i, j;

	printf("Enter the elements of 1st matrix\n");

	// Reading the first matrix (matrix a)
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter a%d%d: ", i + 1, j + 1);
			scanf("%f", &first_matrix[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix\n");

	// Reading the second matrix (matrix b)
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter b%d%d: ", i + 1, j + 1);
			scanf("%f", &second_matrix[i][j]);
		}
	}

	printf("\nSum of Matrix:\n");
    
	// Computing and printing the sum
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%.1f\t", first_matrix[i][j] + second_matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
