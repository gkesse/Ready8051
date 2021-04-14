//===============================================
#ifndef _GUart_
#define _GUart_
//===============================================
#include "GInclude.h"
//===============================================
void GUart_Init(uint baud);
void GUart_Write_Char(uchar d);
uchar GUart_Read_Char();
void GUart_Update();
//===============================================
#endif
//===============================================
