//===============================================
#include "GProcess.h"
#include "GSch.h"
#include "GLed.h"
#include "GLedButton.h"
#include "GButton.h"
//===============================================
static void GProcess_Led_Blink();
static void GProcess_Button();
//===============================================
// public
//===============================================
void GProcess_Init(eGProcess key) {
    if(key == Led_Blink) {GProcess_Led_Blink(); return;}
    if(key == Button) {GProcess_Button(); return;}
}
//===============================================
// private
//===============================================
static void GProcess_Led_Blink() {
    GLed_Init(1, 7);
    GSch_Add_Task(GLed_Update, 0, 1000);
}
//===============================================
static void GProcess_Button() {
    GButton_Init(1, 6);
    GLedButton_Init(1, 7);
    GSch_Add_Task(GButton_Update, 0, 200);
    GSch_Add_Task(GLedButton_Update, 1, 200);
}
//=============================================== 
