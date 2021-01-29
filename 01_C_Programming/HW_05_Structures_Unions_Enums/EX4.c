/*
 * EX4.c
 *
 *  Created on: Jan 29, 2021
 *      Author: MahmoudH
 */

/* Libraries */
#include <stdio.h>

/* Macros */
#define DB_SIZE 10

/* Declarations */
struct student_s
{
	char name[50];
	unsigned int roll;
	unsigned int  marks;
};

/* Function Prototypes */
struct student_s read_student_info(unsigned int roll);

void display_student_info(struct student_s student);

/* Main Program */
int main(void)
{
	struct student_s student_DB[DB_SIZE];
	int i;

	printf("Enter information of students:\n");
	for(i = 0; i < DB_SIZE; i++)
	{
		student_DB[i] = read_student_info(i + 1);
	}


	printf("\nDisplay information of students:\n");
	for(i = 0; i < DB_SIZE; i++)
	{
		display_student_info(student_DB[i]);
	}

	return 0;
}

/* Function Definitions */
struct student_s read_student_info(unsigned int roll)
{
	struct student_s student;
	student.roll = roll;

	printf("\nFor roll number %u\n", student.roll);
	printf("Enter name: ");
	scanf("%s", student.name);

	printf("Enter marks: ");
	scanf("%u", &student.marks);

	return student;
}

void display_student_info(struct student_s student)
{
	printf("\nInformation for roll number %u\n", student.roll);
	printf("Name: %s\nMarks: %u\n", student.name, student.marks);
}
