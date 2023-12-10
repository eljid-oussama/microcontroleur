#include "stm32f10x.h"
#include "../Services/Include/MYPLATEAU.h"

int main(int args, char *argv[]) {
	

	PLAT_Init();
	
	while(1){
		// Continually gets the sets the turn speed to the latest value
		PLAT_Update();
	}
}

