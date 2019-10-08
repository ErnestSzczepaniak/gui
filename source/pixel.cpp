#include "pixel.h"

Pixel::Pixel()
{

}

Pixel::~Pixel()
{
    
}

void Pixel::red(unsigned char value)
{

}

unsigned char Pixel::red()
{

}

void green(unsigned char value)
{

}

unsigned char Pixel::green()
{

}

void Pixel::blue(unsigned char value)
{

}

unsigned char Pixel::blue()
{

}

void Pixel::hue(unsigned char value)
{

}

unsigned char Pixel::hue()
{

}

void Pixel::saturation(unsigned char value)
{

}

unsigned char Pixel::saturation()
{

}

void Pixel::lightness(unsigned char value)
{

}

unsigned char Pixel::lightness()
{

}

Pixel::operator unsigned int()
{
    return _pixel;
}

Pixel_format_rgb Pixel::as_rgb()
{
    return {
        static_cast<unsigned char>(_pixel >> _shift_red) & 0xff,
        (_pixel >> _shift_green) & 0xff,
        (_pixel >> _shift_blue) & 0xff,
    };

    
}

Pixel_format_rgba Pixel::as_rgba()
{
    // return {
    //     ((unsigned char)(_pixel >> 16)) & 0xff,
    //     ((unsigned char)(_pixel >> 8)) & 0xff,
    //     ((unsigned char)(_pixel)) & 0xff,
    //     ((unsigned char)(_pixel >> 24)) & 0xff,
    // };
}

Pixel_format_hsl Pixel::as_hsl()
{

}
