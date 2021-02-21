//===============================================
#include "GBip.h"
#include "GButton.h"
#include "GPort.h"
//===============================================
static uchar g_bip_port;
static uchar g_bip_pin;
static uint g_bip_time;
//===============================================
void GBip_Init(uchar port, uchar pin, unit time) {
    g_bip_port = port;
    g_bip_pin = pin;
    g_bip_time = time;
    GPort_Bit_Write(g_bip_port, g_bip_pin, 1);
}
//===============================================
void GBip_Update() {
    GBit l_button_state = GButton_Get_State();
    GButton_Init_State();
    if(l_button_state == 1) {
        GPort_Bit_Write(g_bip_port, g_bip_pin, l_bip_state);
    }
}
//=============================================== 
