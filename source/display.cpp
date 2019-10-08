#include "display.h"
#include "hal.h"

Display::Display()
{
    _current = &_buffer[1];
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
        for (int i = 0; i < texture->height(); i++)
        {
            for (int j = 0; j < texture->width(); j++)
            {
                auto * pixel = &texture->pixel()[i * texture->width() + j];

                _current->space[y + texture->height() - i - 1][x + j] = pixel->operator unsigned int();
            }
        }

        h::gui::display_pointer((unsigned int *) _current);
        _swap();
    }
}

//---------------------------------------------| info |---------------------------------------------//

void Display::_swap()
{
    if (_current == &_buffer[0])
    {
        _current = &_buffer[1];
    }
    else
    {
        _current = &_buffer[0];
    }
}