//===============================================
#ifndef _GProcess_
#define _GProcess_
//===============================================
#include "GInclude.h"
//===============================================
typedef enum {
    Led_Flash,
    Led_Count,
    Led_Direction,
    Button,
    Button_Bip,
    Button_Switch,
    G7seg,
    Uart,
    Last
} eGProcess;
//===============================================
void GProcess_Init(eGProcess key);
//===============================================
#endif
//=============================================== 
