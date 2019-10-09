#include "texture.h"
#include "loader.h"

int main()
{
   Loader loader;

   loader.load("triplet.bmp", 0);

   while(1);
}