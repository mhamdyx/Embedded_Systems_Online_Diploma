/*
 * students_msys.h
 *
 *  Created on: Oct 29, 2021
 *      Author: MahmoudH
 */

#ifndef STUDENTS_MSYS_H_
#define STUDENTS_MSYS_H_

#include "students_fifo.h"

void students_msys_init(FIFO_Buf_st *students_queue, Item *item_buf, unsigned int buf_len);

void add_student_from_file(FIFO_Buf_st *students_queue);

void add_student_manually(FIFO_Buf_st *students_queue);

void find_student_by_roll(FIFO_Buf_st *students_queue);

void find_student_by_fname(FIFO_Buf_st *students_queue);

void find_student_by_course(FIFO_Buf_st *students_queue);

void print_students_count(FIFO_Buf_st *students_queue);

void delete_student_by_roll(FIFO_Buf_st *students_queue);

void update_student_by_roll(FIFO_Buf_st *students_queue);

void show_students_info(FIFO_Buf_st *students_queue);

#endif /* STUDENTS_MSYS_H_ */
