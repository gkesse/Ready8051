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
    char m_CHAR = GUart_Read_Char_Buffer();
    if(m_CHAR != UART_NO_CHAR) GUart_Write_Char_Buffer(m_CHAR);

    if(gUart_Button_Message_Flag == TRUE) {;
        if(gButton_Left == BUTTON_ON) GUart_Write_Str_Buffer("LEFT BUTTON\n");
        else if(gButton_Right == BUTTON_ON) GUart_Write_Str_Buffer("RIGHT BUTTON\n");
        else if(gButton_Warning == BUTTON_ON) GUart_Write_Str_Buffer("WARNING BUTTON\n");
        else if(gButton_Stop == BUTTON_ON) GUart_Write_Str_Buffer("STOP BUTTON\n");
        gUart_Button_Message_Flag = FALSE;
    }
}
//===============================================
