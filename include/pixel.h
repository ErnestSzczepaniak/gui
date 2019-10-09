#ifndef _pixel_h
#define _pixel_h

class Pixel
{
    struct [[gnu::packed]] Format
    {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    };

public:
    Pixel();
    ~Pixel();

    void red(unsigned char value);
    unsigned char red();

    void green(unsigned char value);
    unsigned char green();

    void blue(unsigned char value);
    unsigned char blue();

    void alpha(unsigned char value);
    unsigned char alpha();

    Format rgba();

protected:
    Format _format;

};

#endif