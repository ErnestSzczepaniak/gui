#include "screen.h"
#include "string.h"

Screen::Screen()
:
_background(0, 0, 0, 255)
{

}

Screen::~Screen()
{

}

Screen & Screen::background(Pixel pixel)
{
    _background = pixel;

    return *this;
}

Pixel * Screen::background()
{
    return &_background;
}

Screen & Screen::draw(Texture * texture, int x, int y)
{
    if ((x + texture_size_x_pixels < screen_size_x_pixels) && (y + texture_size_y_pixels < screen_size_y_pixels))
    {
        for (int i = 0; i < texture_size_y_pixels; i++)
        {
            for (int j = 0; j < texture_size_x_pixels; j++)
            {
                if (texture->pixel(j, i)->alpha() > 0)
                {
                    _bitmap[y + i][x + j].red(((texture->pixel(j, i)->red() * texture->pixel(j, i)->alpha()) + (_background.red() * (255 - texture->pixel(j, i)->alpha())) ) / 255);
                    _bitmap[y + i][x + j].green(((texture->pixel(j, i)->green() * texture->pixel(j, i)->alpha()) + (_background.green() * (255 - texture->pixel(j, i)->alpha())) ) / 255);
                    _bitmap[y + i][x + j].blue(((texture->pixel(j, i)->blue() * texture->pixel(j, i)->alpha()) + (_background.blue() * (255 - texture->pixel(j, i)->alpha())) ) / 255);
                }
                else
                {
                    _bitmap[y + i][x + j] = _background;
                }
            }
        }
    }

    return *this;
}

Screen & Screen::clear(int x, int y, int size_x, int size_y)
{
    if ((x + size_x < screen_size_x_pixels) && (y + size_y < screen_size_y_pixels))
    {
        for (int i = 0; i < size_y; i++)
        {
            memset(&_bitmap[y + i][x], _background, size_x);
        }
    }

    return *this;
}

Screen & Screen::operator=(Screen & rhs)
{
    memcpy(&_bitmap[0][0], &rhs._bitmap[0][0], screen_size_x_bytes * screen_size_y_pixels);

    return *this;
}
