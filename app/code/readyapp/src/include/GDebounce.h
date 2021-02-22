//===============================================
#ifndef _GDebounce_
#define _GDebounce_
//===============================================
#include "GInclude.h"
//===============================================
void GDebounce_Init(uchar port, uchar pin);
void GDebounce_Update();
GBit GDebounce_Get_State();
//===============================================
#endif
//===============================================
