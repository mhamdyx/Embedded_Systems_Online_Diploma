/*
 * main.c
 *
 *  Created on: Mar 12, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>
#include "can.h"

int main(void)
{
    can_init();
    printf("Library is linked successfully\n");
    return 0;
}