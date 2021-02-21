//===============================================
#include "GProcess.h"
#include "GSch.h"
#include "GLed.h"
//===============================================
static void GProcess_led_blink();
//===============================================
// public
//===============================================
void GProcess_Init(eGProcess key) {
    if(key == led_blink) {GProcess_led_blink(); return;}
}
//===============================================
// private
//===============================================
void GProcess_led_blink() {
    GLed_Init();
    GSch_Add_Task(GLed_Update, 0, 1000);
}
//=============================================== 
