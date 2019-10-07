MEMORY
{
  	SDRAM (rwx) : ORIGIN = 0x0, LENGTH = __memory_sdram_size
}

ENTRY(__vector)

SECTIONS
{
	.text : ALIGN_WITH_INPUT
	{
		KEEP(*(.vector))
		KEEP(*(.runtime))

		*(.text*)

		KEEP(*(.init))
		KEEP(*(.fini))

		/* .ctors */
		*crtbegin.o(.ctors)
		*crtbegin?.o(.ctors)
		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
		*(SORT(.ctors.*))
		*(.ctors)

		/* .dtors */
 		*crtbegin.o(.dtors)
 		*crtbegin?.o(.dtors)
 		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
 		*(SORT(.dtors.*))
 		*(.dtors)

		*(.rodata*)

		KEEP(*(.eh_frame*))
	} > SDRAM

	.ARM.extab : ALIGN_WITH_INPUT
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > SDRAM

	__exidx_start = .;
	.ARM.exidx : ALIGN_WITH_INPUT
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > SDRAM
	__exidx_end = .;

	/* Location counter can end up 2byte aligned with narrow Thumb code but
	   __etext is assumed by startup code to be the LMA of a section in RAM
	   which must be 4byte aligned */
	. = ALIGN (4);
	__etext = .;

	.data :
	{
		__data_start__ = .;
		
		*(vtable)
		*(.data*)
	
		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);


		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		KEEP(*(.jcr*))
		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;

	} > SDRAM

	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > SDRAM

	end = .;
}
