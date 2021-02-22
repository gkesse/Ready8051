//===============================================
#include "GLedButton.h"
#include "GButton.h"
#include "GPort.h"
//===============================================
static uchar g_led_port;
static uchar g_led_pin;
static uchar g_led_state;
//===============================================
void GLedButton_Init(uchar port, uchar pin) {
    g_led_port = port;
    g_led_pin = pin;
    g_led_state = 1;
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//===============================================
void GLedButton_Update() {
    GBit l_button_state = GButton_Get_State();
    GButton_Init_State();
    if(l_button_state == 1) {g_led_state = !g_led_state;}
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//=============================================== 
