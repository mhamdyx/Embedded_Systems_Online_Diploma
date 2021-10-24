/*
 * startup.c
 *
 *  Created on: Sep 21, 2021
 *      Author: MahmoudH
 */

#include "Platform_Types.h"

extern uint32 _E_text; // End of text section
extern uint32 _S_data; // Start of data section
extern uint32 _E_data; // End of data section
extern uint32 _S_bss; // Start of bss section
extern uint32 _E_bss; // End of bss section
//extern uint32 _stack_top; // Top of the stack

extern int main(void);
void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak, alias("Default_Handler")));

static uint32 stack_top[256]; // 256 x 4 bytes = 1024

void (* const ptr_fn_vectors[])() __attribute__((section(".vectors"))) = 
{
    (void (*)()) ((uint32)stack_top + sizeof(stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler,
    &MM_Fault_Handler,
    &Bus_Fault_Handler,
    &Usage_Fault_Handler
};

void Default_Handler()
{
    Reset_Handler();
}

void Reset_Handler()
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
