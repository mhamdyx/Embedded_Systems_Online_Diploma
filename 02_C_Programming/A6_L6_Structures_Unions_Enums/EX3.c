/*
 * EX3.c
 *
 *  Created on: Jan 29, 2021
 *      Author: MahmoudH
 */

/* Libraries */
#include <stdio.h>

/* Declarations */
struct complex_s
{
	double real;
	double imaginary;
};

/* Function Prototypes */
struct complex_s read_complex(char number_place[]);

void add_complex(struct complex_s number1, struct complex_s number2);

/* Main Program */
int main(void)
{
	struct complex_s complex_n1, complex_n2;

	complex_n1 = read_complex("1st");
	complex_n2 = read_complex("2nd");
    
	add_complex(complex_n1, complex_n2);

	return 0;
}

/* Function Definitions */
struct complex_s read_complex(char number_place[])
{
	struct complex_s complex;

	printf("\nFor %s complex number\n", number_place);
	printf("Enter real and imaginary respectively: ");
	scanf("%lf %lf", &complex.real, &complex.imaginary);

	return complex;
}

void add_complex(struct complex_s number1, struct complex_s number2)
{
	struct complex_s result;

	result.real = number1.real + number2.real;
	result.imaginary = number1.imaginary + number2.imaginary;

	printf("Sum=%.1lf+%.1lfi\n", result.real, result.imaginary);
}
