//===============================================
#include "GSch.h"
//===============================================
#define PRELOAD01 (65536 - ((OSC_FREQ * 1) / (OSC_PER_INST * 1000))) // ms
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)
//===============================================
#define SCH_MAX_TASKS (8)
//===============================================
typedef struct _sGTask sGTask;
typedef struct _sGData sGData;
//===============================================
struct _sGTask {
    void (*pTask)();
    uint delay;
    uint period;
    uchar run_me;
};
//===============================================
struct _sGData {
    sGTask task_map[SCH_MAX_TASKS];
    uchar check_flag;
    uchar check_pin;
};
//===============================================
static sGData g_data;
//===============================================
// functions
//===============================================
static void GSch_Go_To_Sleep();
static void GSch_Delete_Task(const uchar index);
static void GSch_Check();
//===============================================
#ifdef _SDCC_ /* SDCC C Compiler */
static void GSch_Update() __interrupt(INTERRUPT_TIMER_T2); 
#endif
//===============================================
// private
//===============================================
static void GSch_Go_To_Sleep() {
    PCON |= 0x01;
}
//===============================================
static void GSch_Delete_Task(const uchar index) {
    g_data.task_map[index].pTask = 0x0000;
    g_data.task_map[index].delay = 0;
    g_data.task_map[index].period = 0;
    g_data.task_map[index].run_me = 0;
}
//===============================================
#ifdef _SDCC_ /* SDCC C Compiler */
static void GSch_Update() __interrupt(INTERRUPT_TIMER_T2) 
#else /* Keil µVision C Compiler */
static void GSch_Update() interrupt INTERRUPT_TIMER_T2 
#endif
{
    uchar index;
    TF2 = 0;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(g_data.task_map[index].pTask != 0) {
            if(g_data.task_map[index].delay == 0) {
                g_data.task_map[index].run_me += 1;
                if(g_data.task_map[index].period != 0) {
                    g_data.task_map[index].delay = g_data.task_map[index].period;
                }
            }
            else {
                g_data.task_map[index].delay -= 1;
            }
        }
    }
    GSch_Check();
}
//===============================================
static void GSch_Check() {
    if(g_data.check_flag == 0) {
        g_data.check_flag = 1;
        P1 = 0x00;
    }
    else {
        g_data.check_flag = 0;
        P1 = 0xFF;
    }
}
//===============================================
// public
//===============================================
void GSch_Init() {
    uchar index;
    g_data.check_flag = 0;
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
        if(g_data.task_map[index].run_me > 0) {
            (*g_data.task_map[index].pTask)();
            g_data.task_map[index].run_me -= 1;
            if(g_data.task_map[index].period == 0) {
                GSch_Delete_Task(index);
            }
        }
    }
    GSch_Go_To_Sleep();
}
//===============================================
void GSch_Add_Task(void (*pTask)(), const uint delay, const uint period) {
    uchar index = 0;
    while((g_data.task_map[index].pTask != 0) && (index < SCH_MAX_TASKS)) index++;
    if(index == SCH_MAX_TASKS) return;
    g_data.task_map[index].pTask = pTask;
    g_data.task_map[index].delay = delay;
    g_data.task_map[index].period = period;
    g_data.task_map[index].run_me = 0;
}
//===============================================
