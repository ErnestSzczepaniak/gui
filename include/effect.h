#ifndef _effect_h
#define _effect_h

#include "texture.h"

class Effect
{
public:
    virtual Texture * apply(Texture * texture) = 0;

protected:
    Texture _texture;

};

#endif