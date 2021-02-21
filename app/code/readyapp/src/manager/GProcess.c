//===============================================
#include "GProcess.h"
#include "GSch.h"
#include "GLed.h"
//===============================================
static void GProcess_Led_Blink();
//===============================================
// public
//===============================================
void GProcess_Init(eGProcess key) {
    if(key == Led_Blink) {GProcess_Led_Blink(); return;}
}
//===============================================
// private
//===============================================
static void GProcess_Led_Blink() {
    GLed_Init(1, 7);
    GSch_Add_Task(GLed_Update, 0, 1000);
}
//=============================================== 
