ENTRY(Reset_Handler)

_estack = ORIGIN(SRAM) + LENGTH(SRAM);
_Min_Stack_Size = 0x400;/* from sysmem*/

MEMORY
{
  FLASH(rx):ORIGIN =0x08000000,LENGTH =64K
  SRAM(rwx):ORIGIN =0x20000000,LENGTH =20K
}

SECTIONS
{
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	}> FLASH

  .text :
  {
    _stext = .;
    *(.text)
    *(.rodata)
    . = ALIGN(4);
    _etext = .;
  }> FLASH
/* libgcc.a */
  .ARM : {
    . = ALIGN(4);
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
    . = ALIGN(4);
  } >FLASH


  _la_data = LOADADDR(.data);

  .data :
  {
    _sdata = .;

    *(.data)

    . = ALIGN(4);
    _edata = .;
  }> SRAM AT> FLASH
  
  .bss :
  {
    _sbss = .;

    *(.bss)
    
    . = ALIGN(4);
    _ebss = .;
    _end = _ebss;
  }> SRAM
}