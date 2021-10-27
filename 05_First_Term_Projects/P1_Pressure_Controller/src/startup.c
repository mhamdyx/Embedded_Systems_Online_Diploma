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
    // Line 30: Misra violation 11.4 (Advisory)
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
    // Line 46: Misra Violation 12.3 (Advisory)
    uint32 _data_size, _bss_size, i;
    
    //Line 49: Misra Violation 12.3 (Advisory)
    uint8 *_src_ptr, *_dst_ptr;

    // Copy data from ROM to RAM
    // Line 53: Misra Violation 18.4 (Advisory)
    _data_size = (uint8 *)&_E_data - (uint8 *)&_S_data;
    _src_ptr = (uint8 *)&_E_text;
    _dst_ptr = (uint8 *)&_S_data;

    for(i = 0; i < _data_size; i++)
    {
        // Line 60: Misra Violation 13.3 (Advisory)
        *_dst_ptr++ = *_src_ptr++;
    }

    // Initialize bss section
    // Line 65: Misra Violation 18.4 (Advisory)
    _bss_size = (uint8 *)&_E_bss - (uint8 *)&_S_bss;
    _dst_ptr = (uint8 *)&_S_bss;
    
    for(i = 0; i < _bss_size; i++)
    {
        // Line 71: Misra Violation 13.3 (Advisory)
        *_dst_ptr++ = 0;
    }

    // Branch to main.
    // Removing (void) will cause Misra Violation 17.7 (Required)
    (void)main();
}
