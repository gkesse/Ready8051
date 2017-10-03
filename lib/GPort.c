//===============================================
#include "GPort.h"
#include "GPortDef.h"
//===============================================
void GPort_Init() {
    INPUT = 0xFF;
    OUTPUT = 0x00;
}
//===============================================
void GPort_Bit_Init() {
    GPort_Bit_Write(0, 1);
    GPort_Bit_Write(1, 1);
    GPort_Bit_Write(6, 0);
    GPort_Bit_Write(6, 0);
}
//===============================================
void GPort_Write(const uchar d) {
    OUTPUT = d;
}
//===============================================
void GPort_Bit_Write(const uchar pin, const bit d) {
    uchar m_pin = 0x01;
    
    m_pin <<= pin;
    
    if(d == TRUE) {
        PORT |= m_pin;
        return;
    }
    
    m_pin = ~m_pin;
    PORT &= m_pin;
}
//===============================================
uchar GPort_Read() {
    INPUT = 0xFF;
    return INPUT;
}
//===============================================
bit GPort_Bit_Read(const uchar pin) {
    uchar m_pin = 0x01;
    
    m_pin <<= pin;
    GPort_Bit_Write(pin, 1);
    return (PORT & m_pin); 
}
//===============================================
