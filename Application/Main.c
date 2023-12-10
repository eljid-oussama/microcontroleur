#include "stm32f10x.h"
#include "../Drivers/Include/USART.h"
#include "../Services/Include/MYPLATEAU.h"

int main(int args, char *argv[]) {
	
	// Starts up USART3 and inits the RX handler
	USART_Init_RX(USART3);
	USART_RX_IRQ_Init(USART3, 46);
	
	
	PLAT_Init();
	
	while(1){
		// Continually gets the sets the turn speed to the latest value
		PLAT_Turn(get_command());
	}
}

