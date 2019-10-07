#include <stdio.h>
#include "hal.h"
#include "sprite_manager.h"
#include "sprite.h"

int main()
{
   Sprite_manager manager;

   auto data = manager.open("mark.bmp");

   h_display_init();

   Sprite spr = data;

   spr.draw(0, 0);


   for (int i = 0; i < 15; i++)
   {
      spr.draw(0, i * 16, i * 10);
   }
   
   

   while(1);
}