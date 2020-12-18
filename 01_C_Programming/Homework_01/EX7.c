/*
 * EX7.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	float a, b;

	printf("Enter value of a: ");
	scanf("%f", &a);

	printf("Enter value of b: ");
	scanf("%f", &b);

	a += b;		// a_new = a_old + b_old
	b = a - b;	// b_new = (a_old + b_old) - b_old = a_old
	a -= b;		// a_new2 = (a_old + b_old) - a_old = b_old

	printf("\nAfter swapping, value of a = %.2f\n", a);
	printf("After swapping, value of b = %.2f\n", b);

	return 0;
}
