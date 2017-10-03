//===============================================
#include "GTimer.h"
//===============================================
#define PRELOAD (65536 - ((OSC_FREQ * 1) / (OSC_PER_INST * 1000))) // ms
#define PRELOADH (PRELOAD / 256)
#define PRELOADL (PRELOAD % 256)
//===============================================
void GTimer_T0_Init();
void GTimer_T1_Init();
//===============================================
void GTimer_T0_Init() {
    TMOD &= 0xF0;
    TMOD |= 0x01;
    ET0 = 0;
}
//===============================================
void GTimer_T1_Init() {
    TMOD &= 0x0F;
    TMOD |= 0x10;
    ET1 = 0;
}
//===============================================
void GTimer_T0_ms(uint ms) {
    uint i;
    
    GTimer_T0_Init();
    
    for(i = 0; i < ms; i++) {
        TH0 = PRELOADH;
        TL0 = PRELOADL;
        TF0 = 0; 
        TR0 = 1; 
        while (TF0 == 0);
        TR0 = 0;    
    }
}
//===============================================
void GTimer_T1_ms(uint ms) {
    uint i;
    
    GTimer_T1_Init();
    
    for(i = 0; i < ms; i++) {
        TH1 = PRELOADH;
        TL1 = PRELOADL;
        TF1 = 0; 
        TR1 = 1; 
        while (TF1 == 0);
        TR1 = 0;    
    }
}
//===============================================
