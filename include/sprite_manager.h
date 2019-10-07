#ifndef _sprite_manager_h
#define _sprite_manager_h


class Sprite_manager
{
    static constexpr int _sprite_heigth = 16;
    static constexpr int _sprite_width = 10;
    static constexpr int _cell_buffer_size = 128;

    struct Cell 
    {
        bool empty = true; 
        unsigned int data[_sprite_heigth * _sprite_width]; 
        const char * path;
    };

    struct [[gnu::packed]] BMP_file 
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
    Sprite_manager();
    ~Sprite_manager();

    unsigned int * open(const char * path);
    bool close();


protected:
    Cell * _cell_find();
    Cell * _cell_find(const char * path);

    Cell _cell[_cell_buffer_size];
};

#endif