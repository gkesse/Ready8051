//===============================================
#include "GButton.h"
#include "GPortDef.h"
//===============================================
extern bit gUart_Button_Message_Flag;
//===============================================
bit gButton_Left;
bit gButton_Right;
bit gButton_Warning;
bit gButton_Stop;
//===============================================
static bit gButton_Left_Flag;
static bit gButton_Right_Flag;
static bit gButton_Warning_Flag;
static bit gButton_Stop_Flag;
//===============================================
static uchar gButton_Update_Time;
//===============================================
void GButton_Read_Config();
void GButton_Update();
//===============================================
void GButton_Read_Config() {
    if(gButton_Left_Flag == TRUE) BUTTON0 = 1;
    if(gButton_Right_Flag == TRUE) BUTTON1 = 1;
    if(gButton_Warning_Flag == TRUE) BUTTON2 = 1;
    if(gButton_Stop_Flag == TRUE) BUTTON3 = 1;
}
//===============================================
void GButton_Update() {    
    if(++gButton_Update_Time != 250) return;
    gButton_Update_Time = 0;
    
    gButton_Left_Flag = TRUE;
    gButton_Right_Flag = TRUE;
    gButton_Warning_Flag = TRUE;
    gButton_Stop_Flag = TRUE;
}
//===============================================
void GButton_Init() {
    gButton_Left = BUTTON_OFF;
    gButton_Right = BUTTON_OFF;
    gButton_Warning = BUTTON_OFF;
    gButton_Stop = BUTTON_OFF;
    
    gButton_Left_Flag = TRUE;
    gButton_Right_Flag = TRUE;
    gButton_Warning_Flag = TRUE;
    gButton_Stop_Flag = TRUE;
    
    gButton_Update_Time = 0;
}
//===============================================
void GButton_Scan() {    
    GButton_Read_Config();
    
    if(BUTTON0 == BUTTON_ON && gButton_Left_Flag == TRUE) {
        gButton_Update_Time = 0;
        gButton_Left = BUTTON_ON;
        gButton_Right = BUTTON_OFF;
        gButton_Warning = BUTTON_OFF;
        gButton_Stop = BUTTON_OFF;
		gUart_Button_Message_Flag = TRUE;
        gButton_Left_Flag = FALSE;
    }
    
    if(BUTTON1 == BUTTON_ON && gButton_Right_Flag == TRUE) {
        gButton_Update_Time = 0;
        gButton_Left = BUTTON_OFF;
        gButton_Right = BUTTON_ON;
        gButton_Warning = BUTTON_OFF;
        gButton_Stop = BUTTON_OFF;
		gUart_Button_Message_Flag = TRUE;
        gButton_Right_Flag = FALSE;
    }

    if(BUTTON2 == BUTTON_ON && gButton_Warning_Flag == TRUE) {
        gButton_Update_Time = 0;
        gButton_Left = BUTTON_OFF;
        gButton_Right = BUTTON_OFF;
        gButton_Warning = BUTTON_ON;
        gButton_Stop = BUTTON_OFF;
		gUart_Button_Message_Flag = TRUE;
        gButton_Warning_Flag = FALSE;
    }
    
    if(BUTTON3 == BUTTON_ON && gButton_Stop_Flag == TRUE) {
        gButton_Update_Time = 0;
        gButton_Left = BUTTON_OFF;
        gButton_Right = BUTTON_OFF;
        gButton_Warning = BUTTON_OFF;
        gButton_Stop = BUTTON_ON;
		gUart_Button_Message_Flag = TRUE;
        gButton_Stop_Flag = FALSE;
    }

	GButton_Update();
}
//===============================================
