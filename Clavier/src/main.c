//===============================================
#include "GSch.h"
#include "GKeypad.h"
#include "GKeypadUart.h"
#include "GUartBuffer.h"
//===============================================
void main() {
    GSch_Init();

    GUart_Init(9600);
    GKeypad_Init();
    GKeypadUart_Init();
    
    GSch_Add_Task(GUart_Update, 1, 10);
    GSch_Add_Task(GKeypad_Scan, 3, 10);
    GSch_Add_Task(GKeypadUart_Update, 5, 5000);
    
    GSch_Start();
    
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
//===============================================
