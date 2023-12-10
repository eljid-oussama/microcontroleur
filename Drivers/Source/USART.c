#include "../Include/USART.h"
#include "../Include/MYGPIO.h"

volatile signed char command = 0;

void USART_Init(USART_TypeDef * Usart){
	// Inits the GPIOs used by USART 3
	MyGPIO_Init(GPIOB, 10, AltOut_Ppull); // TX
	MyGPIO_Init(GPIOB, 11, In_Floating); // RX
	
	// Turns on USART clock
	if (Usart == USART2) {
		RCC->APB1ENR |= (1 << 17);
	}
	// USART3
	else {
		RCC->APB1ENR |= (1 << 18);
	}
	
	Usart->CR1 |= (1 << 13); // Turns Usart enable (UE) on
	
	// Set the BRR value to 9600
	Usart->BRR |= (3750); // 36 MHz / 9600 = 3750
}

void USART_Init_RX(USART_TypeDef * Usart){
	USART_Init(Usart);
	Usart->CR1 |= (1 << 2); // Turns RE on
}

void USART_Init_TX(USART_TypeDef * Usart){
	USART_Init(Usart);
	Usart->CR1 |= (1 << 3); // Turns TE on
}

void USART_RX_IRQ_Init(USART_TypeDef * Usart, int priority){
	if (Usart == USART2){
		Usart->CR1 |= (1 << 5); // Enables RXNEIE
		NVIC->ISER[1] |= (0x1 << 6); // Enables NVIC
		NVIC->IP[38] |= (priority << 4); // Sets priority (Shift by 4 because STM version only considers 4 leftmost bits )
	}
	//Usart3
	else {
		Usart->CR1 |= (1 << 5); // Enables RXNEIE
		NVIC->ISER[1] |= (0x1 << 7); // Enables NVIC
		NVIC->IP[39] |= (priority << 4); // Sets priority (Shift by 4 because STM version only considers 4 leftmost bits )
	}
}
void USART2_IRQHandler(){
	command = (signed char) USART3->DR; // Resets the REXNE flag on read
}
void USART3_IRQHandler(){		
	command = (signed char) USART3->DR; // Resets the REXNE flag on read
}

signed char get_command(){
	return command;
}