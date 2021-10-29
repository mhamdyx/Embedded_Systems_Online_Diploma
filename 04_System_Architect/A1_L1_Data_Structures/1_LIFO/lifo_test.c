/*
 * lifo_test.c
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

// LIFO test script
#include "lifo.h"
#include <stdio.h>

#define LIFO_BUF_LEN 5

#define LIFO_TESTING(lifo_func, pass_condition, pass_count, fail_count) \
if((lifo_func) == (pass_condition))		\
{										\
	(pass_count)++;						\
	printf("Test passed\n");			\
}										\
else									\
{										\
	(fail_count)++;						\
	printf("Test failed\n");			\
}

int main(void)
{
	Item arr[LIFO_BUF_LEN], temp;
	int i;
	LIFO_Buf_st lifo;
	int passed = 0, failed = 0;

	// Initialization
	printf("Testing Initialization:\n");
	LIFO_TESTING(lifo_init(&lifo, arr, LIFO_BUF_LEN), LIFO_NO_ERROR, passed, failed);

	// Pushing
	printf("\nTesting Pushing:\n");
	for(i = 0; i < LIFO_BUF_LEN; i++)
	{
		LIFO_TESTING(lifo_push(&lifo, i), LIFO_NO_ERROR, passed, failed);
	}

	// Printing
	printf("\nVerifying pushing with printing:\n");
	LIFO_TESTING(lifo_print(&lifo), LIFO_NO_ERROR, passed, failed);

	// Is full?
	printf("\nTesting capacity: LIFO is full\n");
	LIFO_TESTING(lifo_is_full(&lifo), LIFO_FULL, passed, failed);

	// Popping
	printf("\nTesting Popping:\n");
	for(i = 0; i < LIFO_BUF_LEN - 2; i++)
	{
		LIFO_TESTING(lifo_pop(&lifo, &temp), LIFO_NO_ERROR, passed, failed);
	}

	// Top
	printf("\nTesting top item: 1\n");
	LIFO_TESTING(lifo_top(&lifo, &temp), LIFO_NO_ERROR, passed, failed);

	// Printing
	printf("\nVerifying popping with printing:\n");
	LIFO_TESTING(lifo_print(&lifo), LIFO_NO_ERROR, passed, failed);

	// Is empty?
	printf("\nTesting capacity: LIFO is not empty\n");
	LIFO_TESTING(lifo_is_empty(&lifo), LIFO_NOT_EMPTY, passed, failed);

	// Make empty
	printf("\nMaking LIFO empty:\n");
	LIFO_TESTING(lifo_make_empty(&lifo), LIFO_NO_ERROR, passed, failed);

	// Is empty?
	printf("\nTesting capacity: LIFO is empty\n");
	LIFO_TESTING(lifo_is_empty(&lifo), LIFO_EMPTY, passed, failed);


	printf("\nTest Report:\n");
	printf("Total Cases  : %2d\n", passed + failed);
	printf("Total Passed : %2d\n", passed);
	printf("Total Failed : %d\n", failed);

	return 0;
}
