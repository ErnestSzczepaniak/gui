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
   Sprite sprite;
   Filter_set filter;

   display.init();


   filter.red(100);

   auto * texture = loader.load("/home/en2/Codes/gui/strike.bmp", 0);

   Texture test;
   test = *texture;

   sprite.texture(&test);
   sprite.filter(&filter);

   //sprite.effect(&recolor);

      //sprite.pos_x(16 * i);
      //sprite.pos_y(0);
      //sprite.texture(sprite.texture()->next());
      




   while(1)
   {

      usleep(1000000);

      if (sprite.pos_x() < (screen_size_x_pixels - texture_size_x_pixels)) sprite.pos_x(sprite.pos_x() + 1);
   
      filter.red(filter.red() + 1);
      filter.blue(filter.blue() - 5);
      display.draw(&sprite);
   }
}