#ifndef _effect_recolor_h
#define _effect_recolor_h

#include "effect.h"

class Effect_recolor : public Effect
{
public:
    Effect_recolor();
    ~Effect_recolor();

    void set_red(unsigned char red);

    virtual Texture * apply(Texture * texture);

protected:
    int _red_set;

private:
};

#endif