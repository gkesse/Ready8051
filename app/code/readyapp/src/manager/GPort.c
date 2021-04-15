//===============================================
#include "GPort.h"
//===============================================
#define PORT_0 P0
#define PORT_1 P1
#define PORT_2 P2
#define PORT_3 P3
//===============================================
#define LED_ON (0)
#define LED_OFF (!LED_ON)
//===============================================
void GPort_Data_Write(uchar port, uchar d) {
    if(port == 0) {PORT_0 = d;}
    else if(port == 1) {PORT_1 = d;}
    else if(port == 2) {PORT_2 = d;}
    else if(port == 3) {PORT_3 = d;}
}
//===============================================
void GPort_Data_Shift(uchar port, uchar d, char offset) {
    char l_pin_count;
    for(l_pin_count = offset; l_pin_count < d + offset; l_pin_count++) {
        if(l_pin_count < 0) {continue;}
        if(l_pin_count > 7) {continue;}
        GPort_Bit_Write(port, l_pin_count, LED_ON);
    }
}
//===============================================
uchar GPort_Data_Read(uchar port) {
    uchar l_data = 0;
    if(port == 0) {l_data = PORT_0;}
    else if(port == 1) {l_data = PORT_1;}
    else if(port == 2) {l_data = PORT_2;}
    else if(port == 3) {l_data = PORT_3;}
    return l_data;
}
//=============================================== 
void GPort_Bit_Write(uchar port, uchar pin, GBit d) {
    uchar l_mask = 0x01;
    l_mask <<= pin;
    if(port == 0) {PORT_0 = (d == 0) ? (PORT_0 & ~l_mask) : (PORT_0 | l_mask);}
    else if(port == 1) {PORT_1 = (d == 0) ? (PORT_1 & ~l_mask) : (PORT_1 | l_mask);}
    else if(port == 2) {PORT_2 = (d == 0) ? (PORT_2 & ~l_mask) : (PORT_2 | l_mask);}
    else if(port == 3) {PORT_3 = (d == 0) ? (PORT_3 & ~l_mask) : (PORT_3 | l_mask);}
}
//=============================================== 
GBit GPort_Bit_Read(uchar port, uchar pin) {
    uchar l_mask = 0x01;
    GBit l_data = 0;
    l_mask <<= pin;
    GPort_Bit_Write(port, pin, 1);
    if(port == 0) {l_data = ((PORT_0 & l_mask) == 0) ? 0 : 1;}
    else if(port == 1) {l_data = ((PORT_1 & l_mask) == 0) ? 0 : 1;}
    else if(port == 2) {l_data = ((PORT_2 & l_mask) == 0) ? 0 : 1;}
    else if(port == 3) {l_data = ((PORT_3 & l_mask) == 0) ? 0 : 1;}
    return l_data;
}
//=============================================== 
