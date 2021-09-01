/*
 * uart.c
 *
 *  Created on: Sep 1, 2021
 *      Author: MahmoudH
 */

#include "uart.h"
#define UART0DR (*(volatile unsigned int * const) 0x101f1000)

void uart_send_string(unsigned char *p_tx_string)
{
    while(*p_tx_string)
    {
        // Transmit char and increment string to next char
        UART0DR = (unsigned int)(*p_tx_string++);
    }
}
