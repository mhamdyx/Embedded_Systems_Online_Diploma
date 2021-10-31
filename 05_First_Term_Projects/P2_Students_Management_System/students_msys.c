/*
 * students_msys.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MahmoudH
 */

#include "students_msys.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Students file
FILE *students_file;


// Private utilities declaration
static void print_student_info(struct student_info *student);

static void delete_student(FIFO_Buf_st *students_queue, struct student_info *student);

static struct student_info *search_student_by_roll(FIFO_Buf_st *students_queue, int roll);


// Public functions
void students_msys_init(FIFO_Buf_st *students_queue, Item *item_buf, unsigned int buf_len)
{
	if(fifo_init(students_queue, item_buf, buf_len) == FIFO_NULL)
	{
		printf("system initialization failed\n");
		exit(EXIT_FAILURE);
	}
}


void add_student_from_file(FIFO_Buf_st *students_queue)
{
	struct student_info new_student;
	int i;

	// Opening a file
	students_file = fopen("students.txt", "r");

	if(students_file == NULL)
	{
		printf("\n[ERROR] students.txt file in the directory is not found\n");
		printf("\n[ERROR] Adding students from file failed\n");
		return;
	}

	// Reading students one by one until end of file
	while(!feof(students_file))
	{
		fscanf(students_file, "%d", &new_student.roll_num);

		// Search if roll number exists
		if(search_student_by_roll(students_queue, new_student.roll_num) != NULL)
		{
			// Issue a justification for ignoring the current line
			printf("\n[ERROR] Roll number %d is already taken\n", new_student.roll_num);

			// Ignore the rest of the line
			fscanf(students_file, "%*[^\n]");
			continue;
		}

		// Otherwise, continue reading data
		fscanf(students_file, "%s", new_student.first_name);
		fscanf(students_file, "%s", new_student.last_name);
		fscanf(students_file, "%f", &new_student.GPA);

		for(i = 0; i < COURSES_NUM; i++)
		{
			fscanf(students_file, "%d", &new_student.course_id[i]);
		}

		// Enqueue new student
		if(fifo_enqueue(students_queue, new_student) == FIFO_NO_ERROR)
		{
			printf("\n[INFO] Roll number %d is saved successfully\n", new_student.roll_num);
		}
		else
		{
			printf("\n[ERROR] Adding students by file failed\n");
			return;
		}
	}

	printf("\n[INFO] Students details are saved successfully\n");


	// Closing a file
	fclose(students_file);
}


void add_student_manually(FIFO_Buf_st *students_queue)
{
	struct student_info new_student;
	int i;

	printf("Add the student details\n\n");
	printf("Enter the roll number: ");
	scanf("%d", &new_student.roll_num);

	// Search if roll number exists
	if(search_student_by_roll(students_queue, new_student.roll_num) != NULL)
	{
		// Report an error
		printf("\n[ERROR] Roll number %d is already taken\n", new_student.roll_num);
		printf("\n[ERROR] Adding students manually failed\n");
		return;
	}

	// otherwise, continue reading data
	printf("Enter the first name: ");
	scanf("%s", new_student.first_name);

	printf("Enter the last name: ");
	scanf("%s", new_student.last_name);

	printf("Enter the GPA obtained: ");
	scanf("%f", &new_student.GPA);

	printf("Enter the course ID for each course\n");
	for(i = 0; i < COURSES_NUM; i++)
	{
		printf("Course %d id: ", i + 1);
		scanf("%d", &new_student.course_id[i]);
	}

	// Enqueue new student
	if(fifo_enqueue(students_queue, new_student) == FIFO_NO_ERROR)
	{
		printf("\n[INFO] Student details are added successfully\n");
	}
	else
	{
		printf("\n[ERROR] Adding students manually failed\n");
	}
}


void find_student_by_roll(FIFO_Buf_st *students_queue)
{
	int input_roll;
	struct student_info *student;
	FIFO_Status_st queue_status;

	// Enter your search key: the roll number
	printf("Enter the student roll number: ");
	scanf("%d", &input_roll);

	// Check if students queue is not empty
	queue_status = fifo_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Searching student by roll failed\n");
		return;
	}

	// Traverse the queue to search for student
	student = search_student_by_roll(students_queue, input_roll);


	// If roll is not found
	if(student == NULL)
	{
		printf("\n[ERROR] Roll number %d is not found\n", input_roll);
		//return;
	}
	else
	{
		// If the roll is found, print the student details
		print_student_info(student);
	}
}


