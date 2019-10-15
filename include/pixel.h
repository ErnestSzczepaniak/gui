#ifndef _pixel_h
#define _pixel_h

class [[gnu::packed]] Pixel
{
public:
    Pixel();
    Pixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
    ~Pixel();

    Pixel & red(unsigned char value);
    unsigned char red();

    Pixel & green(unsigned char value);
    unsigned char green();

    Pixel & blue(unsigned char value);
    unsigned char blue();

    Pixel & alpha(unsigned char value);
    unsigned char alpha();

    Pixel & operator=(Pixel & rhs);
    bool operator==(Pixel & rhs);

    operator unsigned int();

protected:

private:
    unsigned char _red;
    unsigned char _green;
    unsigned char _blue;
    unsigned char _alpha;

};

#endif