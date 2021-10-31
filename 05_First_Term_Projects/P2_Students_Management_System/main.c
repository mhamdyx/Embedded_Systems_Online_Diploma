/*
 * main.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>
#include "students_msys.h"
#include "students_fifo.h"

#define STUDENTS_NUM 50

#define I_LOVE_ECLIPSE() \
setvbuf(stdout, NULL, _IONBF, 0);\
setvbuf(stderr, NULL, _IONBF, 0)


int main(void)
{
	int option;
	FIFO_Buf_st students_queue;
	struct student_info students_buffer[STUDENTS_NUM];

	// Eclipse workaround for I/O problems
	I_LOVE_ECLIPSE();

	// System initialization
	students_msys_init(&students_queue, students_buffer, STUDENTS_NUM);

	// User interface
	printf("Welcome to the Student Management System\n\n");

	while(1)
	{
		printf("==============================\n");
		printf("Choose the task that you want to perform\n");
		printf("1.  Add the student details manually\n");
		printf("2.  Add the student details from text file\n");
		printf("3.  Find the student details by roll number\n");
		printf("4.  Find the student details by first name\n");
		printf("5.  Find the student details by course id\n");
		printf("6.  Find the total number of students\n");
		printf("7.  Delete the student details by roll number\n");
		printf("8.  Update the student details by roll number\n");
		printf("9.  Show all information\n");
		printf("10. Exit\n");

		printf("\nEnter option number: ");
		scanf("%d", &option);
		printf("\n==============================\n");

		switch(option)
		{
		case 1: add_student_manually(&students_queue); break;
		case 2: add_student_from_file(&students_queue); break;
		case 3: find_student_by_roll(&students_queue); break;
		case 4: find_student_by_fname(&students_queue); break;
		case 5: find_student_by_course(&students_queue); break;
		case 6: print_students_count(&students_queue); break;
		case 7: delete_student_by_roll(&students_queue); break;
		case 8: update_student_by_roll(&students_queue); break;
		case 9: show_students_info(&students_queue); break;
		case 10: return 0;
		default: printf("[ERROR] Invalid Option! Try again\n"); break;
		}
		printf("\n"); // Line break
	}

	return 0;
}
