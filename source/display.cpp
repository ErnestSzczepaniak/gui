#include "display.h"
#include "hal.h"
#include "unistd.h"

Display::Display()
{
    
}

Display::~Display()
{

}

void Display::init()
{
    h::gui::display_init((unsigned int *)&_screen[0]);
    _current = &_screen[1];
}

void Display::draw(Sprite * sprite)
{
    _clone();

    Texture * texture;
    
     if (auto * effect = sprite->effect(); effect != nullptr)
     {
        texture = effect->apply(sprite->texture());
     }
     else
     {
        texture = sprite->texture();
     }

    _current->draw(texture, sprite->pos_x(), sprite->pos_y());

    h::gui::display_pointer((unsigned int *) _current);

    _swap();
}

//---------------------------------------------| info |---------------------------------------------//

void Display::_swap()
{
    _current = (_current == &_screen[0]) ? &_screen[1] : &_screen[0];
}

void Display::_clone()
{
   _current == &_screen[0] ? _screen[0] = _screen[1] : _screen[1] = _screen[0];
}