//===============================================
#include "GDebounce.h"
#include "GPort.h"
//===============================================
static uchar g_debounce_port;
static uchar g_debounce_pin;
static GBit g_debounce_state;
static GBit g_debounce_ctn0;
static GBit g_debounce_ctn1;
//===============================================
void GDebounce_Init(uchar port, uchar pin) {
    g_debounce_port = port;
    g_debounce_pin = pin;
    g_debounce_state = 0;
    g_debounce_ctn0 = 0;
    g_debounce_ctn1 = 0;
    GPort_Bit_Write(g_debounce_port, g_debounce_pin, 1);
}
//===============================================
void GDebounce_Update() {
    GBit l_debounce_sample = GPort_Bit_Read(g_debounce_port, g_debounce_pin);
    GBit l_debounce_delta = l_debounce_sample ^ g_debounce_state;
    g_debounce_ctn1 = (g_debounce_ctn1 ^ g_debounce_ctn0) & (l_debounce_delta & l_debounce_sample);
    g_debounce_ctn0 = ~g_debounce_ctn0 & (l_debounce_delta & l_debounce_sample);
    g_debounce_state ^= (l_debounce_delta & ~(g_debounce_ctn0 | g_debounce_ctn1));
    GPort_Bit_Write(3, 5, g_debounce_ctn0);
    GPort_Bit_Write(3, 6, g_debounce_ctn1);
    GPort_Bit_Write(3, 7, g_debounce_state);
}
//===============================================
GBit GDebounce_Get_State() {
    return g_debounce_state;
}
//===============================================
