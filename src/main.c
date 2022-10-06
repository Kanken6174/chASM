/*
 *--------------------------------------
 * Program Name: chASM
 * Author: Yorick Geoffre
 * License:
 * Description:
 *--------------------------------------
*/
#include "main.h"
int freezeCounter = 0;
int menuindex = 0;
char menuitems[menuitemsAmount][64] = {"calculateur de debits","resumes lecon","autres","infos"};
bool run = true;
kb_key_t key, prevkey;

int main(void)
{
    /* Initialize graphics drawing */
    gfx_Begin();

    /* Set the text colors */
    gfx_SetTextFGColor(0);
    gfx_SetTextBGColor(255);
    fontlib_SetBackgroundColor(0);

    do{ 
        DrawMenu();
        processKeys();
        do{freezeCounter--;}while(run && (kb_AnyKey() == 0 || freezeCounter > 0) /*&& (!key || key == prevkey)*/);
        freezeCounter = 100;
    }while (run);
    

    /* End graphics drawing */
    gfx_End();

    return 0;
}

void MoveCursor(int amount){
    menuindex += amount;
    if(menuindex >= menuitemsAmount)
        menuindex = 0;
    else if(menuindex < 0)
    menuindex = menuitemsAmount-1;
    cls(40,240);
    gfx_PrintStringXY(">",TEXT_X_OFFSET,(TEXT_Y_OFFSET+(menuindex*TEXT_Y_OFFSET)));
}

void processKeys(){
    kb_Scan();
    key = kb_Data[7];
    int amount = 0;
    switch (key)
    {
    case kb_Down:
        amount++;
        break;
    case kb_Up:
        amount--;
        break;
    case kb_Left:
        run = false;
        break;
    case kb_Right:
        switch (menuindex)
        {
        case 0:
            bandwithCalculator();
        break;
        case 1:
            clss();
            promptuser("CMACD: tDIFS+tSIFS+(ACK*temps)+tbackoff+tdata",NULL,NULL);
            clss();
            promptuser("RTSCTS: tDIFS+(RTS*temps)+SIFS+(CTS*temps)+SIFS+tdata+SIFS+(ACKtemps)+backoff",NULL,NULL);
            clss();
        break;
        default:
        break;
        }
        DrawMenu();
        break;
    default:
        break;
    }
    MoveCursor(amount);
}

/* Simple way to fill the screen with a given color */
void FillScreen(uint8_t color)
{
    memset((void*)lcd_Ram, color, LCD_SIZE);
}

void DrawTitle(){
    gfx_SetTextScale(1, 1);
}

void DrawMenu()
{
    gfx_SetTextScale(1, 1);
    for(int i = 0; i < menuitemsAmount; i++){
        gfx_PrintStringXY(menuitems[i], X_INITIAL_OFFSET+TEXT_X_OFFSET, TEXT_Y_OFFSET+(i*TEXT_Y_OFFSET));
    }
}