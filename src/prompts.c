#include "prompts.h"
#include "screenRoutines.h"
#include <sys/timers.h>

void promptuser(char *prompt,  char *buf, size_t bufsize){
    gfx_PrintStringXY(prompt, 20,140);
    gfx_PrintStringXY(":",20,160);
    kb_key_t pressed;
    int i = 0;
    int freezeCounter = 0;
    bool shouldRun = true;
    do{
        buf[i] = '\0';
        clsxy(320,80,0,180);
        gfx_PrintStringXY(buf,10,200);
        pressed = kb_ScanGroup(3);
        if(pressed){
            switch (pressed)
            {
            case kb_0:
                buf[i] = '0';
                break;
            case kb_1:
                buf[i] = '1';
                break;      
            case kb_4:
                buf[i] = '4';
                break;
            case kb_7:
                buf[i] = '7';
                break;
            case kb_Comma:
                if(i > 0){
                    buf[i] = 0;
                    i--;
                    buf[i] = '\0';
                    i--;
                }
                break;     
            default:
                shouldRun = false;
                break;
            }
            goto skip;
        }    
        if(!pressed)
            pressed = kb_ScanGroup(4);
        if(pressed){
            switch (pressed)
            {
            case kb_2:
                buf[i] = '2';
                break;
            case kb_5:
                buf[i] = '5';
                break;      
            case kb_8:
                buf[i] ='8';
                break;  
            default:
                shouldRun = false;
                break;
            }
            goto skip;
        }    

        if(!pressed)
            pressed = kb_ScanGroup(5);
        if(pressed){
            switch (pressed)
            {
            case kb_2:
                buf[i] = '2';
                break;
            case kb_5:
                buf[i] = '5';
                break;      
            case kb_8:
                buf[i] = '8';
                break;  
            default:
                shouldRun = false;
                break;
            }
        }   

        skip:

        if(pressed){i++;freezeCounter = 100;}
        pressed = 0;
        delay(freezeCounter);
    }while(shouldRun);
}

uint8_t scanf(void){

}

uint8_t get_single_key_pressed(void) {
    static uint8_t last_key;
    uint8_t only_key = 0;
    kb_Scan();
    for (uint8_t key = 1, group = 7; group; --group) {
        for (uint8_t mask = 1; mask; mask <<= 1, ++key) {
            if (kb_Data[group] & mask) {
                if (only_key) {
                    last_key = 0;
                    return 0;
                } else {
                    only_key = key;
                }
            }
        }
    }
    if (only_key == last_key) {
        return 0;
    }
    last_key = only_key;
    return only_key;
}