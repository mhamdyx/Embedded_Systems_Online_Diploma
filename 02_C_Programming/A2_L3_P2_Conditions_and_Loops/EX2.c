/*
 * EX2.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter an alphabet: ");
	scanf(" %c", &ch);

	if(!(ch >= 'A' && ch <= 'z'))
	{
		printf("Error: The entered character is not an alphabet\n");
		return 0;
	}

	switch(ch)
	{
	case 'A': case 'E': case 'I': case 'O': case 'U':
	case 'a': case 'e': case 'i': case 'o': case 'u':
		printf("%c is a vowel\n", ch);
		break;
	default:
		printf("%c is a consonant\n", ch);
		break;
	}

	return 0;
}
