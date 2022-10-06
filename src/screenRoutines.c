#include <graphx.h>
#include <sys/lcd.h>
//clears the screen entirely
void clss(){
    gfx_SetColor(255);
    gfx_FillRectangle(0,0,320,240);
    gfx_SetColor(0);
}

//clears the screen from 0:0
void cls(unsigned int w, unsigned int h){
    gfx_SetColor(255);
    gfx_FillRectangle(0,0,w,h);
    gfx_SetColor(0);
}

void clsxy(unsigned int w, unsigned int h, unsigned int x, unsigned int y){
    gfx_SetColor(255);
    gfx_FillRectangle(x,y,w,h);
    gfx_SetColor(0);
}