void find_student_by_fname(FIFO_Buf_st *students_queue)
{
	char input_fname[NAME_LEN];
	struct student_info *student;
	FIFO_Status_st queue_status;
	int i, match_found = 0;

	// Enter your search key: the first name
	printf("Enter the student first name: ");
	scanf("%s", input_fname);

	// Check if students queue is not empty
	queue_status = fifo_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Searching student by first name failed\n");
		return;
	}

	// Traverse the queue to search for matching students
	student = students_queue->tail;
	for(i = 0; i < students_queue->items_count; i++)
	{
		// Student is found
		if(!strcmp(student->first_name, input_fname))
		{
			match_found = 1;
			print_student_info(student);
		}

		// Check if we reach the buffer boundaries
		if((student + 1) == (students_queue->base + students_queue->buf_len))
		{
			student = students_queue->base; // Reset pointer to the base
		}
		else
		{
			student++;
		}
	}

	// If first name is not found
	if(!match_found)
	{
		printf("\n[ERROR] First name %s is not found\n", input_fname);
	}
}


void find_student_by_course(FIFO_Buf_st *students_queue)
{
	int input_course_id, i, j, enrolled_count = 0;
	struct student_info *student;
	FIFO_Status_st queue_status;


	// Enter your search key: the course id
	printf("Enter the course id: ");
	scanf("%d", &input_course_id);

	// Check if students queue is not empty
	queue_status = fifo_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Searching student by course id failed\n");
		return;
	}

	// Traverse the queue to search for matching students
	student = students_queue->tail;
	for(i = 0; i < students_queue->items_count; i++)
	{

		for(j = 0; j < COURSES_NUM; j++)
		{
			// Student is found
			if(student->course_id[j] == input_course_id)
			{
				enrolled_count++;
				print_student_info(student);
				printf("\n"); // Take a line break
				break;
			}
		}

		// Check if we reach the buffer boundaries
		if((student + 1) == (students_queue->base + students_queue->buf_len))
		{
			student = students_queue->base; // Reset pointer to the base
		}
		else
		{
			student++;
		}
	}

	// If course id is not found in any student
	if(enrolled_count == 0)
	{
		printf("\n[ERROR] Course id %d is not found\n", input_course_id);
	}
	else
	{
		printf("\n[INFO] Total number of students enrolled: %d\n", enrolled_count);
	}
}


void print_students_count(FIFO_Buf_st *students_queue)
{
	unsigned int count = students_queue->items_count;
	unsigned int capacity = students_queue->buf_len;
	printf("[INFO] Total number of students is %u\n", count);
	printf("[INFO] You can add up to %u students\n", capacity);
	printf("[INFO] You can add %u more students\n", capacity - count);
}


void delete_student_by_roll(FIFO_Buf_st *students_queue)
{
	int input_roll;
	struct student_info *student;
	FIFO_Status_st queue_status;

	// Enter your search key: the roll number
	printf("Enter the roll number which you want to delete: ");
	scanf("%d", &input_roll);

	// Check if students queue is not empty
	queue_status = fifo_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Update student by roll failed\n");
		return;
	}

	// Traverse the queue to search for student
	student = search_student_by_roll(students_queue, input_roll);

	// Make sure a student is found
	if(student == NULL)
	{
		printf("\n[ERROR] Student with this roll is not found\n");
		return;
	}

	// Deleting student
	delete_student(students_queue, student);
	printf("\n[INFO] The roll number is removed successfully\n");
}


