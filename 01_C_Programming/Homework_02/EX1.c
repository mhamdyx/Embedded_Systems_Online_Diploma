/*
 * EX1.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter an integer you want to check: ");
	scanf("%d", &n);

	if(n % 2 == 0)
	{
		printf("%d is even\n", n);
	}
	else
	{
		printf("%d is odd\n", n);
	}

	return 0;
}
