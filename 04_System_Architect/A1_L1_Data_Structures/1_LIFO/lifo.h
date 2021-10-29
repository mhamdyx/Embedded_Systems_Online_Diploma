/*
 * lifo.h
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

#ifndef LIFO_H_
#define LIFO_H_

// Data type of buffer item
typedef unsigned char Item;

typedef struct
{
	unsigned int buf_len;
	Item *base;
	Item *head;
	unsigned int items_count;
} LIFO_Buf_st;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
} LIFO_Status_st;

// Initialize LIFO given an array buffer and a buffer length
LIFO_Status_st lifo_init(LIFO_Buf_st *lifo_buf, Item *item_buf, unsigned int buf_len);

// Push item in the LIFO given a data item
LIFO_Status_st lifo_push(LIFO_Buf_st *lifo_buf, Item item);

// Pop item from the LIFO given the address of the item holder
LIFO_Status_st lifo_pop(LIFO_Buf_st *lifo_buf, Item *item);

// Return the top of the LIFO without erasing it given the item holder
LIFO_Status_st lifo_top(LIFO_Buf_st *lifo_buf, Item *item);

// Print the LIFO buffer content
LIFO_Status_st lifo_print(LIFO_Buf_st *lifo_buf);

// Is the LIFO full?
LIFO_Status_st lifo_is_full(LIFO_Buf_st *lifo_buf);

// Is the LIFO empty?
LIFO_Status_st lifo_is_empty(LIFO_Buf_st *lifo_buf);

// Erase all data items inside the LIFO (Reset a LIFO buffer)
LIFO_Status_st lifo_make_empty(LIFO_Buf_st *lifo_buf);

#endif /* LIFO_H_ */
