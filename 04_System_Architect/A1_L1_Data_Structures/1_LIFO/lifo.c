/*
 * lifo.c
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

#include "lifo.h"
#include <stdio.h>

LIFO_Status_st lifo_init(LIFO_Buf_st *lifo_buf, Item *item_buf, unsigned int buf_len)
{
	// Check parameters validity
	if(lifo_buf == NULL || item_buf == NULL || buf_len == 0)
	{
		printf("LIFO initialization failed: NULL pointer or zero length is passed\n");
		return LIFO_NULL;
	}

	lifo_buf->base = item_buf;
	lifo_buf->head = lifo_buf->base;
	lifo_buf->buf_len = buf_len;
	lifo_buf->items_count = 0;

	return LIFO_NO_ERROR;
}

LIFO_Status_st lifo_push(LIFO_Buf_st *lifo_buf, Item item)
{
	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL)
	{
		printf("LIFO push item failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Check overflow
	if(lifo_is_full(lifo_buf) == LIFO_FULL)
	{
		printf("LIFO is full\n");
		return LIFO_FULL;
	}

	// Push new item
	*(lifo_buf->head++) = item;
	lifo_buf->items_count++;

	return LIFO_NO_ERROR;
}

LIFO_Status_st lifo_pop(LIFO_Buf_st *lifo_buf, Item *item)
{
	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL || item == NULL)
	{
		printf("LIFO pop failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Check underflow
	if(lifo_is_empty(lifo_buf) == LIFO_EMPTY)
	{
		printf("LIFO pop failed: LIFO is empty\n");
		return LIFO_EMPTY;
	}

	// Pop the top item
	*item = *(--lifo_buf->head);
	lifo_buf->items_count--;

	return LIFO_NO_ERROR;
}

LIFO_Status_st lifo_top(LIFO_Buf_st *lifo_buf, Item *item)
{
	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL || item == NULL)
	{
		printf("LIFO top failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Check underflow
	if(lifo_is_empty(lifo_buf) == LIFO_EMPTY)
	{
		printf("LIFO top failed: LIFO is empty\n");
		return LIFO_EMPTY;
	}

	// Return the top without popping
	*item = *(lifo_buf->head - 1);

	return LIFO_NO_ERROR;
}

LIFO_Status_st lifo_print(LIFO_Buf_st *lifo_buf)
{
	Item *item_ptr;

	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL)
	{
		printf("LIFO print failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Check underflow
	if(lifo_is_empty(lifo_buf) == LIFO_EMPTY)
	{
		printf("LIFO is empty\n");
		return LIFO_EMPTY;
	}

	// Perform the printing
	printf("=======LIFO print=======\n");
	for(item_ptr = lifo_buf->base; item_ptr < lifo_buf->head; item_ptr++)
	{
		printf("\t%d\n", *item_ptr);
	}

	return LIFO_NO_ERROR;
}

LIFO_Status_st lifo_is_full(LIFO_Buf_st *lifo_buf)
{
	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL)
	{
		printf("LIFO is full failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Check if the number of items matches the total buffer length
	if(lifo_buf->items_count == lifo_buf->buf_len)
	{
		return LIFO_FULL;
	}

	return LIFO_NOT_FULL;
}

LIFO_Status_st lifo_is_empty(LIFO_Buf_st *lifo_buf)
{
	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL)
	{
		printf("LIFO is empty failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Check if the number of items is zero
	if(lifo_buf->items_count == 0)
	{
		return LIFO_EMPTY;
	}

	return LIFO_NOT_EMPTY;
}

LIFO_Status_st lifo_make_empty(LIFO_Buf_st *lifo_buf)
{
	// Check parameters validity
	if(lifo_buf == NULL || lifo_buf->base == NULL || lifo_buf->head == NULL)
	{
		printf("LIFO make empty failed: NULL is passed\n");
		return LIFO_NULL;
	}

	// Reset the head and the number of items
	lifo_buf->head = lifo_buf->base;
	lifo_buf->items_count = 0;

	return LIFO_NO_ERROR;
}
