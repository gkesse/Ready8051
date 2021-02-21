//===============================================
#include "GLedCoop.h"
#include "GPortDef.h"
//===============================================
extern bit gButton_Left;
extern bit gButton_Right;
extern bit gButton_Warning;
extern bit gButton_Stop;
//===============================================
static bit gLed_Left;
static bit gLed_Right;
static bit gLed_Warning;
//===============================================
void GLed_Init() {
    gLed_Left = LED_OFF;
    gLed_Right = LED_OFF;
    gLed_Warning = LED_OFF;
}
//===============================================
void GLed_Left_Right() {
    if(gButton_Left == BUTTON_ON) {
        if(gLed_Left == LED_OFF) {
            gLed_Left = LED_ON;
            LED6 = LED_ON; 
            LED7 = LED_OFF; 
        }
        else {gLed_Left = LED_OFF; LED6 = LED_OFF;}
    }
    
    if(gButton_Right == BUTTON_ON) {
        if(gLed_Right == LED_OFF) {
            gLed_Right = LED_ON; 
            LED6 = LED_OFF; 
            LED7 = LED_ON;
        }
        else {gLed_Right = LED_OFF; LED7 = LED_OFF;}
    }

    if(gButton_Warning == BUTTON_ON) {
        if(gLed_Warning == LED_OFF) {
            gLed_Warning = LED_ON; 
            LED6 = LED_ON; 
            LED7 = LED_ON; 
        }
        else {gLed_Warning = LED_OFF; LED6 = LED_OFF; LED7 = LED_OFF;}
    }
    
    if(gButton_Stop == BUTTON_ON) {
        LED6 = LED_OFF; 
        LED7 = LED_OFF; 
    }
}
//===============================================
