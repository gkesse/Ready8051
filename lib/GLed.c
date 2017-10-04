//===============================================
#include "GLed.h"
#include "GDelay.h"
#include "GPortDef.h"
//===============================================
extern bit gButton_Left;
extern bit gButton_Right;
extern bit gButton_Warning;
extern bit gButton_Stop;
//===============================================
static bit gLed_Flash;
static bit gLed_Flash_Short;
static bit gLed_Lock;
//===============================================
static bit gLed_Left;
static bit gLed_Right;
static bit gLed_Warning;
//===============================================
static uchar gLed_Left_Right_Time;
//===============================================
void GLed_Init() {
    gLed_Flash = LED_OFF;
    gLed_Flash_Short = LED_OFF;
    gLed_Lock = UNLOCKED;
    
    gLed_Left = LED_OFF;
    gLed_Right = LED_OFF;
    gLed_Warning = LED_OFF;
    
    gLed_Left_Right_Time = 0;
}
//===============================================
void GLed_Flash() {
    if(gLed_Flash == LED_OFF) {
        gLed_Flash = LED_ON;
        LED0 = LED_ON;
    }
    else if(gLed_Flash == LED_ON) {
        gLed_Flash = LED_OFF;
        LED0 = LED_OFF;
    }
}
//===============================================
void GLed_Flash_Short() {
    if(gLed_Lock == LOCKED) return;
    gLed_Lock = LOCKED;

    HYBRID1 = LED_OFF;

    if(gLed_Flash_Short == LED_OFF) {
        gLed_Flash_Short = LED_ON;
        HYBRID0 = LED_ON;
    }
    else if(gLed_Flash_Short == LED_ON) {
        gLed_Flash_Short = LED_OFF;
        HYBRID0 = LED_OFF;
    }
    
    gLed_Lock = UNLOCKED;
}
//===============================================
void GLed_Flash_Long() {
    uchar i;
    
    if(gLed_Lock == LOCKED) return;
    gLed_Lock = LOCKED;

    HYBRID0 = LED_OFF;

    for(i = 0; i < 4; i++) {
        HYBRID1 = LED_ON;
        GDelay_ms(200);
        HYBRID1 = LED_OFF;
        GDelay_ms(200);
    }
    
    gLed_Lock = UNLOCKED;
}
//===============================================
void GLed_Left_Right() {
    if(++gLed_Left_Right_Time != 30) return;
    gLed_Left_Right_Time = 0;
    
    if(gButton_Left == BUTTON_ON) {
        if(gLed_Left == LED_OFF) {
            gLed_Left = LED_ON;
            LED6 = LED_ON; 
            LED7 = LED_OFF; 
            gButton_Right = BUTTON_OFF; 
            gButton_Warning = BUTTON_OFF; 
        }
        else {gLed_Left = LED_OFF; LED6 = LED_OFF;}
    }
    
    if(gButton_Right == BUTTON_ON) {
        if(gLed_Right == LED_OFF) {
            gLed_Right = LED_ON; 
            LED6 = LED_OFF; 
            LED7 = LED_ON;
            gButton_Left = BUTTON_OFF; 
            gButton_Warning = BUTTON_OFF; 
        }
        else {gLed_Right = LED_OFF; LED7 = LED_OFF;}
    }

    if(gButton_Warning == BUTTON_ON) {
        if(gLed_Warning == LED_OFF) {
            gLed_Warning = LED_ON; 
            LED6 = LED_ON; 
            LED7 = LED_ON; 
            gButton_Left = BUTTON_OFF;
            gButton_Right = BUTTON_OFF;
        }
        else {gLed_Warning = LED_OFF; LED6 = LED_OFF; LED7 = LED_OFF;}
    }
    
    if(gButton_Stop == BUTTON_ON) {
        LED6 = LED_OFF; 
        LED7 = LED_OFF; 
        gLed_Left = LED_OFF;
        gLed_Right = LED_OFF;
        gLed_Warning = LED_OFF;
    }
}
//===============================================
void GLed_Left_Right_M2() {
    if(gButton_Left == BUTTON_ON) {
        if(gLed_Left == LED_OFF) {
            gLed_Left = LED_ON;
            LED6 = LED_ON; 
            LED7 = LED_OFF; 
            gButton_Right = BUTTON_OFF; 
            gButton_Warning = BUTTON_OFF; 
        }
        else {gLed_Left = LED_OFF; LED6 = LED_OFF;}
    }
    
    if(gButton_Right == BUTTON_ON) {
        if(gLed_Right == LED_OFF) {
            gLed_Right = LED_ON; 
            LED6 = LED_OFF; 
            LED7 = LED_ON;
            gButton_Left = BUTTON_OFF; 
            gButton_Warning = BUTTON_OFF; 
        }
        else {gLed_Right = LED_OFF; LED7 = LED_OFF;}
    }

    if(gButton_Warning == BUTTON_ON) {
        if(gLed_Warning == LED_OFF) {
            gLed_Warning = LED_ON; 
            LED6 = LED_ON; 
            LED7 = LED_ON; 
            gButton_Left = BUTTON_OFF;
            gButton_Right = BUTTON_OFF;
        }
        else {gLed_Warning = LED_OFF; LED6 = LED_OFF; LED7 = LED_OFF;}
    }
    
    if(gButton_Stop == BUTTON_ON) {
        LED6 = LED_OFF; 
        LED7 = LED_OFF; 
        gLed_Left = LED_OFF;
        gLed_Right = LED_OFF;
        gLed_Warning = LED_OFF;
    }
}
//===============================================
