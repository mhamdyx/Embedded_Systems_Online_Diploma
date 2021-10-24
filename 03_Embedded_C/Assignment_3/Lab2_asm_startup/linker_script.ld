/*
 * linker_script.ld
 *
 *  Created on: Sep 16, 2021
 *      Author: MahmoudH
 */

MEMORY
{
    Flash (RX): ORIGIN = 0x08000000, LENGTH = 128K
    SRAM (RWX): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
    } > Flash
    
    .bss :
    {
        *(.bss*)
    } > SRAM
}
