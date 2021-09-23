/*
 * linker_script.ld
 *
 *  Created on: Sep 16, 2021
 *      Author: MahmoudH
 */

MEMORY
{
    Flash (RX): ORIGIN = 0x00000000, LENGTH = 512M
    SRAM (RWX): ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata*)
        _E_text = .; /* End of .text section */
    } > Flash

    .data :
    {
        _S_data = .;
        *(.data*)
        . = ALIGN(4);
        _E_data = .;
    } > SRAM AT> Flash

    .bss :
    {
        _S_bss = .;
        *(.bss*)
        _E_bss = .;
    } > SRAM
}
