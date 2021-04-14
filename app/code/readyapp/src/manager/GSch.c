//===============================================
#include "GSch.h"
//===============================================
#define TIME_MS (1) // ms
#define PRELOAD01 (65536 - ((OSC_FREQ * TIME_MS) / (OSC_PER_INST * 1000))) // ms
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)
//===============================================
#define SCH_MAX_TASKS (8)
//===============================================
typedef struct _sGTask sGTask;
//===============================================
struct _sGTask {
    void (*pTask)();
    uint delay;
    uint period;
    uchar run_me;
};
//===============================================
sGTask g_task_map[SCH_MAX_TASKS];
//===============================================
// functions
//===============================================
static void GSch_Go_To_Sleep();
static void GSch_Delete_Task(const uchar index);
//===============================================
// private
//===============================================
static void GSch_Go_To_Sleep() {
    PCON |= 0x01;
}
//===============================================
static void GSch_Delete_Task(const uchar index) {
    g_task_map[index].pTask = 0x0000;
    g_task_map[index].delay = 0;
    g_task_map[index].period = 0;
    g_task_map[index].run_me = 0;
}
//===============================================
#if defined(_SDCC_) /* SDCC C Compiler */
void GSch_Update() __interrupt(INTERRUPT_TIMER_T2) 
#elif defined(_KEIL_) /* Keil µVision C Compiler */
void GSch_Update() interrupt INTERRUPT_TIMER_T2 
#endif
{
    uchar index;
    TF2 = 0;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(g_task_map[index].pTask != 0) {
            if(g_task_map[index].delay == 0) {
                g_task_map[index].run_me += 1;
                if(g_task_map[index].period != 0) {
                    g_task_map[index].delay = g_task_map[index].period;
                }
            }
            else {
                g_task_map[index].delay -= 1;
            }
        }
    }
}
//===============================================
// public
//===============================================
void GSch_Init() {
    uchar index;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        GSch_Delete_Task(index);
    }
    T2CON = 0x00; 
    TH2 = PRELOAD01H; 
    RCAP2H = PRELOAD01H; 
    TL2 = PRELOAD01L; 
    RCAP2L = PRELOAD01L;
    ET2 = 1;
    TR2 = 1;
}
//===============================================
void GSch_Start() {
    EA = 1;
}
//===============================================
void GSch_Dispatch_Tasks() {
    uchar index;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(g_task_map[index].run_me > 0) {
            (*g_task_map[index].pTask)();
            g_task_map[index].run_me -= 1;
            if(g_task_map[index].period == 0) {
                GSch_Delete_Task(index);
            }
        }
    }
    GSch_Go_To_Sleep();
}
//===============================================
void GSch_Add_Task(void (*pTask)(), const uint delay, const uint period) {
    uchar index = 0;
    while((g_task_map[index].pTask != 0) && (index < SCH_MAX_TASKS)) index++;
    if(index == SCH_MAX_TASKS) return;
    g_task_map[index].pTask = pTask;
    g_task_map[index].delay = delay;
    g_task_map[index].period = period;
    g_task_map[index].run_me = 0;
}
//===============================================
