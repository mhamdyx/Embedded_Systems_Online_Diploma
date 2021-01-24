/*
 * EX3.c
 *
 *  Created on: Jan 25, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

void reverse_sentence(void);

int main(void)
{
	printf("Enter a sentence: ");
    reverse_sentence();
	printf("\n");

	return 0;
}

void reverse_sentence(void)
{
	char ch = getchar();

	if(ch == '\n')
	{
		printf("\n");
		return;
	}
	
    reverse_sentence();
	printf("%c", ch);
}
