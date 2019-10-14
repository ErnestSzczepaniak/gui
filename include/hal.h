#ifndef _hal_h
#define _hal_h

namespace h::gui
{
    void display_init(unsigned int * pointer);
    void display_pointer(unsigned int * pointer);

    bool file_open(const char * path);
    void file_read(void * buffer, int size);
    int file_seek(int offset);
    void file_close();

    void * memory_create(int size);
    void memory_destroy(void * space);
}

#endif