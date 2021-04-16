//===============================================
#include "GButton_Switch.h"
#include "GManager.h"
#include "GPort.h"
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
//===============================================
#define BUTTON_ON (0)
#define BUTTON_OFF (!BUTTON_ON)
//===============================================
#define BUTTON_MAX (8)
//===============================================
static uchar g_port_in;
static uchar g_port_out;
static uchar g_button_state;
static uchar g_led_state;
//===============================================
void GButton_Switch_Init(uchar port_in, uchar port_out) {
    uchar l_button_count;
    
    g_port_in = port_in;
    g_port_out = port_out;
    
    for(l_button_count = 0; l_button_count < BUTTON_MAX; l_button_count++) {
        GManager_Uchar_Bit_Write(&g_button_state, l_button_count, BUTTON_OFF);
        GManager_Uchar_Bit_Write(&g_led_state, l_button_count, LED_OFF);
        GPort_Bit_Write(g_port_in, l_button_count, BUTTON_OFF);
        GPort_Bit_Write(g_port_out, l_button_count, LED_OFF);
    }
}
//===============================================
void GButton_Switch_Read_Update() {
    uchar l_button_count;
    GBit l_button_state;
    for(l_button_count = 0; l_button_count < BUTTON_MAX; l_button_count++) {
        l_button_state = GPort_Bit_Read(g_port_in, l_button_count);
        if(l_button_state == BUTTON_ON) {GManager_Uchar_Bit_Write(&g_button_state, l_button_count, BUTTON_ON);}
    }
}
//===============================================
void GButton_Switch_Write_Update() {
    uchar l_button_count;
    GBit l_button_state;
    GBit l_led_state;
    for(l_button_count = 0; l_button_count < BUTTON_MAX; l_button_count++) {
        l_button_state = GManager_Uchar_Bit_Read(g_button_state, l_button_count);
        if(l_button_state == BUTTON_ON) {
            l_led_state = GManager_Uchar_Bit_Read(g_led_state, l_button_count);
            l_led_state = !l_led_state;
            GPort_Bit_Write(g_port_out, l_button_count, l_led_state);
            GManager_Uchar_Bit_Write(&g_led_state, l_button_count, l_led_state);
            GManager_Uchar_Bit_Write(&g_button_state, l_button_count, BUTTON_OFF);
        }
    }
}
//=============================================== 
