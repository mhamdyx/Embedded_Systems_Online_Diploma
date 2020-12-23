/*
 * EX4.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

#define MAX_LEN 100

int main(void)
{
	int arr[MAX_LEN], arr_len, extra_element, position, i;

	printf("Enter no of elements: ");
	scanf("%d", &arr_len);

	printf("\n");

	for(i = 0; i < arr_len; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\r\nEnter the element to be inserted: ");
	scanf("%d", &extra_element);

	printf("\nEnter the location: ");
	scanf("%d", &position);

	printf("\n");

	for(i = arr_len; i >= position; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[position - 1] = extra_element;
	arr_len++;

	for(i = 0; i < arr_len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}
