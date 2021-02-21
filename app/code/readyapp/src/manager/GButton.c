//===============================================
#include "GButton.h"
#include "GPort.h"
//===============================================
static uchar g_button_port;
static uchar g_button_pin;
static GBit g_led_state;
//===============================================
void GButton_Init(uchar port, uchar pin) {
    g_button_port = port;
    g_button_pin = pin;
    g_led_state = 1;
    GPort_Bit_Write(g_button_port, g_button_pin, 1);
}
//===============================================
void GButton_Update() {
    g_led_state = GPort_Bit_Read(g_button_port, g_button_pin);
}
//===============================================
GBit GButton_Get_State() {
    return g_led_state;
}
//=============================================== 
