#ifndef _texture_h
#define _texture_h

#include "pixel.h"

class Texture
{
public:
    Texture();
    ~Texture();

    void pixel(Pixel * value);
    Pixel * pixel();

    void height(int value);
    int height();

    void width(int value);
    int width();

    void path(const char * value);
    const char * path();

protected:
    Pixel * _pixel;
    int _height;
    int _width;
    const char * _path;

};

#endif