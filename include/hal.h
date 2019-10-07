#ifndef _hal_h
#define _hal_h

void h_display_init();
void h_display_clear();
void h_display_put_pixel(int x, int y, int r, int g, int b, int a);
void h_display_flip();
void h_wait(int ms);

#endif