//===============================================
#include "GLed_Direction.h"
#include "GPort.h"
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
#define PORT_ON (0x00)
#define PORT_OFF (~PORT_ON)
//===============================================
static uchar g_led_port;
static uchar g_led_size;
static char g_led_count;
static char g_led_offset;
static char g_led_count_2;
static char g_led_offset_2;
//===============================================
void GLed_Direction_Init(uchar port, uchar size, char offset) {
    g_led_port = port;
    g_led_size = size;
    g_led_offset = offset;
    g_led_count = g_led_offset;
    g_led_offset_2 = g_led_offset - 2;
    g_led_count_2 = g_led_count - 2;
    GPort_Data_Write(g_led_port, PORT_OFF);
    GPort_Data_Shift(g_led_port, g_led_size, g_led_count);
}
//===============================================
void GLed_Direction_Update() {
    GPort_Data_Write(g_led_port, PORT_OFF);
    GPort_Data_Shift(g_led_port, g_led_size, g_led_count);
    if(++g_led_count > 7) {g_led_count = g_led_offset;}
}
//===============================================
void GLed_Direction_Update_2() {
    GPort_Data_Shift(g_led_port, g_led_size, g_led_count_2);
    if(++g_led_count_2 > 7) {g_led_count_2 = g_led_offset_2;}
}
//===============================================
