//===============================================
#include "GUartBuffer.h"
#include "GPortDef.h"
#include <string.h>
//===============================================
#define BS (0x08) // Backspace
#define CR (0x0A) // Line Feed
#define CR (0x0D) // Carriage Return
//===============================================
#define XON (0x11) // Device Control 1
#define XOFF (0x13) // Device Control 3
//===============================================
#define WRITE_BUFFER_MAX (10)
#define READ_BUFFER_MAX (10)
//===============================================
static char gUart_Write_Buffer[WRITE_BUFFER_MAX];
static char gUart_Read_Buffer[READ_BUFFER_MAX];
//===============================================
static uchar gUart_Write_Index;
static uchar gUart_Read_Index;
//===============================================
static uchar gUart_Write_Wait;
static uchar gUart_Read_Wait;
//===============================================
static bit gUart_Write_Error;
static bit gUart_Read_Error;
//===============================================
void GUart_Write_Char_Buffer(const char d);
void GUart_Write_Str_Buffer(const char* d);
void GUart_Write_Char(const char d);
char GUart_Read_Char();
void GUart_Update();
//===============================================
void GUart_Init(const uint baud) {
    uint m_PRELOAD = (256 - (uchar)((((ulong)OSC_FREQ / 100) * 3125) / ((ulong)baud * OSC_PER_INST * 1000)));
    SCON = 0x50;          
    TMOD |= 0x20;                       
    TH1 = m_PRELOAD;          
    TH1 = m_PRELOAD;          
    TI = 1;  
    ES = 0;          
    TR1 = 1; 
    
    gUart_Write_Index = 0;
    gUart_Read_Index = 0;
    gUart_Write_Wait = 0;
    gUart_Read_Wait = 0;
    gUart_Write_Error = FALSE;
    gUart_Read_Error = FALSE;
}
//===============================================
void GUart_Write_Char_Buffer(const char d) {
    if(gUart_Write_Wait < WRITE_BUFFER_MAX) {
        gUart_Write_Buffer[gUart_Write_Wait] = d;
        gUart_Write_Wait++;
    }
    else {
        gUart_Write_Error = TRUE;
    }
}
//===============================================
void GUart_Write_Str_Buffer(const char* d) {
	uint i;
	uint m_length = strlen(d);
	
	for(i = 0; i < m_length; i++) {
        GUart_Write_Char_Buffer(d[i]);
	}
}
//===============================================
void GUart_Write_Char(const char d) {
    uchar m_data = d;
    
    if(RI == 1) {
        if(SBUF == XOFF) {
            do {
                RI = 0;
                while(RI == 0);
            }while(SBUF != XON)
        }
        RI = 0;
    }
    
    while (TI == 0);
	TI = 0;
	if(d == '\n') m_data = CR;
	SBUF = m_data;
}
//===============================================
char GUart_Read_Char() {
    char m_data;
    if(gUart_Read_Index < gUart_Read_Wait) {
        m_data = gUart_Read_Buffer[gUart_Read_Index];
        
        if(gUart_Read_Index < READ_BUFFER_MAX) {
            gUart_Read_Index++;
        }
    }
    return m_data;
}
//===============================================
void GUart_Update() {
    if(gUart_Write_Index < gUart_Write_Wait) {
        GUart_Write_Char(gUart_Write_Buffer[gUart_Write_Index]);
        gUart_Write_Index++;
    }
    else {
        gUart_Write_Index = 0;
        gUart_Write_Wait = 0;
    }
    
    if(RI == 1) {
        if(gUart_Read_Index == gUart_Read_Wait) {
            gUart_Read_Index = 0;
            gUart_Read_Wait = 0;
        }
        
        gUart_Read_Buffer[gUart_Read_Wait] = SBUF;
        
        if(gUart_Read_Wait < READ_BUFFER_MAX) {
            gUart_Read_Wait++;
        }
        
        RI = 0;
    }
}
//===============================================


