//===============================================
#ifndef _GPort_
#define _GPort_
//===============================================
#include "GTypeDef.h"
//===============================================
void GPort_Bit_Init();
void GPort_Init();
void GPort_Write(const uchar d);
void GPort_Bit_Write(const uchar pin, const bit d);
uchar GPort_Read();
bit GPort_Bit_Read(const uchar pin);
//===============================================
#endif
//===============================================
