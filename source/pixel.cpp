#include "pixel.h"

Pixel::Pixel()
{

}

Pixel::~Pixel()
{
    
}

void Pixel::red(unsigned char value)
{
    
}

unsigned char Pixel::red()
{

}

void green(unsigned char value)
{

}

unsigned char Pixel::green()
{

}

void Pixel::blue(unsigned char value)
{

}

unsigned char Pixel::blue()
{

}

void Pixel::hue(unsigned char value)
{

}

unsigned char Pixel::hue()
{

}

void Pixel::saturation(unsigned char value)
{

}

unsigned char Pixel::saturation()
{

}

void Pixel::lightness(unsigned char value)
{

}

unsigned char Pixel::lightness()
{

}

Pixel::operator unsigned int()
{
    return _pixel;
}

Pixel_format_rgb Pixel::as_rgb()
{
    return {
        (_pixel >> _shift_red) & 0xff,
        (_pixel >> _shift_green) & 0xff,
        (_pixel >> _shift_blue) & 0xff,
    };

    
}

Pixel_format_rgba Pixel::as_rgba()
{
    return {
        (_pixel >> _shift_red) & 0xff,
        (_pixel >> _shift_green) & 0xff,
        (_pixel >> _shift_blue) & 0xff,
        (_pixel >> _shift_alpha) & 0xff
    };
}

Pixel_format_hsl Pixel::as_hsl()
{
    float hue, saturation, lightness;

    float r = red() / 255.0;
    float g = green() / 255.0;
    float b = blue() / 255.0;

    auto min = _find_min(_find_min(r, g), b);
    auto max = _find_max(_find_max(r, g), b);

    auto delta = max - min;

    lightness = (max + min) / 2;

    if (delta == 0)
    {
        hue = 0;
        saturation = 0;
    }
    else
    {
        saturation = lightness <= 0.5 ? (delta / (max + min)) : (delta / (2 - max - min));

        if (r == max)
        {
            hue = ((g - b) / 6) / delta;
        }
        else if (g == max)
        {
            hue = (1.0f / 3) + ((b - r) / 6) / delta;         
        }
        else
        {
            hue = (2.0f / 3) + ((r - g) / 6) / delta;      
        }
    }

    return {hue * 100, saturation * 100, (lightness * 100) / 360};
}   

//---------------------------------------------| info |---------------------------------------------//

float Pixel::_find_min(float a, float b)
{
    return a <= b ? a : b;
}

float Pixel::_find_max(float a, float b)
{
    return a >= b ? a : b;
}

Pixel_format_rgb Pixel::_to_rgb(int hue, int saturation, int lightness)
{
    unsigned char red, green, blue;

    float fhue = hue * 3.6;
    float fsaturation = saturation / 100.0;
    float flightness = lightness / 100.0;

    if (saturation == 0)
	{
        red = flightness * 255;
        green = flightness * 255;
        blue = flightness * 255;
	}
	else
	{
		float v1, v2;
		float vhue = fhue/ 360;

		v2 = (flightness < 0.5) ? (flightness * (1 + fsaturation)) : ((flightness + fsaturation) - (flightness * fsaturation));
		v1 = 2 * flightness - v2;

		red = (255 * _hue_to_rgb(v1, v2, vhue + (1.0 / 3)));
		green = (255 * _hue_to_rgb(v1, v2, vhue));
		blue = (255 * _hue_to_rgb(v1, v2, vhue - (1.0 / 3)));
	}

	return {red, green, blue};
}

float Pixel::_hue_to_rgb(float v1, float v2, float vH)
{
	if (vH < 0) vH += 1;
	if (vH > 1) vH -= 1;
	if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);
    if ((2 * vH) < 1) return v2;
    if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

	return v1;
}