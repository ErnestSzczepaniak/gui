#include "interrupt_interface.h"

Interrupt_interface::Interrupt_interface(unsigned int address)
:
_map((Map_interrupt_interface*) address)
{

}

Interrupt_interface::~Interrupt_interface()
{

}

void Interrupt_interface::enable()
{
    _map->iccicr |= 1;
}

void Interrupt_interface::disable()
{
    _map->iccicr &= ~1;
}

bool Interrupt_interface::is_enabled()
{
    return (_map->iccicr);
}

void Interrupt_interface::priority_mask(Interrupt_priority_mask mask)
{
    _map->iccpmr = (unsigned int) mask;
}

Interrupt_priority_mask Interrupt_interface::priority_mask()
{
    return (Interrupt_priority_mask)(_map->iccpmr);
}

void Interrupt_interface::binary_point(Interrupt_binary_point point)
{
    _map->iccbpr = (unsigned int) point;
}

Interrupt_binary_point Interrupt_interface::binary_point()
{
    return (Interrupt_binary_point)(_map->iccbpr);
}

// ! single acces when read !! to icciar especially

Interrupt_interface::Acknowledge_pair Interrupt_interface::interrupt_acknowledge()
{
	auto value = _map->icciar;
    return {value >> 10, (value & 0x3ff)};
}

void Interrupt_interface::interrupt_end(unsigned int cpu, unsigned int id)
{
    _map->icceoir = ((cpu << 10) | id);
}

unsigned char Interrupt_interface::running_priority()
{
    return _map->iccrpr;
}

Interrupt_binary_point Interrupt_interface::binary_point_aliased()
{
    return (Interrupt_binary_point)(_map->iccabpr);
}

Interrupt_interface::Acknowledge_pair Interrupt_interface::highest_pending_interrupt()
{
    return {_map->icchpir >> 10, (_map->icchpir & 0x3ff)};
}
