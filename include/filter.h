#ifndef _filter_h
#define _filter_h

#include "pixel.h"

class Filter
{
public:
    virtual Pixel * apply(Pixel * pixel) = 0;

protected:
    Pixel _pixel;

};  

class Filter_set : public Filter
{
public:
    Filter_set(int red = -1, int green = -1, int blue = -1, int alpha = -1);
    ~Filter_set();

    Filter_set & red(unsigned char red);
    unsigned char red();

    Filter_set & green(unsigned char green);
    unsigned char green();

    Filter_set & blue(unsigned char blue);
    unsigned char blue();

    Filter_set & alpha(unsigned char alpha);
    unsigned char alpha();

    virtual Pixel * apply(Pixel * pixel);

protected:
    int _red;
    int _green;
    int _blue;
    int _alpha;
};


#endif