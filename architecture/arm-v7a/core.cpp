#include "core.h"

extern "C" unsigned int c_cp15_c0_tlbtr_get();
extern "C" unsigned int c_cp15_c0_mpidr_get();
extern "C" unsigned int c_cp15_c1_sctlr_get();
extern "C" void c_cp15_c1_sctlr_set(unsigned int value);
extern "C" unsigned int c_cp15_c1_actlr_get();
extern "C" void c_cp15_c1_actlr_set(unsigned int value);
extern "C" unsigned int c_cp15_c12_vbar_get();
extern "C" void c_cp15_c12_vbar_set(unsigned int value);
extern "C" unsigned int c_cp15_c15_cbar_get();
extern "C" void c_cp15_c15_cbar_set(unsigned int value);
extern "C" unsigned int c_cpsr_get();
extern "C" unsigned int c_spsr_get();

extern "C" unsigned int c_sp_get();
extern "C" void c_sp_set(unsigned int value);

extern "C" void * c_sp_user_get();
extern "C" void c_sp_user_set(void * value);
extern "C" void * c_sp_fiq_get();
extern "C" void c_sp_fiq_set(void * value);
extern "C" void * c_sp_irq_get();
extern "C" void c_sp_irq_set(void * value);
extern "C" void * c_sp_svc_get();
extern "C" void c_sp_svc_set(void * value);
extern "C" void * c_sp_abort_get();
extern "C" void c_sp_abort_set(void * value);
extern "C" void * c_sp_undefined_get();
extern "C" void c_sp_undefined_set(void * value);
extern "C" void * c_sp_system_get();
extern "C" void c_sp_system_set(void * value);

extern "C" void c_wfe();
extern "C" void c_wfi();
extern "C" void c_dsb();
extern "C" void c_isb();
extern "C" void c_dmb();
extern "C" void c_sev();
extern "C" void c_svc(void * request, int opcode);
extern "C" void c_lock(void * value);
extern "C" void c_unlock(void * value);
extern "C" void c_run(void * sp);

extern "C" void c_cpsie_i();
extern "C" void c_cpsid_i();
extern "C" void c_cpsie_f();
extern "C" void c_cpsid_f();
extern "C" void c_cpsie_a();
extern "C" void c_cpsid_a();

Core::Core()
:
interrupt_interface(private_base() + 0x0100),
timer_global(private_base() + 0x0200),
timer_private(private_base() + 0x0600),
timer_watchdog(private_base() + 0x0620),
interrupt_distributor(private_base() + 0x1000)
{

}

Core::~Core()
{

}

int Core::index()
{
	auto mpidr = c_cp15_c0_mpidr_get();

	return (mpidr & 0x3);
}

Core_mode Core::mode()
{
	auto cpsr = c_cpsr_get();

	return ((Core_mode) (cpsr & 0x1f));
}

void Core::interrupt_mask(Core_interrupt interrupt)
{
	switch (interrupt)
	{
		case Core_interrupt::INTERRUPT:
			c_cpsid_i();
			break;
		case Core_interrupt::FAST_INTERRUPT:
			c_cpsid_f();
			break;
		case Core_interrupt::IMPRECISE_ABORT:
			c_cpsid_a();
			break;
		default:
			break;
	}
}

void Core::interrupt_unmask(Core_interrupt interrupt)
{
	switch (interrupt)
	{
		case Core_interrupt::INTERRUPT:
			c_cpsie_i();
			break;
		case Core_interrupt::FAST_INTERRUPT:
			c_cpsie_f();
			break;
		case Core_interrupt::IMPRECISE_ABORT:
			c_cpsie_a();
			break;
		default:
			break;
	}
}

unsigned int Core::runtime(Core_runtime element)
{
	auto * ptr = (unsigned int *) &__runtime;
	return *(ptr + (unsigned int) element);
}

void Core::call_supervisor(void * request, int opcode)
{
	c_svc(request, opcode);
}

void Core::wakeup(int cpu_index)
{
	if (index() != cpu_index)
	{
		*((unsigned int *)0xFFD05010) = 0;
	}
	else
	{

	}
}

void Core::stack_pointer_mode(Core_mode mode, void * value)
{
	switch (mode)
	{
		case Core_mode::USER:
			c_sp_user_set(value);
			break;
		case Core_mode::FIQ:
			c_sp_fiq_set(value);
			break;
		case Core_mode::IRQ:
			c_sp_irq_set(value);
			break;
		case Core_mode::SVC:
			c_sp_svc_set(value);
			break;
		case Core_mode::ABORT:
			c_sp_abort_set(value);
			break;
		case Core_mode::UNDEFINED:
			c_sp_undefined_set(value);
			break;
		case Core_mode::SYSTEM:
			c_sp_system_set(value);
			break;
		default:
			break;
	}
}

void * Core::stack_pointer_mode(Core_mode mode)
{
	switch (mode)
	{
		case Core_mode::USER:
			return c_sp_user_get();
		case Core_mode::FIQ:
			return c_sp_fiq_get();
		case Core_mode::IRQ:
			return c_sp_irq_get();
		case Core_mode::SVC:
			return c_sp_svc_get();
		case Core_mode::ABORT:
			return c_sp_abort_get();
		case Core_mode::UNDEFINED:
			return c_sp_undefined_get();
		case Core_mode::SYSTEM:
			return c_sp_system_get();
		default:
			return 0;
	}
}

void Core::interrupt_vector_base(unsigned int address)
{
	c_cp15_c12_vbar_set(address);
}

unsigned int Core::interrupt_vector_base()
{
	return c_cp15_c12_vbar_get();
}

unsigned int Core::private_base()
{
	return c_cp15_c15_cbar_get();
}
