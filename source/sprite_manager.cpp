#include "sprite_manager.h"
#include "hal.h"
#include "string.h"

Sprite_manager::Sprite_manager()
{

}

Sprite_manager::~Sprite_manager()
{

}

unsigned int * Sprite_manager::open(const char * path)
{
    if (auto * cell = _cell_find(path); cell == nullptr)
    {
        unsigned char buffer[1024];

        if (auto result = h_file_open(path, buffer, 1024))
        {
            auto * file = (BMP_file *) buffer;

            if ((file->width == _sprite_width) && (file->height == _sprite_heigth) && (file->size_raw == (_sprite_heigth * _sprite_width * 4)))
            {
                auto * cell = _cell_find();

                cell->empty = false;
                cell->path = path;
                memcpy(cell->data, &buffer[file->offset], _sprite_heigth * _sprite_width * 4);

                return cell->data;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        return cell->data;
    }
}

bool Sprite_manager::close()
{

}

//---------------------------------------------| protected |---------------------------------------------//

Sprite_manager::Cell * Sprite_manager::_cell_find()
{
    for (int i = 0; i < _cell_buffer_size; i++)
    {
        if (_cell[i].empty) return &_cell[i];
    }

    return nullptr;
}

Sprite_manager::Cell * Sprite_manager::_cell_find(const char * path)
{
    for (int i = 0; i < _cell_buffer_size; i++)
    {
        if (_cell[i].empty == false)
        {
            if (strcmp(_cell[i].path, path) == 0) return &_cell[i];
        }
        else
        {
            
        }
    }

    return nullptr;
}