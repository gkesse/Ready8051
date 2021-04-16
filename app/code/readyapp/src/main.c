//=============================================== 
#include "GSch.h"
#include "GProcess.h"
//=============================================== 
void main() {
    GSch_Init();
    GProcess_Init(Led_Flash);
    GSch_Start();
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//=============================================== 
