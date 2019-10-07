.global __handler_reset
.global __handler_default
.global __dso_handle
.global __aeabi_atexit

.text

.macro call_array start, end
	ldr r4, =\start
	ldr r5, =\end
1:
	cmp r4, r5
	ldmltia r4!, {r6}
	blxlt r6
	cmp r4, r5
	blt 1b
.endm

__handler_reset:
	cps #0x1f

	ldr r0, =__runtime
	ldr r0, [r0]
	mov sp, r0

	mrc p15, 0, r0, c0, c0, 5
	ubfx r0, r0, #0, #5
	cmp r0, #0

	bne main

	ldr r0, =__bss_start__
	ldr r1, =__bss_end__
	mov r2, #0
1:
	cmp r0, r1
	stmltia r0!, {r2}
	blt 1b

	call_array __preinit_array_start __preinit_array_end
	call_array __init_array_start __init_array_end

	b main

__handler_default:
	b .

__aeabi_atexit:
	bx lr

__dso_handle:

