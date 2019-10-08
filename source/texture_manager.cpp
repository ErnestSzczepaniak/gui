#include "texture_manager.h"
#include "hal.h"
#include "string.h"

Texture_manager::Texture_manager()
{
    for (int i = 0; i < manager_size_buffer; i++)
    {
        _texture[i] = nullptr;
    }
}

Texture_manager::~Texture_manager()
{

}

Texture * Texture_manager::open(const char * path)
{
    if (auto * texture = _texture_find(path); texture == nullptr)
    {
        if (auto result = h::gui::file_open(path))
        {
            BMP_header file_header;

            h::gui::file_read(&file_header, sizeof(BMP_header));

            if ((file_header.height % screen_resolution_grid == 0) &&
                (file_header.width % screen_resolution_grid == 0))
            {
                auto * texture = (Texture *) h::gui::memory_create(sizeof(Texture));
                auto * pixel = (Pixel *) h::gui::memory_create(file_header.size_raw);

                texture->path(path);
                texture->width(file_header.width);
                texture->height(file_header.height);
                texture->pixel(pixel);

                h::gui::file_seek(file_header.offset);
                h::gui::file_read(pixel, file_header.size_raw);
                h::gui::file_close();

                auto ** space = _space_find();
                *space = texture;

                return texture;
            }
            else
            {
                h::gui::file_close();

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
        return texture;
    }
}

bool Texture_manager::close()
{

}

//---------------------------------------------| protected |---------------------------------------------//

Texture * Texture_manager::_texture_find(const char * path)
{
    for (int i = 0; i < manager_size_buffer; i++)
    {
        if (_texture[i] != nullptr)
        {
            if (strcmp(_texture[i]->path(), path) == 0)
            {
                return _texture[i];
            }
        }
    }

    return nullptr;
}

Texture ** Texture_manager::_space_find()
{
    for (int i = 0; i < manager_size_buffer; i++)
    {
        if (_texture[i] == nullptr) return &_texture[i];
    }

    return nullptr;
}