//===============================================
#ifndef _GUart_
#define _GUart_
//===============================================
#include "GInclude.h"
//===============================================
void GUart_Init(uint baud);
void GUart_Write_Char(char d);
void GUart_Write_String(char* d);
char GUart_Read_Char();
void GUart_Update_Read();
void GUart_Update_Write();
void GUart_Update_3();
//===============================================
#endif
//===============================================
