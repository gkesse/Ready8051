//===============================================
#ifndef _GButton_
#define _GButton_
//===============================================
#include "GInclude.h"
//===============================================
void GButton_Init(uchar port, uchar pin);
void GButton_Update();
GBit GButton_Get_State();
void GButton_Init_State();
//===============================================
#endif
//===============================================
