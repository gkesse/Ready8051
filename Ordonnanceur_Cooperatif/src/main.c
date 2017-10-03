//===============================================
#include "GSch.h"
#include "GLed.h"
#include "GButton.h"
//===============================================
void main() {
    GSch_Init();

    GLed_Init();
    GButton_Init();
    
    GSch_Add_Task(GButton_Scan, 0, 10);
    GSch_Add_Task(GButton_Update, 1, 10);
    GSch_Add_Task(GLed_Left_Right_M2, 3, 250);
    
    GSch_Start();
    
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//===============================================
