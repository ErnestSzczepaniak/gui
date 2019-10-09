#ifndef _display_h
#define _display_h

#include "config.h"
#include "texture.h"
#include "screen.h"

class Display
{

public:
    Display();
    ~Display();

    void init();
    void draw(Texture * texture, int x, int y);

protected:
    Screen _screen[2];
    Screen * _current;

    void _swap();
    void _clone();
};

#endif