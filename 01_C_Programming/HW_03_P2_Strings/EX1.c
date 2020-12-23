/*
 * EX1.c
 *
 *  Created on: Dec 23, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>
#include <string.h>

#define LEN 100

int main(void)
{
	char sentence[LEN], ch;
	unsigned int ch_freq = 0, sent_len, i;

	printf("Enter a string: ");
	gets(sentence);

	sent_len = strlen(sentence);

	printf("\nEnter a character to find frequency: ");
	scanf(" %c", &ch);

	for(i = 0; i < sent_len; i++)
	{
		if(sentence[i] == ch)
			ch_freq++;
	}

	printf("\nFrequency of %c = %d\n", ch, ch_freq);

	return 0;
}
