//===============================================
#include "GManager.h"
//===============================================
void GManager_Uchar_Bit_Write(uchar* uchar_d, uchar pos, GBit d) {
    uchar l_mask = 0x01;
    l_mask <<= pos;
    (*uchar_d) = (d == 0) ? ((*uchar_d) & (~l_mask)) : ((*uchar_d) | l_mask);
}
//=============================================== 
GBit GManager_Uchar_Bit_Read(uchar uchar_d, uchar pos) {
    uchar l_mask = 0x01;
    GBit l_data;
    l_mask <<= pos;
    l_data = ((uchar_d & l_mask) == 0) ? 0 : 1;
    return l_data;
}
//=============================================== 
