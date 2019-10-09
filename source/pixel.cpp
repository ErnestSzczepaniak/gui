#include "pixel.h"

Pixel::Pixel()
{

}

Pixel::~Pixel()
{
    
}

void Pixel::red(unsigned char red)
{
    _format.red = red;
}

unsigned char Pixel::red()
{
    return _format.red;
}

void Pixel::green(unsigned char green)
{
    _format.green = green;
}

unsigned char Pixel::green()
{
    return _format.green;
}

void Pixel::blue(unsigned char blue)
{
    _format.blue = blue;
}

unsigned char Pixel::blue()
{
    return _format.blue;
}

void Pixel::alpha(unsigned char alpha)
{
    _format.alpha = alpha;
}

unsigned char Pixel::alpha()
{
    return _format.alpha;
}

Pixel::Format Pixel::rgba()
{
    return _format;
}