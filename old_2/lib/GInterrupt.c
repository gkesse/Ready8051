//===============================================
#include "GInterrupt.h"
#include "GLed.h"
#include "GButton.h"
//===============================================
#define PRELOAD (65536 - ((OSC_FREQ * 10) / (OSC_PER_INST * 1000))) // ms
#define PRELOADH (PRELOAD / 256)
#define PRELOADL (PRELOAD % 256)
//===============================================
void GTimer_T0_Reload();
void GTimer_T1_Reload();
//===============================================
void GInterrupt_Start() {
    EA = 1;
}
//===============================================
void GTimer_T0_Reload() {
    TR0 = 0;
    TH0 = PRELOADH;
    TL0 = PRELOADL;
    TR0 = 1;
}
//===============================================
void GTimer_T1_Reload() {
    TR1 = 0;
    TH1 = PRELOADH;
    TL1 = PRELOADL;
    TR1 = 1;
}
//===============================================
void GTimer_T0_Init() {
    TMOD &= 0xF0;
    TMOD |= 0x01;
    GTimer_T0_Reload();
    ET0 = 1; 
}
//===============================================
void GTimer_T1_Init() {
    TMOD &= 0x0F;
    TMOD |= 0x10;
    GTimer_T1_Reload();
    ET1 = 1; 
}
//===============================================
void GTimer_T2_Init() {
    T2CON = 0x00; 
    TH2 = PRELOADH; 
    RCAP2H = PRELOADH; 
    TL2 = PRELOADL; 
    RCAP2L = PRELOADL;
    ET2 = 1;
    TR2 = 1;
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T0() __interrupt(INTERRUPT_TIMER_T0) 
#else /* Keil µVision C Compiler */
void GInterrupt_Timer_T0() interrupt INTERRUPT_TIMER_T0 
#endif
{
    GTimer_T0_Reload();
    GButton_Scan();
    GButton_Update();
    GLed_Left_Right();
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T1() __interrupt(INTERRUPT_TIMER_T1) 
#else /* Keil µVision C Compiler */
void GInterrupt_Timer_T1() interrupt INTERRUPT_TIMER_T1 
#endif
{
    GTimer_T1_Reload();
    GButton_Scan();
    GButton_Update();
    GLed_Left_Right();
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T2() __interrupt(INTERRUPT_TIMER_T2) 
#else /* Keil µVision C Compiler */
void GInterrupt_Timer_T2() interrupt INTERRUPT_TIMER_T2 
#endif
{
    TF2 = 0;
    GButton_Scan();
    GButton_Update();
    GLed_Left_Right();
}
//===============================================
