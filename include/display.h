#ifndef _display_h
#define _display_h

#include "config.h"
#include "texture.h"

class Display
{
    struct Screen 
    {
        unsigned int space[screen_resolution_y][screen_resolution_x] = {0};
    };

public:
    Display();
    ~Display();

    void init();
    void draw(Texture * texture, int x, int y);

protected:
    Screen _buffer[2];
    Screen * _current;

    void _swap();
};

#endif