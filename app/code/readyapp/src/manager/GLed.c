//===============================================
#include "GLed.h"
#include "GPort.h"
//===============================================
static uchar g_led_port;
static uchar g_led_pin;
static GBit g_led_state;
//===============================================
void GLed_Init(uchar port, uchar pin) {
    g_led_port = port;
    g_led_pin = pin;
    g_led_state = 0;
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//===============================================
void GLed_Update() {
    g_led_state = !g_led_state;
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//=============================================== 
