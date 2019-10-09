#ifndef _texture_h
#define _texture_h

#include "config.h"
#include "pixel.h"

class Texture
{
public:
    Texture();
    ~Texture();

    void pixel(Pixel * pixel, int x, int y);
    Pixel * pixel(int x, int y);

    void path(const char * value);
    const char * path();

protected:
    Pixel _pixel[screen_resolution_grid][screen_resolution_grid];
    const char * _path;

};

#endif