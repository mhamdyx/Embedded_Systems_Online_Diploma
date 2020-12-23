/*
 * EX3.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

#define MAX_LEN 100

int main(void)
{
	char input_string[MAX_LEN];
	int len = 0, left, right;

	printf("Enter the string: ");
	
	// Read the whole line including spaces
	gets(input_string);

	// Computing length
	while(input_string[len++]);
	len--;

	// Reversing the string using swapping
	for(left = 0, right = len - 1; left < right; left++, right--)
	{

		input_string[left] ^= input_string[right];
		input_string[right] ^= input_string[left];
		input_string[left] ^= input_string[right];
	}

	printf("Reverse string is: %s\n", input_string);

	return 0;
}
