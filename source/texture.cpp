#include "texture.h"

Texture::Texture()
{

}

Texture::~Texture()
{

}

void Texture::pixel(Pixel * value)
{
    _pixel = value;
}

Pixel * Texture::pixel(int x, int y)
{
    return (x < _width && y < _height) ? &_pixel[_height * (_height - y - 1) + x]
    : nullptr;
}

void Texture::height(int value)
{
    _height = value;
}

int Texture::height()
{
    return _height;
}

void Texture::width(int value)
{
    _width = value;
}

int Texture::width()
{
    return _width;
}

void Texture::path(const char * value)
{
    _path = value;
}

const char * Texture::path()
{
    return _path;
}