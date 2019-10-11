#ifndef _sprite_h
#define _sprite_h

#include "config.h"
#include "texture.h"
#include "effect.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();

    void pos_x(int pos_x);
    int pos_x();

    void pos_y(int pos_y);
    int pos_y();

    void texture(Texture * texture);
    Texture * texture();

    void effect(Effect * effect);
    Effect * effect();

protected:

private:
    Texture * _texture;
    Effect * _effect;

    int _pos_x;
    int _pos_y;
};


#endif