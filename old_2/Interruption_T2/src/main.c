//===============================================
#include "GInterrupt.h"
#include "GButton.h"
//===============================================
void main() {
    GTimer_T2_Init();
    GButton_Init();
    
	GInterrupt_Start();

	while(1);
}
//===============================================
