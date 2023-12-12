#include "stm32f10x.h"
#include "../Services/Include/MYPLATEAU.h"
#include "../Services/Include/girouette.h"
int main(int args, char *argv[]) {
	

	//PLAT_Init();
	gir_init();
	while(1){
		// Continually gets the sets the turn speed to the latest value
		//PLAT_Update();
		gir_srvomoteur();
	}
}

