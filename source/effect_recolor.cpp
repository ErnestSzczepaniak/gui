#include "effect_recolor.h"

Effect_recolor::Effect_recolor()
{

}

Effect_recolor::~Effect_recolor()
{

}

void Effect_recolor::set_red(unsigned char red)
{
    _red_set = red;
}

Texture * Effect_recolor::apply(Texture * texture)
{
    _texture = *texture;

    for (int i = 0; i < texture_size_y_pixels; i++)
    {
        for (int j = 0; j < texture_size_x_pixels; j++)
        {
            *_texture.pixel(j, i) = *texture->pixel(j, i);
            _texture.pixel(j, i)->red(_red_set);
        }
    }

    return &_texture;
}