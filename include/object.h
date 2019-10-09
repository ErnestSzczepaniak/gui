#ifndef _object_h
#define _object_h

#include "generic_object.h"

template<int size_x, int size_y>
class Object
{
public:
    Object();
    ~Object();

    Sprite * sprite(int x, int y);

protected:

private:
    Sprite _sprite[size_x][size_y];

}

#endif