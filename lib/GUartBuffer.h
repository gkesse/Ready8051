//===============================================
#ifndef _GUartBuffer_
#define _GUartBuffer_
//===============================================
#include "GTypeDef.h"
//===============================================
void GUart_Init(const uint baud);
void GUart_Write_Char_Buffer(const char d);
void GUart_Write_Str_Buffer(const char* d);
char GUart_Read_Char_Buffer();
void GUart_Update();
//===============================================
#endif
//===============================================
