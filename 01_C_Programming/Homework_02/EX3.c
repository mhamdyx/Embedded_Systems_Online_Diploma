/*
 * EX3.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	float n1, n2, n3, max_n;

	printf("Enter three numbers: ");
	scanf("%f %f %f", &n1, &n2, &n3);

	max_n = (n1 > n2) ? ((n1 > n3) ? n1 : n3) : ((n2 > n3) ? n2 : n3);

	printf("Largest number = %.2f\n", max_n);

	return 0;
}
