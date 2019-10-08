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

Pixel * Texture::pixel()
{
    return _pixel;
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

// void Texture::draw(int x, int y)
// {
//     for (int i = 0; i < _height; i++) //16
//     {
//         for (int j = 0; j < _width; j++) //10
//         {
//             auto pixel = _pixel[i * _height + j];

//             //alpha ? h::gui::display_put_pixel(x + j, y + _height - i - 1, pixel.red, pixel.green, pixel.blue, pixel.alpha)
//             //: h::gui::display_put_pixel(x + j, y + _height - i - 1, pixel.red, pixel.green, pixel.blue, pixel.alpha); 
//         }
//     }

//     //h::gui::display_flip();
// }
