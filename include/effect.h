#ifndef _effect_h
#define _effect_h

#include "texture.h"

class Effect
{
public:
    Effect();
    ~Effect();

    void active(bool active);
    bool active();

    virtual Texture * apply(Texture * texture) = 0;

protected:
    Texture _texture;
    bool _active;

private:
};

#endif