/*
 * EX4.c
 *
 *  Created on: Feb 12, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	int arr[15], size, i;
	int *ptr;

	printf("Input the number of elements to store in the array (max 15): ");
	scanf("%d", &size);

	printf("\nInput %d elements in the array:\n", size);
	for(i = 0; i < size; i++)
	{
		printf("\nelement - %d : ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\nThe elements of array in reverse order are:\n");
	ptr = arr + (size - 1); /* Point to the end of the array */

	for(i = size; i > 0; i--)
	{
		printf("\nelement - %d : %d\n", i, *ptr--);
	}

	return 0;
}
