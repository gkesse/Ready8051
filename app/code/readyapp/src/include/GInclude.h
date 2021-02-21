//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#include <8052.h>
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
//===============================================
#define OSC_FREQ (11059200)
#define OSC_PER_INST (12)
//===============================================
#define INTERRUPT_TIMER_T0 1
#define INTERRUPT_TIMER_T1 3
#define INTERRUPT_TIMER_T2 5
//===============================================
#ifdef _SDCC_ /* SDCC C Compiler */
typedef __bit GBit; 
#else /* Keil µVision C Compiler */
typedef bit GBit; 
#endif
//===============================================
#endif
//=============================================== 
