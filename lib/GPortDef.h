//===============================================
#ifndef _GPortDef_
#define _GPortDef_
//===============================================
#include "GTypeDef.h"
//===============================================
#define PORT P1
//===============================================
#define INPUT P1
#define OUTPUT P2
//===============================================
#define LED P1
sbit LED0 = LED^0;
sbit LED6 = LED^6;
sbit LED7 = LED^7;
//===============================================
#define BUTTON P1
sbit BUTTON0 = BUTTON^0;
sbit BUTTON1 = BUTTON^1;
sbit BUTTON2 = BUTTON^2;
sbit BUTTON3 = BUTTON^3;
//===============================================
#define LIGHT P1
sbit LIGHT_RED_L1 = LIGHT^0;
sbit LIGHT_AMBER_L1 = LIGHT^1;
sbit LIGHT_GREEN_L1 = LIGHT^2;
sbit LIGHT_RED_L2 = LIGHT^5;
sbit LIGHT_AMBER_L2 = LIGHT^6;
sbit LIGHT_GREEN_L2 = LIGHT^7;
//===============================================
#endif
//===============================================
