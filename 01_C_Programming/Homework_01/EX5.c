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

	printf("ASCII value of %c = %d\n", ch, ch);

	return 0;
}
