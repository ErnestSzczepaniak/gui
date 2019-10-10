#ifndef _loader_h
#define _loader_h

#include "config.h"
#include "texture.h"

struct Model
{
    Texture * texture;
    int count;
};

class Loader
{
    struct Model_info
    {
        int rows;
        int cols;
        int count;
    };

    struct File_info
    {
        int width;
        int height;
        int offset;
    };

    struct Texture_info
    {
        int row;
        int col;
        int start;
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

public:
    Loader();
    ~Loader();

    Texture * load(const char * path, int index);
    Model load(const char * path);

protected:
    File_info _file_info();
    Model_info _model_info(int width, int height);
    Texture_info _texture_info(int index, int rows, int cols, int offset);

    Texture_cell * _cell_empty_find();

    void _load_from_offset(int offset);
    void _texture_link(Texture * previous, Texture * next);

private:
    Texture_cell _cell[loader_cell_size];
    unsigned char _buffer[texture_size_x_bytes];
};

#endif