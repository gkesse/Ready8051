//===============================================
#include "GPort.h"
#include "GDelay.h"
//===============================================
void main() {
    GPort_Bit_Init();

	while(1) {
		GPort_Bit_Write(6, GPort_Bit_Read(0));
		GPort_Bit_Write(7, GPort_Bit_Read(1));
		GDelay_ms(200);
	}
}
//===============================================
