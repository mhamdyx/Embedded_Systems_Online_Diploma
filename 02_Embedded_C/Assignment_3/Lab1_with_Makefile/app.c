/*
 * app.c
 *
 *  Created on: Sep 1, 2021
 *      Author: MahmoudH
 */

#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth: Mahmoud Hamdy";

int main(void)
{
    uart_send_string(string_buffer);
    while(1);
    return 0;
}