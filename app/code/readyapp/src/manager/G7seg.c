//===============================================
#include "G7seg.h"
#include "GPort.h"
//===============================================
static uchar g_7seg_port;
static uchar g_digit_count;
//===============================================
static GCode g_digit_map[] = {
    //0   1     2     3     4     5     6     7     8     9
    0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10
};
//===============================================
static uchar g_digit_size = sizeof(g_digit_map);
//===============================================
static void G7seg_Data_Write(uchar d);
//===============================================
void G7seg_Init(uchar port) {
    g_7seg_port = port;
    g_digit_count = 0;
    G7seg_Data_Write(0x7F);
}
//===============================================
static void G7seg_Data_Write(uchar d) {
    uchar l_mask = 0x80;
    uchar l_data_mask = (~l_mask) & d;
    uchar l_data_port = GPort_Data_Read(g_7seg_port);
    uchar l_port_mask = l_mask & l_data_port;
    uchar l_data = l_data_mask | l_port_mask;
    GPort_Data_Write(g_7seg_port, l_data);
}
//===============================================
void G7seg_Digit_Write(uchar d) {
    uchar l_digit = g_digit_map[d];;
    G7seg_Data_Write(l_digit);
}
//===============================================
void G7seg_Update() {
    G7seg_Digit_Write(g_digit_count);
    g_digit_count += 1;
    if(g_digit_count >= g_digit_size) {g_digit_count = 0;}
}
//===============================================
