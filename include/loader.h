#ifndef _loader_h
#define _loader_h

#include "config.h"
#include "texture.h"

struct Texture_pack
{
    Texture * texture;
    int count;
};

struct Texture_cell
{
    bool empty = true;
    Texture texture;
};

struct [[gnu::packed]] Header
{
    unsigned short int id;
    unsigned int size;
    unsigned short int reserved[2];
    unsigned int offset;
    unsigned int bytes_in_header;
    unsigned int width;
    unsigned int height;
    unsigned short int planes;
    unsigned short int bits_per_pixel;
    unsigned int bi_rgb;
    unsigned int size_raw;
};

struct Texture_info
{
    int width;
    int height;
    int offset;
};

class Loader
{
public:
    Loader();
    ~Loader();

    Texture * load(const char * path, int index);

protected:
    Texture_info _texture_info();

    Texture_cell * _cell_empty_find();
    Texture * _texture_find(int hash);
    int _hash_calculate(const char * path, int count);

    void _load_from_offset(int offset);


private:
    Texture_cell _cell[loader_buffer_size];
    unsigned char _buffer[loader_buffer_size] = {0};
};

#endif