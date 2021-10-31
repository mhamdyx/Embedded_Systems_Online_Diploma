/*
 * students_fifo.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MahmoudH
 */

#include "students_fifo.h"
#include <stdio.h>

// Initialize FIFO given an array buffer and a buffer length
FIFO_Status_st fifo_init(FIFO_Buf_st *fifo_buf, Item *item_buf, unsigned int buf_len)
{
	// Check parameters validity
	if(fifo_buf == NULL || item_buf == NULL || buf_len == 0)
	{
		printf("FIFO initialization failed: NULL pointer or zero length is passed\n");
		return FIFO_NULL;
	}

	fifo_buf->base = item_buf;
	fifo_buf->head = fifo_buf->base;
	fifo_buf->tail = fifo_buf->base;
	fifo_buf->buf_len = buf_len;
	fifo_buf->items_count = 0;

	return FIFO_NO_ERROR;
}


// Enqueue item in the FIFO given a data item
FIFO_Status_st fifo_enqueue(FIFO_Buf_st *fifo_buf, Item item)
{
	// Check parameters validity
	if(fifo_buf == NULL || fifo_buf->base == NULL || fifo_buf->head == NULL || fifo_buf->tail == NULL)
	{
		printf("FIFO enqueue failed: NULL is passed\n");
		return FIFO_NULL;
	}

	// Check overflow
	if(fifo_is_full(fifo_buf) == FIFO_FULL)
	{
		printf("FIFO enqueue failed: FIFO is full\n");
		return FIFO_FULL;
	}

	// enqueue new item
	*(fifo_buf->head) = item;
	if((fifo_buf->head + 1) == (fifo_buf->base + fifo_buf->buf_len))
	{
		fifo_buf->head = fifo_buf->base;
	}
	else
	{
		fifo_buf->head++;
	}

	fifo_buf->items_count++;

	return FIFO_NO_ERROR;
}


// Dequeue item from the FIFO given the address of the item holder
FIFO_Status_st fifo_dequeue(FIFO_Buf_st *fifo_buf, Item *item)
{
	// Check parameters validity
	if(fifo_buf == NULL || fifo_buf->base == NULL || fifo_buf->head == NULL || fifo_buf->tail == NULL || item == NULL)
	{
		printf("FIFO dequeue failed: NULL is passed\n");
		return FIFO_NULL;
	}

	// Check underflow
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		printf("FIFO dequeue failed: FIFO is empty\n");
		return FIFO_EMPTY;
	}

	// Dequeue the top item
	*item = *(fifo_buf->tail);
	if((fifo_buf->tail + 1) == (fifo_buf->base + fifo_buf->buf_len))
	{
		fifo_buf->tail = fifo_buf->base;
	}
	else
	{
		fifo_buf->tail++;
	}

	fifo_buf->items_count--;

	return FIFO_NO_ERROR;
}


// Is the FIFO full?
FIFO_Status_st fifo_is_full(FIFO_Buf_st *fifo_buf)
{
	// Check parameters validity
	if(fifo_buf == NULL || fifo_buf->base == NULL || fifo_buf->head == NULL || fifo_buf->tail == NULL)
	{
		printf("FIFO is full failed: NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the number of items matches the total buffer length
	if(fifo_buf->items_count == fifo_buf->buf_len)
	{
		return FIFO_FULL;
	}

	return FIFO_NOT_FULL;
}


// Is the FIFO empty?
FIFO_Status_st fifo_is_empty(FIFO_Buf_st *fifo_buf)
{
	// Check parameters validity
	if(fifo_buf == NULL || fifo_buf->base == NULL || fifo_buf->head == NULL || fifo_buf->tail == NULL)
	{
		printf("FIFO is empty failed: NULL is passed\n");
		return FIFO_NULL;
	}

	// Check if the number of items is zero
	if(fifo_buf->items_count == 0)
	{
		return FIFO_EMPTY;
	}

	return FIFO_NOT_EMPTY;
}


// Erase all data items inside the FIFO (Reset a FIFO buffer)
FIFO_Status_st fifo_make_empty(FIFO_Buf_st *fifo_buf)
{
	// Check parameters validity
	if(fifo_buf == NULL || fifo_buf->base == NULL || fifo_buf->head == NULL || fifo_buf->tail == NULL)
	{
		printf("FIFO make empty failed: NULL is passed\n");
		return FIFO_NULL;
	}

	// Reset the head, the tail, and the number of items
	fifo_buf->head = fifo_buf->base;
	fifo_buf->tail = fifo_buf->base;
	fifo_buf->items_count = 0;

	return FIFO_NO_ERROR;
}

