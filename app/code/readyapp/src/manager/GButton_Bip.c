//===============================================
#include "GButton_Bip.h"
#include "GButton.h"
#include "GPort.h"
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
//===============================================
static uchar g_bip_port;
static uchar g_bip_pin;
static uint g_bip_state;
static uint g_bip_flag;
static uint g_bip_time;
//===============================================
void GButton_Bip_Init(uchar port, uchar pin, uint time) {
    g_bip_port = port;
    g_bip_pin = pin;
    g_bip_time = time;
    g_bip_state = LED_OFF;
    g_bip_flag = 0;
    GPort_Bit_Write(g_bip_port, g_bip_pin, g_bip_state);
}
//===============================================
void GButton_Bip_Read_Update() {
    GBit l_button_state = GButton_State_Get();
    GButton_State_Init();
    if(l_button_state == 1) {g_bip_flag = !g_bip_flag;}
    if(g_bip_flag == 0) {GPort_Bit_Write(g_bip_port, g_bip_pin, LED_OFF);}
}
//===============================================
void GButton_Bip_Flash_Update() {
    if(g_bip_flag == 0) {return;}
    g_bip_state = !g_bip_state;
    GPort_Bit_Write(g_bip_port, g_bip_pin, g_bip_state);
}
//=============================================== 
