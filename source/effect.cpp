#include "effect.h"

Effect::Effect()
:
_active(true)
{

}

Effect::~Effect()
{

}

void Effect::active(bool active)
{
    _active = active;
}

bool Effect::active()
{
    return _active;
}