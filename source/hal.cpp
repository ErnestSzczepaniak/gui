#include "hal.h"
#include "allegro5/allegro.h"
#include "unistd.h"
#include <fstream>

void h_wait(int ms)
{
    usleep(ms * 1000);
}

void h_display_init()
{
    al_init();
    al_create_display(1024, 600);
}

void h_display_clear()
{
    
}

void h_display_put_pixel(int x, int y, int r, int g, int b, int a)
{
    al_put_pixel(x, y, {(float)r/255, (float)g/255, (float)b/255, (float)a/255});
}

void h_display_flip()
{
    al_flip_display();
}

bool h_file_open(const char * path, void * buffer, int size)
{
    std::ifstream stream;

    stream.open(path, std::istream::in);

    if (stream.is_open())
    {
        stream.read((char*)buffer, size);
        return true;
    }
    else
    {
        return false;
    }
}