//=============================================== 
#include "GSch.h"
#include "GProcess.h"
//=============================================== 
void main() {
    GSch_Init();
    GProcess_Init(Button_Switch);
    GSch_Start();
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//=============================================== 
