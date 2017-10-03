//===============================================
#include "GLed.h"
#include "GButton.h"
#include "GDelay.h"
//===============================================
void main() {
    GLed_Init();
	GButton_Init();

	while(1) {
		GButton_Scan();
		GButton_Update();
		GLed_Left_Right();
		GDelay_ms(10);
	}
}
//===============================================
