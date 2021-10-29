/*
 * main.c
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>
#include "Students_DB.h"

#define I_LOVE_ECLIPSE() \
setvbuf(stdout, NULL, _IONBF, 0);\
setvbuf(stderr, NULL, _IONBF, 0)

int main(void)
{
	I_LOVE_ECLIPSE();
	int command, n;

	while(1)
	{
		printf("==============================\n");
		printf("Choose one of the following options:\n");
		printf("1: Add Atudent\n");
		printf("2: Delete Student\n");
		printf("3: View Students\n");
		printf("4: Delete All\n");
		printf("5: Get nth student\n");
		printf("6: Get middle student\n");
		printf("7: Get the number of students\n");
		printf("8: Get nth student from the end\n");
		printf("9: Reverse students database\n");
		printf("10: Exit\n");

		printf("\nEnter option number: ");
		scanf("%d", &command);
		printf("\n==============================\n");

		switch(command)
		{
		case 1: list_add_student(); break;
		case 2: list_delete_student(); break;
		case 3: list_view_students(); break;
		case 4: list_delete_all(); break;
		case 5:
			printf("Enter the student zero-based index: ");
			scanf("%d", &n);
			list_print_student(list_get_nth_student(n));
			break;
		case 6:
			printf("Middle student data:\n");
			list_print_student(list_get_middle_student());
			break;
		case 7:
			printf("Number of students is: ");
			printf("%d\n", list_students_count_iterative());
			break;
		case 8:
			printf("Enter the number from the end: ");
			scanf("%d", &n);
			list_print_student(list_get_nth_student_from_end(n));
			break;
		case 9: list_reverse_students(); break;
		case 10: return 0;
		default: printf("Invalid Option! Try again\n\n");
		}
	}

	printf("Hello, Students Database\n");
	return 0;
}
