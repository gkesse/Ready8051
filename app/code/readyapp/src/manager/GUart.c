//===============================================
#include "GUart.h"
//===============================================
void GUart_Init(uint baud) {
    uchar l_preload = (256 - ((OSC_FREQ) / (OSC_PER_INST * 32 * baud)));
    TMOD |= 0x20;
    TH1 = l_preload;
    SCON = 0x50;
    TR1 = 1;
}
//===============================================
void GUart_Write_Char(uchar d) {
    SBUF = d;
	while(TI == 0);
	TI = 0;	
}
//===============================================
uchar GUart_Read_Char() {
    uchar l_data;
    while(RI == 0);
    l_data = SBUF;
    RI = 0;
    return l_data;
}
//===============================================
void GUart_Update() {
    GUart_Write_Char('A');
}
//=============================================== 
