//===============================================
#include "GInterrupt.h"
#include "GButton.h"
//===============================================
void main() {
    GTimer_T1_Init();
    GButton_Init();
    
	GInterrupt_Start();

	while(1);
}
//===============================================
