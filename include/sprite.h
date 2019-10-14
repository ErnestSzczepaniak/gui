#ifndef _sprite_h
#define _sprite_h

#include "config.h"
#include "texture.h"
#include "effect.h"
#include "filter.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();

    Sprite & pos_x(int pos_x);
    int pos_x();

    Sprite & pos_y(int pos_y);
    int pos_y();

    Sprite & texture(Texture * texture);
    Texture * texture();

    Sprite & effect(Effect * effect);
    Effect * effect();

    Sprite & filter(Filter * filter);
    Filter * filter();

protected:

private:
    Texture * _texture;
    Effect * _effect;
    Filter * _filter;

    int _pos_x;
    int _pos_y;
};


#endif