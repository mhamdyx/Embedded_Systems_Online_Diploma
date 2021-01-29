/*
 * EX6.c
 *
 *  Created on: Jan 29, 2021
 *      Author: MahmoudH
 */

/* Libraries */
#include <stdio.h>

/* Global Variables */
union job
{
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1
{
	char name[32];
	float salary;
	int worker_no;
}s;

/* Main Program */
int main(void)
{
	printf("size of union = %d\n", sizeof(u)); /* 32 */
	printf("size of structure = %d\n", sizeof(s)); /* 40 */
    
	return 0;
}
