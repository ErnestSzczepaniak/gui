#include "screen.h"
#include "string.h"

Screen::Screen()
{

}

Screen::~Screen()
{

}

Screen & Screen::operator=(Screen & rhs)
{
    memcpy(&_bitmap[0][0], &rhs._bitmap[0][0], screen_resolution_x * screen_resolution_y * 4);
}

void Screen::put(Pixel * pixel, int x, int y)
{
    _bitmap[y][x] = *pixel;
}