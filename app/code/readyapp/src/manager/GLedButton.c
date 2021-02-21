//===============================================
#include "GLedButton.h"
#include "GButton.h"
#include "GPort.h"
//===============================================
static uchar g_led_port;
static uchar g_led_pin;
//===============================================
void GLedButton_Init(uchar port, uchar pin) {
    g_led_port = port;
    g_led_pin = pin;
    GPort_Bit_Write(g_led_port, g_led_pin, 1);
}
//===============================================
void GLedButton_Update() {
    GBit l_led_state = GButton_Get_State();
    GPort_Bit_Write(g_led_port, g_led_pin, l_led_state);
}
//=============================================== 
