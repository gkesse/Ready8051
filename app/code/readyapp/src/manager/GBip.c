//===============================================
#include "GBip.h"
#include "GButton.h"
#include "GPort.h"
//===============================================
static uchar g_bip_port;
static uchar g_bip_pin;
static uint g_bip_state;
static uint g_bip_flag;
static uint g_bip_time;
//===============================================
void GBip_Init(uchar port, uchar pin, uint time) {
    g_bip_port = port;
    g_bip_pin = pin;
    g_bip_time = time;
    g_bip_state = 1;
    g_bip_flag = 0;
    GPort_Bit_Write(g_bip_port, g_bip_pin, g_bip_state);
}
//===============================================
void GBip_Update() {
    GBit l_button_state = GButton_Get_State();
    GButton_Init_State();
    if(l_button_state == 1) {g_bip_flag = !g_bip_flag;}
    if(g_bip_flag == 0) {GPort_Bit_Write(g_bip_port, g_bip_pin, 1);}
}
//===============================================
void GBip_Update_2() {
    if(g_bip_flag == 0) {return;}
    g_bip_state = !g_bip_state;
    GPort_Bit_Write(g_bip_port, g_bip_pin, g_bip_state);
}
//=============================================== 
