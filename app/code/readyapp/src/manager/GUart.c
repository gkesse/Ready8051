//===============================================
#include "GUart.h"
//===============================================
#define FACTOR (OSC_FREQ / (OSC_PER_INST * 32))
//===============================================
static uchar g_char = 0;
static GBit g_read_flag = 0;
//===============================================
void GUart_Init(uint baud) {
    uchar l_preload = (256 - (FACTOR / baud));
    TMOD |= 0x20;
    TH1 = l_preload;
    SCON = 0x50;
    TR1 = 1;
}
//===============================================
void GUart_Write_Char(char d) {
    if(d == 0) {return;}
    if(d == '\n') {d = 0x0D;}
    SBUF = d;
	while(TI == 0);
	TI = 0;	
}
//===============================================
void GUart_Write_String(char* d) {
    uchar l_count = 0;
    while(1) {
        char l_char = d[l_count];
        if(l_char == 0) {break;}
        GUart_Write_Char(l_char);
        l_count += 1;
    }
}
//===============================================
char GUart_Read_Char() {
    char l_data = 0;
    if(RI == 1) {
        l_data = SBUF;
        RI = 0;
    }
    return l_data;
}
//===============================================
void GUart_Update_Read() {
    if(RI == 0) {return;}
    g_char = GUart_Read_Char();
    g_read_flag = 1;
}
//===============================================
void GUart_Update_Write() {
    if(g_read_flag == 0) {return;}
    GUart_Write_Char(g_char);
    g_read_flag = 1;
}
//===============================================
void GUart_Update_3() {
    GUart_Write_String("Bonjour tout le monde\n");
}
//=============================================== 
