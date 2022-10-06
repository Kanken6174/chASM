#include "bandwithCalculator.h"

void bandwithCalculator(){
    bool ShouldRun = true;
    char buff[255] = "";
    clss();
    os_FontSelect(os_SmallFont);
    while(ShouldRun){
        ShouldRun = false;
        promptuser("Debit (byte/micros) [1mb = 1b/micros]:",buff,255);
        clss();
        promptuser(buff,buff,255);
    }
}

struct IPLatencyValuesMicroseconds makeIPLStructDefault(unsigned long int bandwithBytePerSecond){
    struct IPLatencyValuesMicroseconds ipl;
    ipl.backoff = 20;
    ipl.data = 0;
    ipl.DIFS = 128;
    ipl.SIFS = 28;
    ipl.msPerByte = bandwithBytePerSecond/1000000;   //
    return ipl;
}

struct byteSizeStruct makeBSSStructDefault(){
    struct byteSizeStruct bss;
    bss.ACK = 14;
    bss.MACHeader = 34;
    bss.PhysHeader = 24;
    bss.RTS = 20;
    bss.CTS = 20;
    bss.data = 0;
    return bss;
}

void DrawBandwithCalc(){
    clss();
}

unsigned long calculateCMACDLatencyMs(struct IPLatencyValuesMicroseconds lv, struct byteSizeStruct bs)
{
    unsigned long result = lv.DIFS+lv.SIFS+(bs.ACK*lv.msPerByte)+lv.backoff;
    return result;
}

unsigned long calculateRTSCTSLatencyMs(struct IPLatencyValuesMicroseconds lv, struct byteSizeStruct bs)
{
    unsigned long result = lv.DIFS+(bs.RTS*lv.msPerByte)+lv.SIFS+(bs.CTS*lv.msPerByte)+lv.SIFS+0+lv.SIFS+(bs.ACK*lv.msPerByte)+lv.backoff;
    return result;
}