//===============================================
#include "GLed_Button.h"
#include "GButton.h"
#include "GPort.h"
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
//===============================================
static uchar g_led_port;
static uchar g_led_pin;
static uchar g_led_state;
//===============================================
void GLed_Button_Init(uchar port, uchar pin) {
    g_led_port = port;
    g_led_pin = pin;
    g_led_state = LED_OFF;
    GPort_Bit_Write(g_led_port, g_led_pin, LED_OFF);
}
//===============================================
void GLed_Button_Update() {
    GBit l_button_state = GButton_State_Get();
    GButton_State_Init();
    if(l_button_state == 1) {g_led_state = !g_led_state;}
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//=============================================== 
