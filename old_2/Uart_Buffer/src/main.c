//===============================================
#include "GSch.h"
#include "GLedCoop.h"
#include "GButton.h"
#include "GUartBuffer.h"
#include "GUartButtonBuffer.h"
#include "GButton.h"
//===============================================
void main() {
    GSch_Init();

    GLed_Init();
    GButton_Init();
	GUart_Init(9600);
	GUart_Button_Init();
    
    GSch_Add_Task(GButton_Scan, 0, 50);
    GSch_Add_Task(GUart_Update, 1, 10);
    GSch_Add_Task(GLed_Left_Right, 3, 250);
    GSch_Add_Task(GUart_Button_Message, 5, 10);
    
    GSch_Start();
    
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//===============================================
