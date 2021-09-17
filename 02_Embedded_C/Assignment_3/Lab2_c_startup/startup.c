/*
 * startup.c
 *
 *  Created on: Sep 17, 2021
 *      Author: MahmoudH
 */

#include "Platform_Types.h"

// Macros
#define STACK_START_SP 0x20001000

extern uint32 _E_text; // End of text section
extern uint32 _S_data; // Start of data section
extern uint32 _E_data; // End of data section
extern uint32 _S_bss; // Start of bss section
extern uint32 _E_bss; // End of bss section
extern uint32 _stack_top; // Top of the stack

extern int main(void);
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32 vectors[] __attribute__((section(".vectors"))) = 
{
    (uint32) &_stack_top,
    (uint32) &Reset_Handler,
    (uint32) &NMI_Handler,
    (uint32) &H_Fault_Handler,
    (uint32) &MM_Fault_Handler,
    (uint32) &Bus_Fault_Handler,
    (uint32) &Usage_Fault_Handler
};

void Default_Handler(void)
{
    Reset_Handler();
}

void Reset_Handler(void)
{
    uint32 _data_size, _bss_size, i;
    uint8 *_src_ptr, *_dst_ptr;

    // Copy data from ROM to RAM
    _data_size = (uint8 *)&_E_data - (uint8 *)&_S_data;
    _src_ptr = (uint8 *)&_E_text;
    _dst_ptr = (uint8 *)&_S_data;

    for(i = 0; i < _data_size; i++)
    {
        *_dst_ptr++ = *_src_ptr++;
    }

    // Initialize bss section
    _bss_size = (uint8 *)&_E_bss - (uint8 *)&_S_bss;
    _dst_ptr = (uint8 *)&_S_bss;
    
    for(i = 0; i < _bss_size; i++)
    {
        *_dst_ptr++ = 0;
    }

    // Branch to main
    main();
}
