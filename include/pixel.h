#ifndef _pixel_h
#define _pixel_h

struct Pixel_format_rgb
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct Pixel_format_rgba
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

struct Pixel_format_hsl
{
    unsigned char hue;
    unsigned char saturation;
    unsigned char lightness;
};

class Pixel
{
    static constexpr unsigned int _shift_alpha = 24;
    static constexpr unsigned int _shift_red = 16;
    static constexpr unsigned int _shift_green = 8;
    static constexpr unsigned int _shift_blue = 0;

public:
    Pixel();
    ~Pixel();

    void red(unsigned char value);
    unsigned char red();

    void green(unsigned char value);
    unsigned char green();

    void blue(unsigned char value);
    unsigned char blue();

    void hue(unsigned char value);
    unsigned char hue();

    void saturation(unsigned char value);
    unsigned char saturation();

    void lightness(unsigned char value);
    unsigned char lightness();

    operator unsigned int();
    Pixel_format_rgb as_rgb();
    Pixel_format_rgba as_rgba();
    Pixel_format_hsl as_hsl();

protected:

    unsigned int _pixel;
};

#endif