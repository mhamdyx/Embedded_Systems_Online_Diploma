/*
 * EX1.c
 *
 *  Created on: Jan 29, 2021
 *      Author: MahmoudH
 */

/* Libraries */
#include <stdio.h>

/* Declarations */
struct student_s
{
	char name[50];
	unsigned int roll;
	float marks;
};

/* Function Prototypes */
struct student_s read_student_info(void);

void display_student_info(struct student_s student);

/* Main */
int main(void)
{
	struct student_s student;
    
	student = read_student_info();

	display_student_info(student);

	return 0;
}

struct student_s read_student_info(void)
{
	struct student_s student;

	printf("Enter information of students:\n\nEnter name: ");
	scanf("%s", student.name);

	printf("Enter roll number: ");
	scanf("%u", &student.roll);

	printf("Enter marks: ");
	scanf("%f", &student.marks);

	return student;
}

void display_student_info(struct student_s student)
{
	printf("\nDisplaying Information\n");
	printf("name: %s\nRoll: %u\nMarks: %.2f\n", student.name, student.roll, student.marks);
}
