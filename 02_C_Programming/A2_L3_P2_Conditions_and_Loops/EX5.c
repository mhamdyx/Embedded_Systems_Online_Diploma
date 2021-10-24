/*
 * EX5.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter a character: ");
	scanf(" %c", &ch);

	if(ch >= 'A' && ch < 'z')
	{
		printf("%c is an alphabet\n", ch);
	}
	else
	{
		printf("%c is not an alphabet\n", ch);
	}

	return 0;
}
