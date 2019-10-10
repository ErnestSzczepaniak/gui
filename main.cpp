#include "texture.h"
#include "loader.h"
#include "display.h"

int main()
{
   Loader loader;
   Display display;

   display.init();

   auto * texture = loader.load("test_screen.bmp", 5);

   display.draw(texture, 0, 0);

   while(1);
}