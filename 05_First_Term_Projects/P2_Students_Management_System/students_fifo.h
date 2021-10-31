/*
 * students_fifo.h
 *
 *  Created on: Oct 29, 2021
 *      Author: MahmoudH
 */

#ifndef STUDENTS_FIFO_H_
#define STUDENTS_FIFO_H_

#define NAME_LEN 20
#define COURSES_NUM 5

// Student Structures
struct student_info
{
	char first_name[NAME_LEN];
	char last_name[NAME_LEN];
	int roll_num;
	float GPA;
	int course_id[COURSES_NUM];
};

// Data type of buffer item
typedef struct student_info Item;

typedef struct
{
	unsigned int buf_len;
	Item *base;
	Item *head;
	Item *tail;
	unsigned int items_count;
} FIFO_Buf_st;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
} FIFO_Status_st;

// Initialize FIFO given an array buffer and a buffer length
FIFO_Status_st fifo_init(FIFO_Buf_st *fifo_buf, Item *item_buf, unsigned int buf_len);

// Enqueue item in the FIFO given a data item
FIFO_Status_st fifo_enqueue(FIFO_Buf_st *fifo_buf, Item item);

// Dequeue item from the FIFO given the address of the item holder
FIFO_Status_st fifo_dequeue(FIFO_Buf_st *fifo_buf, Item *item);

// Print the FIFO buffer content
//FIFO_Status_st fifo_print(FIFO_Buf_st *fifo_buf);

// Is the FIFO full?
FIFO_Status_st fifo_is_full(FIFO_Buf_st *fifo_buf);

// Is the FIFO empty?
FIFO_Status_st fifo_is_empty(FIFO_Buf_st *fifo_buf);

// Erase all data items inside the FIFO (Reset a FIFO buffer)
FIFO_Status_st fifo_make_empty(FIFO_Buf_st *fifo_buf);

#endif /* STUDENTS_FIFO_H_ */
