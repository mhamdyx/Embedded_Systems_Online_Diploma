/*
 * EX8.c
 *
 *  Created on: Dec 18, 2020
 *      Author: MahmoudH
 */

#include <stdio.h>

int main(void)
{
	float operand1, operand2, result;
	char operator;


	printf("Enter operator either + or - or * or divide: ");
	scanf(" %c", &operator);

	printf("Enter two operands: ");
	scanf("%f %f", &operand1, &operand2);

	switch(operator)
	{
	case '+': result = operand1 + operand2; break;
	case '-': result = operand1 - operand2; break;
	case '*': result = operand1 * operand2; break;
	case '/': result = operand1 / operand2; break;
	default: operator = 'X'; break;
	}

	if(operator == 'X')
	{
		printf("Error: Invalid operator\n");
	}
	else
	{
		printf("%.1f %c %.1f = %.1f\n", operand1, operator, operand2, result);
	}

	return 0;
}
