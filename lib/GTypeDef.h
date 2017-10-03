//===============================================
#ifndef _GTypeDef_
#define _GTypeDef_
//===============================================
#include <reg52.h>
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
typedef __bit GBit; 
#else /* Keil µVision C Compiler */
typedef bit GBit; 
#endif
//===============================================
#ifndef TRUE
#define FALSE (0)
#define TRUE (!FALSE)
#endif
//===============================================
#ifndef LOCKED
#define UNLOCKED (0)
#define LOCKED (!UNLOCKED)
#endif
//===============================================
#define COOP (1)
#define PREEMP (!COOP)
//===============================================
#define OSC_FREQ (11059200)
#define OSC_PER_INST (12)
//===============================================
#define INTERRUPT_TIMER_T0 1
#define INTERRUPT_TIMER_T1 3
#define INTERRUPT_TIMER_T2 5
//===============================================
#define LED_OFF (1)
#define LED_ON (!LED_OFF)
//===============================================
#define BUTTON_OFF (1)
#define BUTTON_ON (!BUTTON_OFF)
//===============================================
#define LIGHT_OFF (1)
#define LIGHT_ON (!LIGHT_OFF)
#define LIGHT_GREEN_DURATION (3)
#define LIGHT_AMBER_DURATION (2)
#define LIGHT_RED_RED_DURATION (1)
#define LIGHT_RED_DURATION (LIGHT_GREEN_DURATION)
#define LIGHT_RED_AMBER_DURATION (LIGHT_AMBER_DURATION)
#define LIGHT_RED_RED_1_DURATION (LIGHT_RED_RED_DURATION)
#define LIGHT_RED_RED_2_DURATION (LIGHT_RED_RED_DURATION)
//===============================================
#endif
//===============================================
