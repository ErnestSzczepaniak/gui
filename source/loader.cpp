#include "loader.h"
#include "hal.h"

Loader::Loader()
{

}

Loader::~Loader()
{

}

Texture * Loader::load(const char * path, int index)
{
    if (auto result = h::gui::file_open(path))
    {
        auto [width, height, offset] = _texture_info();

        if ((width % screen_resolution_grid == 0) &&
            (height % screen_resolution_grid == 0))
        {
            auto rows = height / screen_resolution_grid;
            auto cols = width / screen_resolution_grid;
            
            for (int i = 0; i < rows; i++)
            {   
                for (int j = 0; j < cols; j++)
                {
                    auto index = i * cols + j;

                    auto row_end = offset + (rows - index / cols - 1) * 1024;
                    auto row_start = row_end + 1024 * cols - 64;

                    for (int k = 0; k < 16; k++)
                    {
                        _load_from_offset(row_start);
                        row_start -= cols * 16 * 4;
                    }


                    
                }
            }
        }
        else
        {
            
        }
    }
    else
    {
        h::gui::file_close();
        return nullptr;
    }    
}

//---------------------------------------------| info |---------------------------------------------//

Texture_info Loader::_texture_info()
{
    h::gui::file_read(_buffer, sizeof(Header));

    auto * ptr = (Header *) _buffer;

    return {ptr->width, ptr->height, ptr->offset};
}

void Loader::_load_from_offset(int offset)
{
    h::gui::file_seek(offset);
    h::gui::file_read(_buffer, 64);
}