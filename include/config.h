#ifndef _config_h
#define _config_h

#include <iostream>
#include "stdio.h"

constexpr int screen_size_x_pixels = 64;
constexpr int screen_size_x_bytes = screen_size_x_pixels * 4;
constexpr int screen_size_y_pixels = 64;
constexpr int screen_size_y_bytes = screen_size_y_pixels * 4;

constexpr int manager_size_buffer = 128;
constexpr int object_buffer_size = 128;

constexpr int loader_cell_size = 128;

constexpr int texture_size_x_pixels = 16;
constexpr int texture_size_x_bytes = texture_size_x_pixels * 4;
constexpr int texture_size_y_pixels = 16;
constexpr int texture_size_y_bytes = texture_size_y_pixels * 4;
constexpr int texture_size_pixels = texture_size_x_pixels * texture_size_y_pixels;
constexpr int texture_size_bytes = texture_size_pixels * 4;

constexpr int effect_buffer_size = 8;

template<typename ...T>
void _i(const char * format, T ... ts)
{
    unsigned char buffer[256];
    snprintf((char *)buffer, 256, format, ts...);
    std::cout << buffer << std::endl;
}

#endif