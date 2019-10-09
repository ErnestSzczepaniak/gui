#include "hal.h"
#include "allegro5/allegro.h"
#include "unistd.h"
#include <fstream>
#include "config.h"

std::ifstream _stream;
ALLEGRO_DISPLAY * _display;
ALLEGRO_BITMAP * _bitmap;

void h::gui::display_init()
{
    al_init();
    _display = al_create_display(1024, 720);
    _bitmap = al_create_bitmap(screen_resolution_x, screen_resolution_y);
}

void h::gui::display_pointer(unsigned int * pointer)
{
    //al_set_target_bitmap(bitmap);

    for (int i = 0; i < screen_resolution_y; i++)
    {
        for (int j = 0; j < screen_resolution_x; j++)
        {
            auto pixel = pointer[i * screen_resolution_x + j];

            auto a = (pixel >> 24) & 0xff;
            auto r = (pixel >> 16) & 0xff;
            auto g = (pixel >> 8) & 0xff;
            auto b = (pixel) & 0xff;

            al_put_pixel(j, i, {(float)r/255, (float)g/255, (float)b/255, (float)a/255});
        }
    }

    al_draw_bitmap(_bitmap, 0, 0, 0);
    al_flip_display();
}

void h::gui::display_put_pixel(int x, int y, int r, int g, int b, int a)
{
    al_put_pixel(x, y, {(float)r/255, (float)g/255, (float)b/255, (float)a/255});
}

void h::gui::display_flip()
{
    al_flip_display();
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