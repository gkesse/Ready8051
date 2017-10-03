//===============================================
#include "GSchHybrid.h"
#include "GLed.h"
//===============================================
void main() {
    GSch_Init();

    GLed_Init();
    
    GSch_Add_Task(GLed_Flash_Short, 0, 200, COOP);
    GSch_Add_Task(GLed_Flash_Long, 1600, 1600, PREEMP);
    
    GSch_Start();
    
    while(1) {
        GSch_Dispatch_Tasks();
    }			 
}
//===============================================
