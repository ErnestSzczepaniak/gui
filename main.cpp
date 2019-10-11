#include "texture.h"
#include "loader.h"
#include "display.h"
#include "effect_recolor.h"
#include "sprite.h"

int main()
{
   Loader loader;
   Display display;
   Effect_recolor recolor;
   Sprite sprite;

   display.init();

   auto [texture, count] = loader.load("test_screen.bmp");

   sprite.texture(texture);
   sprite.effect(&recolor);

   for (int i = 0; i < 10; i++)
   {
      sprite.pos_x(16 * i);
      sprite.pos_y(16 * i);
      recolor.set_red(i * 30);
      display.draw(&sprite);
   }



   while(1);
}