/*
 * EX1.c
 *
 *  Created on: Feb 12, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	unsigned int m;     /* Integer */
	unsigned int *ab;   /* Pointer to integer */

	m = 29;
	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n\n", m);


	ab = &m;
	printf("Now ab is assigned to the address of m.\n");
	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n\n", *ab);

	m = 34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n\n", *ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n\n", m);

	return 0;
}
