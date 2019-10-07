#ifndef _display_h
#define _display_h

class Display
{
    static constexpr int _resulution_x = 128;
    static constexpr int _resulution_y = 64;

public:
    Display();
    ~Display();

    void refresh();
    
    unsigned int frame_buffer[2][_resulution_y][_resulution_x];
    int index;

};

#endif