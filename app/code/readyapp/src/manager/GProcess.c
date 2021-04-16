//===============================================
#include "GProcess.h"
#include "GSch.h"
#include "GLed.h"
#include "GLed_Count.h"
#include "GLed_Direction.h"
#include "GLed_Button.h"
#include "GButton.h"
#include "GButton_Bip.h"
#include "GButton_Switch.h"
#include "G7seg.h"
#include "GUart.h"
//===============================================
static void GProcess_Led_Flash();
static void GProcess_Led_Count();
static void GProcess_Led_Direction();
static void GProcess_Button();
static void GProcess_Button_Bip();
static void GProcess_Button_Switch();
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
    if(key == Button_Bip) {GProcess_Button_Bip(); return;}
    if(key == Button_Switch) {GProcess_Button_Switch(); return;}
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
    GLed_Count_Init(1, 0);
    GSch_Add_Task(GLed_Count_Update, 0, 500);
}
//===============================================
static void GProcess_Led_Direction() {
    GLed_Direction_Init(1, 3, -3);
    GSch_Add_Task(GLed_Direction_Update, 0, 500);
    GSch_Add_Task(GLed_Direction_Update_2, 3007, 500);
}
//===============================================
static void GProcess_Button() {
    GButton_Init(3, 7);
    GLed_Button_Init(1, 7);
    GSch_Add_Task(GButton_Read_Update, 0, 200);
    GSch_Add_Task(GLed_Button_Update, 3, 200);
}
//===============================================
static void GProcess_Button_Bip() {
    GButton_Init(3, 7);
    GButton_Bip_Init(1, 7, 1000);
    GSch_Add_Task(GButton_Read_Update, 0, 200);
    GSch_Add_Task(GButton_Bip_Read_Update, 3, 200);
    GSch_Add_Task(GButton_Bip_Flash_Update, 5, 200);
}
//===============================================
static void GProcess_Button_Switch() {
    GButton_Switch_Init(3, 1);
    GSch_Add_Task(GButton_Switch_Read_Update, 0, 200);
    GSch_Add_Task(GButton_Switch_Write_Update, 3, 200);
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
    GSch_Add_Task(GUart_Update_Write, 3, 10);
    GSch_Add_Task(GUart_Update_3, 5, 1000);
}
//=============================================== 
