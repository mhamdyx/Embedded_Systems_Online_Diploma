/*
 * EX2.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main(void)
{
	char input_string[MAX_LEN];
	int len = 0;

	printf("Enter a string: ");
	gets(input_string);

	while(input_string[len++]);

	printf("\nLength of string: %d\n", --len);

	return 0;
}
