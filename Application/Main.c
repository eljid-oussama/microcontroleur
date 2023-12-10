#include "stm32f10x.h"
#include "../Drivers/Include/USART.h"
#include "../Services/Include/MYPLATEAU.h"

int main(int args, char *argv[]) {
	
	USART_Init_RX(USART3);
	USART_RX_IRQ_Init(USART3, 46);
	
	// Put message in Data Register
	//USART3->DR = 0x41;
	
	PLAT_Init();
	//PLAT_Turn(get_command());
	
	
	//TXE / TEXEIE interrupt indicates we can write new mesg to DR
	
	while(1){
		PLAT_Turn(get_command());
	}
}

