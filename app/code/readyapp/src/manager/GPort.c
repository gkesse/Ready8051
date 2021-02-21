//===============================================
#include "GPort.h"
//===============================================
#define PORT_0 P0
#define PORT_1 P1
#define PORT_2 P2
#define PORT_3 P3
//===============================================
void GPort_Data_Write(uchar port, uchar d) {
    if(port == 0) {PORT_0 = d;}
    else if(port == 1) {PORT_1 = d;}
    else if(port == 2) {PORT_2 = d;}
    else if(port == 3) {PORT_3 = d;}
}
//=============================================== 
void GPort_Bit_Write(uchar port, uchar pin, GBit d) {
    uchar lData = 0x01;
    lData <<= pin;
    if(port == 0) {PORT_0 = (d == 0) ? (PORT_0 & ~lData) : (PORT_0 | lData);}
    else if(port == 1) {PORT_1 = (d == 0) ? (PORT_1 & ~lData) : (PORT_1 | lData);}
    else if(port == 2) {PORT_2 = (d == 0) ? (PORT_2 & ~lData) : (PORT_2 | lData);}
    else if(port == 3) {PORT_3 = (d == 0) ? (PORT_3 & ~lData) : (PORT_3 | lData);}
}
//=============================================== 
