#include "screen.h"
#include "string.h"

Screen::Screen()
{

}

Screen::~Screen()
{

}

// Screen & Screen::operator=(Screen & rhs)
// {
//     memcpy(&_bitmap[0][0], &rhs._bitmap[0][0], screen_size_x_bytes * screen_size_y_pixels);
// }

void Screen::put(Pixel * pixel, int x, int y)
{   
    _bitmap[y][x] = *pixel;
}