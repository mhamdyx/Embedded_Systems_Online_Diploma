/*
 * EX5.c
 *
 *  Created on: Feb 13, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>

/* Structure */
struct employee
{
	char name[30];
	int ID;
};

int main(void)
{
    /* structure employee variables */
	struct employee emp1 = {"Alex", 1002}, emp2 = {"Kero", 1003};
	
    /* Array of pointers to structure employee */
    struct employee *company[2];

    /* Pointer to array of size 2 of each of type pointer to structure employee */
	struct employee *(*ptr_arr)[2] = &company;

	company[0] = &emp1;
	company[1] = &emp2;

	/* Dereferencing the first element in the array through the pointer to the array */
    printf("Employee Name : %s\n", ((*ptr_arr)[0])->name);
	printf("Employee ID : %d\n", ((*ptr_arr)[0])->ID);

    /* or
	printf("Employee Name : %s\n", (**(*ptr_arr)).name);
	printf("Employee ID : %d\n", (**(*ptr_arr)).ID);
	*/

	return 0;
}
