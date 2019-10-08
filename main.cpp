
#include "texture_manager.h"
#include "display.h"



// void box(int x, int y)
// {
//    auto * horizontal = manager.open("horizontal.bmp");
//    auto * vertical = manager.open("vertical.bmp");
//    auto * j1 = manager.open("junction1.bmp");
//    auto * j2 = manager.open("junction2.bmp");
//    auto * j3 = manager.open("junction3.bmp");
//    auto * j4 = manager.open("junction4.bmp");

//    display.draw(j4, 0, 0);

//    for (int i = 1; i < 30; i++)
//    {
//       //vertical->draw(x, y + i * vertical->height());
//       //vertical->draw(x + 160, y + i * vertical->height());
//    }
   
//    for (int i = 0; i < 9; i++)
//    {
//       //horizontal->draw(x + 16 + i * horizontal->width(), y + 0);
//       //horizontal->draw(x + 16 + i * horizontal->width(), y + 480);
//    }

//    //j3->draw(x + 0, y + 0);
//    //j1->draw(x + 160, y + 480);
// }

int main()
{
   Pixel p;

   p._pixel = 0xff520057;

   auto [r, g, b] = p.as_rgb();

   auto [h, s, l] = p.as_hsl();

   Texture_manager manager;
   Display display;

   auto * texture = manager.open("vertical.bmp");
   
   display.init();
   display.draw(texture, 0, 0);
   display.draw(texture, 0, 16);

   while(1);
}