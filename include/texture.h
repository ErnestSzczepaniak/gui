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

    void next(Texture * texture);
    Texture * next();

    void previous(Texture * texture);
    Texture * previous();

    void path(const char * path);
    const char * path();

    void hash(int hash);
    int hash();

protected:

private:
    Pixel _pixel[screen_resolution_grid][screen_resolution_grid];

    Texture * _next;
    Texture * _previous;

    const char * _path;

    int _hash;
};

#endif