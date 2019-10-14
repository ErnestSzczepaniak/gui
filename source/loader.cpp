#include "loader.h"
#include "hal.h"
#include "string.h"

Loader::Loader()
{

}

Loader::~Loader()
{

}

Texture * Loader::load(const char * path, int index)
{
    if (h::gui::file_open(path))
    {
        auto [width, height, offset] = _file_info();
        auto [rows, cols, count] = _model_info(width, height);
        
        if (index < count)
        {
            auto [row, col, start] = _texture_info(index, rows, cols, offset);

            auto * cell = _cell_empty_find();

            for (int i = 0; i < texture_size_y_pixels; i++)
            {
                _load_from_offset(start);

                memcpy(cell->texture.pixel(0, i), _buffer, texture_size_x_bytes);

                start -= cols * texture_size_x_bytes;
            }

            h::gui::file_close();
            return &cell->texture;
        }
        else
        {
            h::gui::file_close();
            return nullptr;
        }
    }
    else
    {
        h::gui::file_close();
        return nullptr;
    }    
}

Model Loader::load(const char * path)
{
    int index = 0;
    Texture * current;
    Texture * previous;
    Texture * first;

    while(current = load(path, index))
    {
        if (index == 0)
        {
            current->previous(nullptr);
            first = current;
        }
        else _texture_link(previous, current);

        index++;

        previous = current;
    }

    if (index)
    {
        return {first, index};
    }
    else
    {
        return {nullptr, 0};
    }
}

//---------------------------------------------| info |---------------------------------------------//

Loader::File_info Loader::_file_info()
{
    h::gui::file_read(_buffer, sizeof(Header));

    auto * ptr = (Header *) _buffer;

    return {ptr->width, ptr->height, ptr->offset};
}

Loader::Model_info Loader::_model_info(int width, int height)
{
    auto rows = height / texture_size_y_pixels;
    auto cols = width / texture_size_x_pixels;
    auto count = rows * cols;

    return {rows, cols, count};
}

void Loader::_load_from_offset(int offset)
{
    h::gui::file_seek(offset);
    h::gui::file_read(_buffer, 64);
}

Loader::Texture_cell * Loader::_cell_empty_find()
{
    for (int i = 0; i < loader_cell_size; i++)
    {
        if (_cell[i].empty)
        {
            _cell[i].empty = false;
            return &_cell[i];
        } 
    }

    return nullptr;
}

Loader::Texture_info Loader::_texture_info(int index, int rows, int cols, int offset)
{
    auto texture_row = index / cols;
    auto texture_col = index % cols;
    auto row_end = offset + (rows - texture_row - 1) * texture_size_bytes * cols;
    auto row_start = row_end + texture_size_bytes * cols - (cols - texture_col) * texture_size_x_bytes;

    return {texture_row, texture_col, row_start};
}

void Loader::_texture_link(Texture * previous, Texture * next)
{
    previous->next(next);
    next->previous(previous);
}