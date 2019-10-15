#ifndef _screen_h
#define _screen_h

#include "config.h"
#include "texture.h"

class Screen
{
public:
    Screen();
    ~Screen();

    Screen & background(Pixel pixel);
    Pixel * background();

    Screen & draw(Texture * texture, int x, int y);
    Screen & clear(int x, int y, int size_x, int size_y);

    Screen & operator=(Screen & rhs);

protected:
    Pixel _bitmap[screen_size_y_pixels][screen_size_x_pixels];
    Pixel _background;
};

#endif