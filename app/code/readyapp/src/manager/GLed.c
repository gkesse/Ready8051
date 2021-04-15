//===============================================
#include "GLed.h"
#include "GPort.h"
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
//===============================================
static uchar g_led_port;
static uchar g_led_pin;
static uchar g_led_state;
//===============================================
void GLed_Flash_Init(uchar port, uchar pin) {
    g_led_port = port;
    g_led_pin = pin;
    g_led_state = LED_OFF;
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
}
//===============================================
void GLed_Flash_Update() {
    GPort_Bit_Write(g_led_port, g_led_pin, g_led_state);
    g_led_state = !g_led_state;
}
//=============================================== 
