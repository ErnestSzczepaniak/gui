#ifndef _texture_h
#define _texture_h

#include "config.h"
#include "pixel.h"

class Texture
{
public:
    Texture();
    ~Texture();

    Texture & pixel(Pixel * pixel, int x, int y);
    Pixel * pixel(int x, int y);

    Texture & next(Texture * texture);
    Texture * next();

    Texture & previous(Texture * texture);
    Texture * previous();

    Texture & path(const char * path);
    const char * path();

    Texture & hash(int hash);
    int hash();

    Texture & operator=(Texture & rhs);

protected:

private:
    Pixel _pixel[texture_size_y_pixels][texture_size_x_pixels];

    Texture * _next;
    Texture * _previous;

    const char * _path;
    int _hash;
};

#endif