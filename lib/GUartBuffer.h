//===============================================
#ifndef _GUartBuffer_
#define _GUartBuffer_
//===============================================
#include "GTypeDef.h"
//===============================================
void GUart_Init(const uint baud);
void GUart_Char(const char d);
void GUart_Str(const char* d);
//===============================================
#endif
//===============================================
