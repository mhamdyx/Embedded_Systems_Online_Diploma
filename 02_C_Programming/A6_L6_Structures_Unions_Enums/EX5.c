/*
 * EX5.c
 *
 *  Created on: Jan 29, 2021
 *      Author: MahmoudH
 */

/* Libraries */
#include <stdio.h>

/* Macros */
#define PI 3.14159

#define AREA_OF_CIRCLE(R) (PI * (R) * (R))

/* Main Program */
int main(void)
{
	double radius;

	printf("Enter the radius: ");
	scanf("%lf", &radius);

	printf("Area=%.2lf\n", AREA_OF_CIRCLE(radius));

	return 0;
}
