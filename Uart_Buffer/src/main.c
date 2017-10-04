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
    
    GSch_Add_Task(GButton_Scan, 0, 10);
    GSch_Add_Task(GButton_Update, 1, 5);
    GSch_Add_Task(GUart_Update, 5, 10);
    GSch_Add_Task(GLed_Left_Right, 7, 250);
    GSch_Add_Task(GUart_Button_Message, 11, 250);
    
    GSch_Start();
    
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//===============================================
