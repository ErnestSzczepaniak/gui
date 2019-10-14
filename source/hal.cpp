#include "hal.h"
#include <pthread.h>
#include "unistd.h"
#include <fstream>
#include "config.h"

std::ifstream _stream;
unsigned int * _current_ptr;

void put_pixel(int x, int y, int r, int g, int b)
{
   printf("\x1b[%d;%dH\x1b[38;2;%d;%d;%dm@", y + 1, x + 1, r, g, b);
}

void * h_screen_refresh(void * params)
{
    std::system("clear");

    while(1)
    {
        auto my_ptr = _current_ptr;

        for (int i = 0; i < screen_size_y_pixels; i++)
        {
            for (int j = 0; j < screen_size_x_pixels; j++)
            {
                auto pixel = my_ptr[i * screen_size_x_pixels + j];

                auto a = (pixel >> 24) & 0xff;
                auto r = (pixel >> 16) & 0xff;
                auto g = (pixel >> 8) & 0xff;
                auto b = (pixel) & 0xff;

                put_pixel(j, i, r, g, b);
            }
        }

        //usleep(1000000);
    }
}

void h::gui::display_init(unsigned int * ptr)
{   
    _current_ptr = ptr;
    pthread_t id;
    pthread_create(&id, NULL, h_screen_refresh, NULL);
}

void h::gui::display_pointer(unsigned int * pointer)
{
    _current_ptr = pointer;
}

bool h::gui::file_open(const char * path)
{
    _stream.open(path, std::istream::in);

    if (_stream.is_open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void h::gui::file_read(void * buffer, int size)
{
    _stream.read((char*)buffer, size);
}

int h::gui::file_seek(int offset)
{
    _stream.seekg(offset, std::ios::beg);
    return _stream.tellg();
}

void h::gui::file_close()
{
    _stream.close();
}

void * h::gui::memory_create(int size)
{
    return new unsigned char[size];
}

void h::gui::memory_destroy(void * space)
{
    delete[] space;
}