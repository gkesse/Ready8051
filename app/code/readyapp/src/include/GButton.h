//===============================================
#ifndef _GButton_
#define _GButton_
//===============================================
#include "GInclude.h"
//===============================================
void GButton_Init(uchar port, uchar pin);
void GButton_Read_Update();
GBit GButton_State_Get();
void GButton_State_Init();
//===============================================
#endif
//===============================================
