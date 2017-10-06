//===============================================
#include "GKeypadUart.h"
#include "GUartBuffer.h"
//===============================================
static bit gKeypadUart_Write_Flag;
static uchar gKeypadUart_Update_State;
static uchar gKeypadUart_Read_Count;
//===============================================
void GKeypadUart_Write_Message();
void GKeypadUart_Read_Message();
void GKeypadUart_Delete_Message();
//===============================================
void GKeypadUart_Init() {
    gKeypadUart_Write_Flag = TRUE;
    gKeypadUart_Update_State = 1;
    gKeypadUart_Read_Count = 0;
}
//===============================================
void GKeypadUart_Write_Message() {
    if(gKeypadUart_Write_Flag == TRUE) {
        switch(gKeypadUart_Update_State) {
            case 1: {
                GUart_Write_Str_Buffer("FIRST NAME : ");
                gKeypadUart_Update_State++;
                break;
            }
            case 2: {
                GUart_Write_Str_Buffer("LAST NAME : ");
                gKeypadUart_Update_State++;
                break;
            }
            case 3: {
                GUart_Write_Str_Buffer("EMAIL : ");
                gKeypadUart_Update_State++;
                break;
            }
        }
        gKeypadUart_Write_Flag = FALSE;
    }
}
//===============================================
void GKeypadUart_Read_Message() {
    char m_CHAR = GUart_Read_Char_Buffer();
    if(m_CHAR != UART_NO_CHAR) {
        if(m_CHAR == CR) {
            gKeypadUart_Write_Flag = TRUE;
            GUart_Write_Char_Buffer(m_CHAR);
            gKeypadUart_Read_Count = 0;
        }
        else if(m_CHAR == BS) {
            GKeypadUart_Delete_Message();
        }
        else {
            GUart_Write_Char_Buffer(m_CHAR);
            gKeypadUart_Read_Count++;
        }
    }
}
//===============================================
void GKeypadUart_Delete_Message() {
    if(gKeypadUart_Read_Count > 0) {
        GUart_Write_Char_Buffer(BS);
        gKeypadUart_Read_Count--;
    }
}
//===============================================
void GKeypadUart_Update() {
    GKeypadUart_Write_Message();
    GKeypadUart_Read_Message();
}
//===============================================
