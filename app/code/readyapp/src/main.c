//=============================================== 
#include "GSch.h"
#include "GProcess.h"
//=============================================== 
void main() {
    GSch_Init();
    GProcess_Init(Button_Bip);
    GSch_Start();
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//=============================================== 
