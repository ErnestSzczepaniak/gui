#ifndef _config_h
#define _config_h

constexpr int screen_resolution_x = 1024;
constexpr int screen_resolution_y = 720;

constexpr int manager_size_buffer = 128;
constexpr int object_buffer_size = 128;

constexpr int loader_cell_size = 128;

constexpr int texture_size_x_pixels = 16;
constexpr int texture_size_x_bytes = texture_size_x_pixels * 4;
constexpr int texture_size_y_pixels = 16;
constexpr int texture_size_y_bytes = texture_size_y_pixels * 4;
constexpr int texture_size_pixels = texture_size_x_pixels * texture_size_y_pixels;
constexpr int texture_size_bytes = texture_size_pixels * 4;

#endif