//===============================================
#ifndef _GSch_
#define _GSch_
//===============================================
#include "GInclude.h"
//===============================================
void GSch_Init();
void GSch_Start();
void GSch_Dispatch_Tasks();
void GSch_Add_Task(void (*pTask)(), const uint delay, const uint period);
//===============================================
#if defined(_SDCC_) /* SDCC C Compiler */
void GSch_Update() __interrupt(INTERRUPT_TIMER_T2); 
#endif
//===============================================
#endif
//===============================================
