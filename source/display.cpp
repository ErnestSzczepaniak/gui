#include "display.h"
#include "hal.h"

Display::Display()
:
index(0)
{

}

Display::~Display()
{

}

void Display::refresh()
{
    auto current_index = index;

    for (int i = 0; i < _resulution_y; i++)
    {
        for (int j = 0; j < _resulution_x; j++)
        {
                //h_pixel_set(i, j, frame_buffer[current_index][i][j]);
        }
    }
}