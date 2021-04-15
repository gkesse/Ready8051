//===============================================
#include "GLed_Count.h"
#include "GPort.h"
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
#define PORT_ON (0x00)
#define PORT_OFF (~PORT_ON)
//===============================================
static uchar g_led_port;
static uchar g_led_count;
//===============================================
void GLed_Count_Init(uchar port, uchar start) {
    g_led_port = port;
    g_led_count = start;
    GPort_Data_Write(g_led_port, PORT_OFF);
}
//===============================================
void GLed_Count_Update() {
    GPort_Data_Write(g_led_port, PORT_OFF);
    GPort_Bit_Write(g_led_port, g_led_count, LED_ON);
    if(++g_led_count > 7) {g_led_count = 0;}
}
//===============================================
