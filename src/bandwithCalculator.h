#include <ti/getcsc.h>
#include <graphx.h>
#include <sys/lcd.h>
#include <keypadc.h>
#include <fontlibc.h>
#include <string.h>
#include <ti/screen.h>

#include "screenRoutines.h"
#include "prompts.h"

struct IPLatencyValuesMicroseconds{
    unsigned int DIFS;
    unsigned int data;
    unsigned int SIFS;
    unsigned int backoff;
    unsigned long int msPerByte;   //microseconds per byte
};

struct byteSizeStruct{
    unsigned int data;
    unsigned int ACK;
    unsigned int RTS;
    unsigned int CTS;
    unsigned int MACHeader;
    unsigned int PhysHeader;
};

struct IPLatencyValuesMicroseconds makeIPLStructDefault(unsigned long int bandwithBytePerSecond);
struct byteSizeStruct makeBSSStructDefault();
void bandwithCalculator();
void DrawBandwithCalc();
unsigned long calculateCMACDLatencyMs(struct IPLatencyValuesMicroseconds lv, struct byteSizeStruct bs);
unsigned long calculateRTSCTSLatencyMs(struct IPLatencyValuesMicroseconds lv, struct byteSizeStruct bs);