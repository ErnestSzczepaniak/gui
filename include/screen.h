#ifndef _screen_h
#define _screen_h

#include "config.h"
#include "pixel.h"

class Screen
{
public:
    Screen();
    ~Screen();

    //Screen & operator=(Screen & rhs);
    void put(Pixel * pixel, int x, int y);

    Pixel _bitmap[screen_size_y_pixels][screen_size_x_pixels];

protected:
};

#endif