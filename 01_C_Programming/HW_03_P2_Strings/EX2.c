/*
 * EX2.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

#define MAX_LEN 100

int main(void)
{
	char input_string[MAX_LEN];
	int len = 0;

	printf("Enter a string: ");
	
	// Read the whole line including spaces
	gets(input_string);

	// Find the null character
	while(input_string[len++]);

	// Decrement to get the accurate length
	printf("\nLength of string: %d\n", --len);

	return 0;
}
