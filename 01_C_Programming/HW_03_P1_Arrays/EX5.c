/*
 * EX5.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

#define MAX_LEN 100

int main(void)
{
	int arr[MAX_LEN], arr_len, element, i;

	// Computing the size of the dataset
	printf("Enter no of elements: ");
	scanf("%d", &arr_len);

	// Reading the dataset
	for(i = 0; i < arr_len; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\nEnter the element to be searched: ");
	scanf("%d", &element);

	// Searching for the element in question
	for(i = 0; i < arr_len; i++)
	{
		if(arr[i] == element)
			break;
	}

	// Checking if no breaks
	if(i == arr_len)
	{
		printf("\nNumber is not found\n");
	}
	else
	{
		printf("\nNumber found at the location = %d\n", i + 1);
	}

	return 0;
}
