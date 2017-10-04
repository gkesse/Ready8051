//===============================================
#include "GUartBuffer.h"
#include "GUart.h"
//===============================================
extern bit gButton_Left;
extern bit gButton_Right;
extern bit gButton_Warning;
extern bit gButton_Stop;
//===============================================
bit gUart_Button_Message_Flag;
//===============================================
void GUart_Button_Init() {
    gUart_Button_Message_Flag = FALSE;
}
//===============================================
void GUart_Button_Message() {
    if(gUart_Button_Message_Flag == FALSE) return;

    if(gButton_Left == BUTTON_ON) {
        gUart_Button_Message_Flag = FALSE;
        GUart_Write_Str_Buffer("LEFT BUTTON\n");
    }
    else if(gButton_Right == BUTTON_ON) {
        gUart_Button_Message_Flag = FALSE;
        GUart_Write_Str_Buffer("RIGHT BUTTON\n");
    }
    else if(gButton_Warning == BUTTON_ON) {
        gUart_Button_Message_Flag = FALSE;
        GUart_Write_Str_Buffer("WARNING BUTTON\n");
    }
    else if(gButton_Stop == BUTTON_ON) {
        gUart_Button_Message_Flag = FALSE;
        GUart_Write_Str_Buffer("STOP BUTTON\n");
    }
}
//===============================================
