#ifndef _screen_h
#define _screen_h

#include "config.h"
#include "pixel.h"

class Screen
{
public:
    Screen();
    ~Screen();

    Screen & operator=(Screen & rhs);
    void put(Pixel * pixel, int x, int y);

protected:
    Pixel _bitmap[screen_resolution_y][screen_resolution_x];
};

#endif