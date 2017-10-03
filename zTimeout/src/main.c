//===============================================
#include "GSeos.h"
#include "GLed.h"
#include "GButton.h"
//===============================================
void main() {
    GSeos_Init(10);
    GLed_Init();
	GButton_Init();
    GSeos_Start();
    
	while(1) {
		GSeos_Go_To_Sleep();
	}
}
//===============================================
