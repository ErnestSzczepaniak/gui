#ifndef _texture_manager_h
#define _texture_manager_h

#include "texture.h"
#include "config.h"

class Texture_manager
{
    struct [[gnu::packed]] BMP_header
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
        unsigned int resolution_horizontal;
        unsigned int resolution_vertical;
        unsigned int colors_in_pallet;
        unsigned int colors_important;
    };

public:
    Texture_manager();
    ~Texture_manager();

    Texture * open(const char * path);
    bool close();

protected:
    Texture * _texture[manager_size_buffer];

    Texture * _texture_find(const char * path);
    Texture ** _space_find();
};

#endif