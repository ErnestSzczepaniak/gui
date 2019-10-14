#include "texture.h"
#include "string.h"

Texture::Texture()
{

}

Texture::~Texture()
{

}

Texture & Texture::pixel(Pixel * pixel, int x, int y)
{
    _pixel[y][x] = *pixel;
    return *this;
}

Pixel * Texture::pixel(int x, int y)
{
    return &_pixel[y][x];
}

Texture & Texture::next(Texture * texture)
{
    _next = texture;
    return *this;
}

Texture * Texture::next()
{
    return _next;
}

Texture & Texture::previous(Texture * texture)
{
    _previous = texture;
    return *this;
}

Texture * Texture::previous()
{
    return _previous;
}

Texture & Texture::path(const char * path)
{
    _path = path;
    return *this;
}

const char * Texture::path()
{
    return _path;
}

Texture & Texture::hash(int hash)
{
    _hash = hash;
    return *this;
}

int Texture::hash()
{
    return _hash;
}

Texture & Texture::operator=(Texture & rhs)
{
    for (int i = 0; i < texture_size_y_pixels; i++)
    {
        memcpy(_pixel, rhs._pixel, sizeof(_pixel));
    }

    return *this;
}