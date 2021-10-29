/*
 * Students_DB.c
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

#include "Students_DB.h"
#include <stdio.h>
#include <stdlib.h>

struct student_node *student_list = NULL;

void fill_the_record(struct student_data *new_student)
{
	printf("Enter student ID: ");
	scanf("%d", &(new_student->ID));
	getchar(); // skip end line

	printf("Enter student name: ");
	gets(new_student->name);

	printf("Enter student height: ");
	scanf("%f", &(new_student->height));
}

void list_add_student(void)
{
	// Create new student dynamically
	struct student_node *new_student = malloc(sizeof(struct student_node));
	struct student_node *temp_student;

	// Check for invalid allocation
	if(new_student == NULL)
	{
		printf("Error: Can't create new student\n");
		return;
	}

	// Initialize the student data
	fill_the_record(&(new_student->student));

	new_student->next = NULL;

	// Check if the list is empty or not
	if(list_is_empty())
	{
		student_list = new_student;
	}
	else
	{
		// Traverse to the last node of the list
		for(temp_student = student_list; temp_student->next != NULL; temp_student = temp_student->next);
		temp_student->next = new_student;
	}
}

void list_delete_student(void)
{
	int ID;
	struct student_node *curr_student = student_list, *prev_student = NULL;

	printf("Enter student ID to be deleted: ");
	scanf("%d", &ID);

	// Traverse until stop at the end or at a valid ID
	for(; (curr_student != NULL) && (curr_student->student.ID != ID);
			prev_student = curr_student, curr_student = curr_student->next);

	if(curr_student == NULL) // ID is not found
	{
		printf("ID is not found\n");
		return;
	}

	if(prev_student == NULL) // ID of first node
	{
		student_list = student_list->next;
	}
	else // ID of otherwise node
	{
		prev_student->next = curr_student->next;
	}

	// Delete the dynamic data
	free(curr_student);

	printf("Student whose ID is %d is deleted\n", ID);
}

void list_view_students(void)
{
	int count = 0;
	struct student_node *curr_student;

	// Make sure the database is not empty
	if(list_is_empty())
	{
		printf("Can't view student: Database is empty\n");
		return;
	}

	// Print the database
	printf("Students Database:\n\n");
	for(curr_student = student_list; curr_student != NULL; curr_student = curr_student->next)
	{
		printf("Record Number %d:\n", ++count);
		list_print_student(curr_student);
	}
}

void list_delete_all(void)
{
	struct student_node *curr_student;

	// Make sure the database is not empty
	if(list_is_empty())
	{
		printf("Can't delete database as it's already empty\n");
		return;
	}

	// Traverse the whole list and delete one by one
	do
	{
		curr_student = student_list;
		student_list = student_list->next;
		free(curr_student);
	} while(student_list != NULL);
}


int list_is_empty(void)
{
	return (student_list == NULL); // Check the head
}

struct student_node *list_get_nth_student(int n)
{
	struct student_node *curr_student;
	int i;

	// Make sure the list is not empty
	if(list_is_empty())
	{
		printf("Can't find nth student: Database is empty\n");
		return NULL;
	}

	// Traverse to the index or to the end of the list
	curr_student = student_list;
	for(i = 0; (i < n) && (curr_student != NULL); i++, curr_student = curr_student->next);

	return curr_student;
}


int list_students_count_iterative(void)
{
	int count = 0;
	struct student_node *curr_student = student_list;

	// Traverse the whole list
	for(; curr_student != NULL; curr_student = curr_student->next, count++);

	return count;
}

int list_students_count_recursive(struct student_node *list)
{
	if(list == NULL)
	{
		return 0;
	}

	return 1 + list_students_count_recursive(list->next);
}

struct student_node *list_get_nth_student_from_end(int n)
{
	struct student_node *main_node, *ref_node;

	// Make sure the list is not empty
	if(list_is_empty())
	{
		printf("Can't find nth student from end: Database is empty\n");
		return NULL;
	}

	// Initialize main node by the beginning of the list
	main_node = student_list;

	// Move reference node by the desired offset from main node
	for(ref_node = student_list; n--; ref_node = ref_node->next)
	{
		// Defensive programming to avoid runtime errors
		if(ref_node == NULL)
		{
			printf("list get nth student from end failed\n");
			return NULL;
		}
	}

	// Traverse main node and reference node relatively one by one
	for(; ref_node != NULL; main_node = main_node->next, ref_node = ref_node->next);

	// return the desired node
	return main_node;
}

struct student_node *list_get_middle_student(void)
{
	struct student_node *middle_student;
	int students_count;

	// Make sure the list is not empty
	if(list_is_empty())
	{
		printf("Can't find nth student from end: Database is empty\n");
		return NULL;
	}

	// Count nodes
	students_count = list_students_count_iterative();

	// Get the desired indexed node
	middle_student = list_get_nth_student(students_count / 2);

	return middle_student;
}

void list_reverse_students(void)
{
	struct student_node *prev_student, *curr_student, *next_student;

	// Make sure the list is not empty
	if(list_is_empty())
	{
		printf("Can't reverse an empty Database\n");
		return;
	}

	prev_student = NULL;
	curr_student = student_list;

	while(curr_student != NULL)
	{
		next_student = curr_student->next;
		curr_student->next = prev_student;
		prev_student = curr_student;
		curr_student = next_student;
	}

	student_list = prev_student;
}

void list_print_student(struct student_node *student)
{
	// Defensive programming to avoid runtime errors
	if(student == NULL)
	{
		printf("Trying to print NULL student\n");
		return;
	}

	printf("ID: %d\n", student->student.ID);
	printf("Name: %s\n", student->student.name);
	printf("Height: %f\n\n", student->student.height);
}
