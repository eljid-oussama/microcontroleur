#include "../Include/MYPLATEAU.h"
#include "../../Drivers/Include/MYGPIO.h"
#include "../../Drivers/Include/MYTimer.h"
#include "../../Drivers/Include/USART.h"
#include <stdlib.h>
int8_t test;
// Initializes the GPIOA(Pin 0), Timer2 and PWM with frequence 20 KHz.
void PLAT_Init(){
	MyTimer_Struct_TypeDef T2 = { TIM2, 1800, 1}; // Def of T2
	
	// Starts up USART3 and inits the RX handler
	USART_Init_RX(USART3);
	USART_RX_IRQ_Init(USART3, 46);
	
	// Initializes GPIOs and timer
	MyGPIO_Init( GPIOA, 0, Out_Ppull);
	MyGPIO_Init(GPIOA, 1, AltOut_Ppull); // Pin A1 corresponds to channel 2 on TIM2
	MyTimer_Base_Init(&T2);
	MyTimer_PWM_Init(TIM2, 2);
}

void PLAT_Turn(int8_t power){
	
	if (power < 0) {
		MyGPIO_Reset(GPIOA, 0); // Sets Direction to 0 (Turn left)
	}
	else {
		MyGPIO_Set ( GPIOA, 0); // Sets Direction to 1 (Turn right)
	}
	MyTimer_PWM_DutyCycle (TIM2, 2, abs(power));
	
}

void PLAT_Update(){
	test = get_command();
	PLAT_Turn(test);
}