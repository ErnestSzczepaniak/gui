#include "texture.h"
#include "loader.h"
#include "display.h"
#include "effect_recolor.h"
#include "sprite.h"
#include <fstream>
#include "filter.h"
#include "unistd.h"

int main()
{
   Loader loader;
   Display display;
   Effect_recolor recolor;
   Sprite se, sr, sn;
   Filter_set filter;

   display.init();


   filter.red(100);

   auto * e = loader.load("/home/en2/Codes/gui/ern2.bmp", 0);
   auto * r = loader.load("/home/en2/Codes/gui/ern.bmp", 1);
   auto * n = loader.load("/home/en2/Codes/gui/ern.bmp", 2);


   se.texture(e);
   sr.texture(r);
   sn.texture(n);

      
   sr.pos_y(16);
   sn.pos_y(32);


   while(1)
   {
      usleep(100000);


      display.draw(&se);
      display.draw(&sr);     
      display.draw(&sn);   
   }
}