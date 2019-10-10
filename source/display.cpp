#include "display.h"
#include "hal.h"

Display::Display()
{
    _current = &_screen[1];
}

Display::~Display()
{

}

void Display::init()
{
    h::gui::display_init();
}

void Display::draw(Texture * texture, int x, int y)
{

    _clone();

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            auto * pixel = texture->pixel(j, i);

            _current->put(pixel, x + j, y + i);
        }
    }

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