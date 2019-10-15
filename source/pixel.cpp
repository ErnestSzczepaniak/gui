#include "pixel.h"

Pixel::Pixel()
:
_red(0),
_green(0),
_blue(0),
_alpha(0)
{

}

Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
:
_red(red),
_green(green),
_blue(blue),
_alpha(alpha)
{
    
}

Pixel::~Pixel()
{
    
}

Pixel & Pixel::red(unsigned char red)
{
    _red = red;
    return *this;
}

unsigned char Pixel::red()
{
    return _red;
}

Pixel & Pixel::green(unsigned char green)
{
    _green = green;
    return *this;
}

unsigned char Pixel::green()
{
    return _green;
}

Pixel & Pixel::blue(unsigned char blue)
{
    _blue = blue;
    return *this;
}

unsigned char Pixel::blue()
{
    return _blue;
}

Pixel & Pixel::alpha(unsigned char alpha)
{
    _alpha = alpha;
    return *this;
}

unsigned char Pixel::alpha()
{
    return _alpha;
}

Pixel & Pixel::operator=(Pixel & rhs)
{
    _red = rhs._red;
    _green = rhs._green;
    _blue = rhs._blue;
    _alpha = rhs._alpha;

    return *this;
}

bool Pixel::operator==(Pixel & rhs)
{
    return (
        _red == rhs._red &&
        _green == rhs._green && 
        _blue == rhs._blue && 
        _alpha == rhs._alpha
    );
}

Pixel::operator unsigned int()
{
    return (_red << 24 | _green << 18 | _blue << 8 | _alpha);
}