void update_student_by_roll(FIFO_Buf_st *students_queue)
{
	int input_roll, update_option;
	struct student_info *student;
	FIFO_Status_st queue_status;

	// Enter your search key: the roll number
	printf("Enter the roll number to update the entry: ");
	scanf("%d", &input_roll);

	// Check if students queue is not empty
	queue_status = fifo_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Update student by roll failed\n");
		return;
	}

	// Traverse the queue to search for student
	student = search_student_by_roll(students_queue, input_roll);

	// Make sure a student is found
	if(student == NULL)
	{
		printf("\n[ERROR] Student with this roll is not found\n");
		return;
	}

	printf("Enter the update option\n");
	printf("1. First name\n2. Last name\n3. Roll no.\n4. GPA\n5. Courses\n");
	scanf("%d", &update_option);

	switch(update_option)
	{
	case 1:
		printf("Enter the new first name: ");
		scanf("%s", student->first_name);
		printf("\n[INFO] UPDATED SUCCESSFULLY\n");
		break;
	case 2:
		printf("Enter the new last name: ");
		scanf("%s", student->last_name);
		printf("\n[INFO] UPDATED SUCCESSFULLY\n");
		break;
	case 3:
		printf("Enter the new roll number: ");
		scanf("%d", &input_roll);
		if(search_student_by_roll(students_queue, input_roll) == NULL)
		{
			student->roll_num = input_roll;
			printf("\n[INFO] UPDATED SUCCESSFULLY\n");
		}
		else
		{
			printf("\n[ERROR] UPDATE FAILED: Roll already exists or same roll is chosen\n");
		}
		break;
	case 4:
		printf("Enter the new GPA: ");
		scanf("%f", &student->GPA);
		printf("\n[INFO] UPDATED SUCCESSFULLY\n");
		break;
	case 5:
		printf("Enter the course number from %d to %d: ", 1, COURSES_NUM);
		scanf("%d", &update_option);
		printf("Enter the new course id: ");
		scanf("%d", &student->course_id[update_option - 1]);
		printf("\n[INFO] UPDATED SUCCESSFULLY\n");
		break;
	default:
		break;
	}
}


void show_students_info(FIFO_Buf_st *students_queue)
{
	struct student_info *student;
	int i;
	FIFO_Status_st queue_status;

	// Checking if the database is empty
	queue_status = fifo_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] show students info failed\n");
		return;
	}

	printf("Students full database\n\n");

	// Traverse the queue to print the info for each student
	student = students_queue->tail;
	for(i = 0; i < students_queue->items_count; i++)
	{
		print_student_info(student);
		printf("\n"); // Take a line break

		// Check if we reach the buffer boundaries
		if((student + 1) == (students_queue->base + students_queue->buf_len))
		{
			student = students_queue->base; // Reset pointer to the base
		}
		else
		{
			student++;
		}
	}
}


static void print_student_info(struct student_info *student)
{
	int i;

	printf("The student details are\n");
	printf("First name is %s\n", student->first_name);
	printf("Last name is %s\n", student->last_name);
	printf("Roll number is %d\n", student->roll_num);
	printf("GPA is %f\n", student->GPA);
	printf("Courses IDs are\n");

	for(i = 0; i < COURSES_NUM; i++)
	{
		printf("Course %d id: %d\n", i + 1, student->course_id[i]);
	}
}


static void delete_student(FIFO_Buf_st *students_queue, struct student_info *student)
{
	while(student != students_queue->tail)
	{
		// Check if we reach the buffer boundaries
		if(student == students_queue->base)
		{
			*student = *(students_queue->head - 1);
			student = students_queue->head - 1;

		}
		else
		{
			*student = *(student - 1);
			student--;
		}
	}

	if(student == students_queue->tail)
	{
		// Check if we reach the buffer boundaries
		if((student + 1) == (students_queue->base + students_queue->buf_len))
		{
			students_queue->tail = students_queue->base; // Reset pointer to the base
		}
		else
		{
			students_queue->tail++;
		}
	}

	// Update count
	students_queue->items_count--;
}


static struct student_info *search_student_by_roll(FIFO_Buf_st *students_queue, int roll)
{
	int i;
	struct student_info *student = students_queue->tail;

	for(i = 0; i < students_queue->items_count; i++)
	{
		if(student->roll_num == roll)
		{
			break;
		}

		// Check if we reach the buffer boundaries
		if((student + 1) == (students_queue->base + students_queue->buf_len))
		{
			student = students_queue->base; // Reset pointer to the base
		}
		else
		{
			student++;
		}
	}

	if(i == students_queue->items_count)
	{
		student = NULL;
	}

	return student;
}

