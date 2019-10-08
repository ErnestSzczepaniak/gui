#ifndef _hal_h
#define _hal_h

namespace h::gui
{
    void display_init();
    void display_pointer(unsigned int * pointer);
    void display_put_pixel(int x, int y, int r, int g, int b, int a);
    void display_flip();

    bool file_open(const char * path);
    void file_read(void * buffer, int size);
    void file_seek(int offset);
    void file_close();

    void * memory_create(int size);
    void memory_destroy(void * space);
}

#endif