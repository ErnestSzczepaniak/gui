.global __vector
.global __runtime

.section .vector

__vector:
	ldr pc,[pc,#28]
	ldr pc,[pc,#28]
	ldr	pc,[pc,#28]
	ldr pc,[pc,#28]
	ldr pc,[pc,#28]
	ldr pc,[pc,#28]
	ldr	pc,[pc,#28]
	ldr pc,[pc,#28]

.section .runtime

__runtime:
	.word __memory_sdram_size
	.word __handler_reset
	.word __handler_default
	.word __handler_default
	.word __handler_default
	.word __handler_default
	.word __handler_default
	.word __handler_default
	.word __handler_default

