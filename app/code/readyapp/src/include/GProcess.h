//===============================================
#ifndef _GProcess_
#define _GProcess_
//===============================================
#include "GInclude.h"
//===============================================
typedef enum _eGProcess eGProcess;
//===============================================
void GProcess_Init(eGProcess key);
//===============================================
enum _eGProcess {
    Led_Blink,
    Button,
    Bip,
    Last
};
//===============================================
#endif
//=============================================== 
