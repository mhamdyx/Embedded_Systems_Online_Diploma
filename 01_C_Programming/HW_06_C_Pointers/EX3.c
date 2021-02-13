/*
 * EX3.c
 *
 *  Created on: Feb 12, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>
#define LEN 30

int main(void)
{
	char ch_str[LEN + 1];
	char *ptr = ch_str;

	printf("Input a string : ");
	scanf("%s", ch_str);

	/* Seeking the end of the string */
	while(*ptr++);
    
	/* Adjusting to the end of the string */
	ptr--;

	printf("Reverse of the string is : ");
	while(ptr != ch_str)
	{
		printf("%c", *--ptr);
	}

	printf("\n");

	return 0;
}
