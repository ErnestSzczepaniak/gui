#include "sprite.h"
#include "hal.h"

Sprite::Sprite(unsigned int * data)
:
_data(data)
{

}

Sprite::~Sprite()
{

}

unsigned int * Sprite::data()
{
    return _data;
}

void Sprite::draw(int x, int y, int alpha)
{
    for (int i = 0; i < 16; i++) //16
    {
        for (int j = 0; j < 10; j++) //10
        {
            auto pixel = _data[i * 10 + j];

            auto a = (pixel >> 24) & 0xff;
            auto r = (pixel >> 16) & 0xff;
            auto g = (pixel >> 8) & 0xff;
            auto b = (pixel) & 0xff;

            alpha ? h_display_put_pixel(x + j, y + 16 - i - 1, r, g, b, alpha)
            : h_display_put_pixel(x + j, y + 16 - i - 1, r, g, b, a); 

        }
    }

    h_display_flip();
}
