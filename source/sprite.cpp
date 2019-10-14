#include "sprite.h"

Sprite::Sprite()
:
_texture(nullptr),
_effect(nullptr),
_pos_x(0),
_pos_y(0)
{

}

Sprite::~Sprite()
{

}

Sprite & Sprite::pos_x(int pos_x)
{
    _pos_x = pos_x;
    return *this;
}

int Sprite::pos_x()
{
    return _pos_x;
}

Sprite & Sprite::pos_y(int pos_y)
{
    _pos_y = pos_y;
    return *this;
}

int Sprite::pos_y()
{
    return _pos_y;
}

Sprite & Sprite::texture(Texture * texture)
{
    _texture = texture;
    return *this;
}

Texture * Sprite::texture()
{
    return _texture;
}

Sprite & Sprite::effect(Effect * effect)
{
    _effect = effect;
    return *this;
}

Effect * Sprite::effect()
{
    return _effect;
}

Sprite & Sprite::filter(Filter * filter)
{
    _filter = filter;
    return *this;
}

Filter * Sprite::filter()
{
    return _filter;
}
