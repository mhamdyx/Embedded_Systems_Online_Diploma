/*
 * Students_DB.h
 *
 *  Created on: Oct 28, 2021
 *      Author: MahmoudH
 */

#ifndef STUDENTS_DB_H_
#define STUDENTS_DB_H_

#define NAME_LEN 30

struct student_data
{
	int ID;
	char name[NAME_LEN + 1];
	float height;
};

struct student_node
{
	struct student_data student;
	struct student_node *next;
};

// Fill the student's record
void fill_the_record(struct student_data *new_student);

// Add a student to the list
void list_add_student(void);

// Delete a student from the list
void list_delete_student(void);

// Print all students in the list
void list_view_students(void);

// Delete all students from the list
void list_delete_all(void);

// Is the list empty?
int list_is_empty(void);

// Get a student node from the list given a zero-based index
struct student_node *list_get_nth_student(int n);

// Get the list length using iteration (looping)
int list_students_count_iterative(void);

// Get the list length using recursion
int list_students_count_recursive(struct student_node *list);

// Get a student node from the list given its number from the end
struct student_node *list_get_nth_student_from_end(int n);

// Get a student node in the middle of the list
struct student_node *list_get_middle_student(void);

// Reverse the arrangement of the list
void list_reverse_students(void);

// Print each student data item
void list_print_student(struct student_node *student);

#endif /* STUDENTS_DB_H_ */
