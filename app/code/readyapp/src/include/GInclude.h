//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#if defined(_SDCC_) /* SDCC C Compiler */
#include <8052.h>
#elif defined(_KEIL_)  /* Keil µVision C Compiler */
#include <reg52.h> 
#endif
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
#if defined(_SDCC_) /* SDCC C Compiler */
typedef __bit GBit; 
typedef __code uchar GCode; 
#elif defined(_KEIL_)  /* Keil µVision C Compiler */
typedef bit GBit; 
typedef code uchar GCode; 
#endif
//===============================================
#endif
//=============================================== 
