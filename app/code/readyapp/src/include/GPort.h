//===============================================
#ifndef _GPort_
#define _GPort_
//===============================================
#include "GInclude.h"
//===============================================
void GPort_Data_Write(uchar port, uchar d);
void GPort_Data_Shift(uchar port, uchar d, char offset);
uchar GPort_Data_Read(uchar port);
void GPort_Bit_Write(uchar port, uchar pin, GBit d);
GBit GPort_Bit_Read(uchar port, uchar pin);
//===============================================
#endif
//===============================================
