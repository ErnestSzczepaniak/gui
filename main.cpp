#include <stdio.h>
#include "hal.h"

int fx = 13;
int fy = 13;

class box
{
public:
   box(int posx, int posy) : _posx(posx), _posy(posy) {}
   ~box(){}

   int _posx, _posy;

   void draw(int r, int g, int b, int a)
   {
      for (int i = 0; i < fx; i++)
      {
         for (int j = 0; j < fy; j++)
         {
            h_display_put_pixel(_posx + i, _posy + j, r, g, b, a);
         }
      }

      h_display_flip();
   }
};

box drop[10];

#include <fstream>

int main()
{
   unsigned char buff[128];

      std::fstream fs;
     fs.open("pixil-frame-0.bmp", std::fstream::out);
      auto res = fs.read((char *) buff, 128);



   // h_display_init();



   // for (int i = 0; i < 20; i++)
   // {
   //    auto w = box(i * (fx + 1), 0);
   //    w.draw(80 + i, 150, 30 - i, 50 - i);
   // }

   

   while(1);
}