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

void Sprite::pos_x(int pos_x)
{
    _pos_x = pos_x;
}

int Sprite::pos_x()
{
    return _pos_x;
}

void Sprite::pos_y(int pos_y)
{
    _pos_y = pos_y;
}

int Sprite::pos_y()
{
    return _pos_y;
}

void Sprite::texture(Texture * texture)
{
    _texture = texture;
}

Texture * Sprite::texture()
{
    return _texture;
}

void Sprite::effect(Effect * effect)
{
    _effect = effect;
}

Effect * Sprite::effect()
{
    return _effect;
}
