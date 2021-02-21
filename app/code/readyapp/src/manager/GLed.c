//===============================================
#include "GLed.h"
#include "GPort.h"
//===============================================
static uchar g_led_port = 1;
static uchar g_led_pin = 7;
static GBit g_led_state = 0;
//===============================================
void GLed_Init() {
    g_led_state = 0;
    GPort_Bit_Write(g_led_port, g_led_pin, 0);
}
//===============================================
void GLed_Update() {
    g_led_state = !g_led_state;
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//=============================================== 
