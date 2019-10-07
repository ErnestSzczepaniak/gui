#ifndef _sprite_h
#define _sprite_h

class Sprite
{
public:
    Sprite(unsigned int * data);
    ~Sprite();

    unsigned int * data();
    void draw(int x, int y, int alpha = 0);

protected:
    unsigned int * _data;

};

#endif