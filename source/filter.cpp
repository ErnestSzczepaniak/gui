#include "filter.h"

Filter_set::Filter_set(int red, int green, int blue, int alpha)
:
_red(red),
_green(green),
_blue(blue),
_alpha(alpha)
{

}

Filter_set::~Filter_set()
{

}

Filter_set & Filter_set::red(unsigned char red)
{
    _red = red;
}

unsigned char Filter_set::red()
{
    return _red;
}

Filter_set & Filter_set::green(unsigned char green)
{
    _green = green;
    return *this;
}

unsigned char Filter_set::green()
{
    return _green;
}

Filter_set & Filter_set::blue(unsigned char blue)
{
    _blue = blue;
    return *this;
}

unsigned char Filter_set::blue()
{
    return _blue;
}

Filter_set & Filter_set::alpha(unsigned char alpha)
{
    _alpha = alpha;
    return *this;
}

unsigned char Filter_set::alpha()
{
    return _alpha;
}

Pixel * Filter_set::apply(Pixel * pixel)
{
    _pixel = *pixel;

    if (_red >= 0) _pixel.red(_red);
    if (_green >= 0) _pixel.green(_green);
    if (_blue >= 0) _pixel.blue(_blue);
    if (_alpha >= 0) _pixel.alpha(_alpha);

    return &_pixel;
}