/*
 * EX2.c
 *
 *  Created on: Feb 12, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	char alphabets[26];
	char *p_arr = alphabets;
	int i;

	printf("The Alphabets are:\n");
	for(i = 0; i < 26; i++)
	{
		*(p_arr + i) = 'A' + i;
		printf("%c ", *(p_arr + i));
	}

	return 0;
}
