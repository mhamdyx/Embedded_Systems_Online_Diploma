/*
 * fifo_test.c
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

// LIFO test script
#include "fifo.h"
#include <stdio.h>

#define FIFO_BUF_LEN 5

#define FIFO_TESTING(fifo_func, pass_condition, pass_count, fail_count) \
if((fifo_func) == (pass_condition))		\
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
	Item arr[FIFO_BUF_LEN], temp;
	int i;
	FIFO_Buf_st fifo;
	int passed = 0, failed = 0;

	// Initialization
	printf("Testing Initialization:\n");
	FIFO_TESTING(fifo_init(&fifo, arr, FIFO_BUF_LEN), FIFO_NO_ERROR, passed, failed);

	// Enqueue
	printf("\nTesting Enqueue with 7 elements given the FIFO length is 5 only:\n");
	for(i = 0; i < FIFO_BUF_LEN; i++)
	{
		FIFO_TESTING(fifo_enqueue(&fifo, i), FIFO_NO_ERROR, passed, failed);
	}

	for(i = 0; i < 2; i++)
	{
		FIFO_TESTING(fifo_enqueue(&fifo, i), FIFO_FULL, passed, failed);
	}

	// Printing
	printf("\nVerifying enqueue with printing:\n");
	FIFO_TESTING(fifo_print(&fifo), FIFO_NO_ERROR, passed, failed);

	// Is full?
	printf("\nTesting capacity: FIFO is full\n");
	FIFO_TESTING(fifo_is_full(&fifo), FIFO_FULL, passed, failed);

	// Dequeue
	printf("\nTesting Dequeue:\n");
	for(i = 0; i < FIFO_BUF_LEN - 2; i++)
	{
		FIFO_TESTING(fifo_dequeue(&fifo, &temp), FIFO_NO_ERROR, passed, failed);
	}

	// Printing
	printf("\nVerifying dequeue with printing:\n");
	FIFO_TESTING(fifo_print(&fifo), FIFO_NO_ERROR, passed, failed);

	// Is empty?
	printf("\nTesting capacity: FIFO is not empty\n");
	FIFO_TESTING(fifo_is_empty(&fifo), FIFO_NOT_EMPTY, passed, failed);

	// Make empty
	printf("\nMaking FIFO empty:\n");
	FIFO_TESTING(fifo_make_empty(&fifo), FIFO_NO_ERROR, passed, failed);

	// Is empty?
	printf("\nTesting capacity: FIFO is empty\n");
	FIFO_TESTING(fifo_is_empty(&fifo), FIFO_EMPTY, passed, failed);


	printf("\nTest Report:\n");
	printf("Total Cases  : %2d\n", passed + failed);
	printf("Total Passed : %2d\n", passed);
	printf("Total Failed : %d\n", failed);

	return 0;
}
