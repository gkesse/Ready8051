//===============================================
#include "GButton.h"
#include "GPort.h"
//===============================================
static uchar g_button_port;
static uchar g_button_pin;
static GBit g_button_state;
//===============================================
void GButton_Init(uchar port, uchar pin) {
    g_button_port = port;
    g_button_pin = pin;
    g_button_state = 1;
    GPort_Bit_Write(g_button_port, g_button_pin, 1);
}
//===============================================
void GButton_Update() {
    GBit l_button_state = GPort_Bit_Read(g_button_port, g_button_pin);
    if(l_button_state == 0) {
        g_button_state = 1;
    }
}
//===============================================
void GButton_Init_State() {
    g_button_state = 0;
}
//=============================================== 
