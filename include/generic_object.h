#ifndef _generic_object_h
#define _generic_object_h

#include "config.h"
#include "sprite.h"

class Generic_object
{
public:
    Generic_object(const char * name = nullptr, int pos_x = 0, int pos_y = 0, bool visible = true);
    ~Generic_object();

    void name(const char * name);
    const char * name();

    void pos_x(int pos_x);
    int pos_x();

    void pos_y(int pos_y);
    int pos_y();

    void visible(bool visible);
    bool visible();

    virtual int size_x() = 0;
    virtual int size_y() = 0;

    virtual Sprite * sprite(int x, int y) = 0;

    static Generic_object * find(const char * name);

protected:
    const char * _name;
    int _pos_x;
    int _pos_y;
    bool _visible;

    void _update(Generic_object * object);

private:
    static Generic_object * _table[object_buffer_size];
    static int _counter;
    
};

#endif