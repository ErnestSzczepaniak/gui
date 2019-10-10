#include "texture.h"

Texture::Texture()
{

}

Texture::~Texture()
{

}

void Texture::pixel(Pixel * pixel, int x, int y)
{
    _pixel[y][x] = *pixel;
}

Pixel * Texture::pixel(int x, int y)
{
    return &_pixel[y][x];
}

void Texture::next(Texture * texture)
{
    _next = texture;
}

Texture * Texture::next()
{
    return _next;
}

void Texture::previous(Texture * texture)
{
    _previous = texture;
}

Texture * Texture::previous()
{
    return _previous;
}

void Texture::path(const char * path)
{
    _path = path;
}

const char * Texture::path()
{
    return _path;
}

void Texture::hash(int hash)
{
    _hash = hash;
}

int Texture::hash()
{
    return _hash;
}
