//===============================================
#ifndef _GUart_
#define _GUart_
//===============================================
#include "GTypeDef.h"
//===============================================
void GUart_Init(const uint baud);
void GUart_Char(const char d);
void GUart_Str(const char* d);
//===============================================
#endif
//===============================================
