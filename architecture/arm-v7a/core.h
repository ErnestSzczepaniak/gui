#ifndef _lib_os_core_h
#define _lib_os_core_h

#include "interrupt_interface.h"
#include "timer_global.h"
#include "timer_private.h"
#include "timer_watchdog.h"
#include "interrupt_distributor.h"

extern void * __runtime;

enum class Core_mode
{
	USER = 0x10,
	FIQ = 0x11,
	IRQ = 0x12,
	SVC = 0x13,
	ABORT = 0x17,
	UNDEFINED = 0x1b,
	SYSTEM = 0x1f
};

enum class Core_runtime
{
	STACK_POINTER = 0,
	HANDLER_RESET,
	HANDLER_UNDEFINED,
	HANDLER_SVC,
	HANDLER_PREFETCH_ABORT,
	HANDLER_DATA_ABORT,
	HANDLER_RESERVED,
	HANDLER_IRQ,
	HANDLER_FIQ
};

enum class Core_interrupt
{
	IMPRECISE_ABORT,
	INTERRUPT,
	FAST_INTERRUPT
};

class Core
{
public:
	Core();
	~Core();

	int index();
	Core_mode mode();

	void interrupt_mask(Core_interrupt interrupt);
	void interrupt_unmask(Core_interrupt interrupt);

    void interrupt_vector_base(unsigned int address);
    unsigned int interrupt_vector_base();

    template<typename T>
    void runtime(Core_runtime element, T callback);
    unsigned int runtime(Core_runtime element);

	void call_supervisor(void * request, int opcode);

	void wakeup(int cpu_index);

	void stack_pointer_mode(Core_mode mode, void * value);
    void * stack_pointer_mode(Core_mode mode);

	unsigned int private_base();

	Interrupt_interface interrupt_interface;
	Timer_global timer_global;
	Timer_private timer_private;
	Timer_watchdog timer_watchdog;
	Interrupt_distributor interrupt_distributor;
};

template<typename T>
void Core::runtime(Core_runtime element, T value)
{
	auto * ptr = (unsigned int *) &__runtime;
	*(ptr + (unsigned int) element) = (unsigned int) value;
}

#endif
