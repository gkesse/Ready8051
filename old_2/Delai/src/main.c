//===============================================
#include "GLed.h"
#include "GDelay.h"
//===============================================
void main() {
    GLed_Init();

	while(1) {
		GLed_Flash();
		GDelay_ms(1000);
	}
}
//===============================================