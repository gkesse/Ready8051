//===============================================
#include "GProcess.h"
#include "GSch.h"
#include "GLed.h"
#include "GLed_Count.h"
#include "GLed_Direction.h"
#include "GLedButton.h"
#include "GButton.h"
#include "GBip.h"
#include "G7seg.h"
#include "GUart.h"
//===============================================
static void GProcess_Led_Flash();
static void GProcess_Led_Count();
static void GProcess_Led_Direction();
static void GProcess_Button();
static void GProcess_Bip();
static void GProcess_7seg();
static void GProcess_Uart();
//===============================================
// public
//===============================================
void GProcess_Init(eGProcess key) {
    if(key == Led_Flash) {GProcess_Led_Flash(); return;}
    if(key == Led_Count) {GProcess_Led_Count(); return;}
    if(key == Led_Direction) {GProcess_Led_Direction(); return;}
    if(key == Button) {GProcess_Button(); return;}
    if(key == Bip) {GProcess_Bip(); return;}
    if(key == G7seg) {GProcess_7seg(); return;}
    if(key == Uart) {GProcess_Uart(); return;}
}
//===============================================
// private
//===============================================
static void GProcess_Led_Flash() {
    GLed_Flash_Init(1, 7);
    GSch_Add_Task(GLed_Flash_Update, 0, 500);
}
//===============================================
static void GProcess_Led_Count() {
    GLed_Count_Init(1, 3);
    GSch_Add_Task(GLed_Count_Update, 0, 500);
}
//===============================================
static void GProcess_Led_Direction() {
    GLed_Direction_Init(1, 3, -3);
    GSch_Add_Task(GLed_Direction_Update, 0, 500);
    GSch_Add_Task(GLed_Direction_Update_2, 1, 500);
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
    GSch_Add_Task(GBip_Update_2, 3, 200);
}
//===============================================
static void GProcess_7seg() {
    G7seg_Init(3);
    GSch_Add_Task(G7seg_Update, 0, 500);
}
//===============================================
static void GProcess_Uart() {
    GUart_Init(9600);
    GSch_Add_Task(GUart_Update_Read, 0, 10);
    GSch_Add_Task(GUart_Update_Write, 1, 10);
    GSch_Add_Task(GUart_Update_3, 3, 1000);
}
//=============================================== 
