//===============================================
#include "GProcess.h"
#include "GSch.h"
#include "GLed.h"
#include "GLedButton.h"
#include "GButton.h"
#include "GBip.h"
#include "GDebounce.h"
#include "G7seg.h"
//===============================================
static void GProcess_Led_Blink();
static void GProcess_Button();
static void GProcess_Bip();
static void GProcess_Debounce();
static void GProcess_7seg();
//===============================================
// public
//===============================================
void GProcess_Init(eGProcess key) {
    if(key == Led_Blink) {GProcess_Led_Blink(); return;}
    if(key == Button) {GProcess_Button(); return;}
    if(key == Bip) {GProcess_Bip(); return;}
    if(key == G7seg) {GProcess_7seg(); return;}
    if(key == Debounce) {GProcess_Debounce(); return;}
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
static void GProcess_Bip() {
    GButton_Init(1, 6);
    GBip_Init(1, 7, 1000);
    GSch_Add_Task(GButton_Update, 0, 10);
    GSch_Add_Task(GBip_Update, 1, 200);
    GSch_Add_Task(GBip_Update_T2, 3, 200);
}
//===============================================
static void GProcess_7seg() {
    G7seg_Init(3);
    GSch_Add_Task(G7seg_Update, 0, 500);
}
//===============================================
static void GProcess_Debounce() {
    GDebounce_Init(1, 6);
    GSch_Add_Task(GDebounce_Update, 0, 10);
}
//=============================================== 
