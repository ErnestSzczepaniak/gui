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
    if (((x + texture->width()) < screen_resolution_x) && ((y + texture->height()) < screen_resolution_y))
    {
        _clone();

        for (int i = 0; i < texture->height(); i++)
        {
            for (int j = 0; j < texture->width(); j++)
            {
                auto * pixel = texture->pixel(j, i);

                if (pixel->green() != 0)
                {
                    auto * s = (unsigned int *) pixel;
                    int k = 2;
                }

                _current->put(pixel, x + j, y + i);
            }
        }

        h::gui::display_pointer((unsigned int *) _current);

        _swap();
    }
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