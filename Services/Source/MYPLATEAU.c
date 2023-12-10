#include "../Include/MYPLATEAU.h"
#include "../../Drivers/Include/MYGPIO.h"
#include "../../Drivers/Include/MYTimer.h"
#include <stdlib.h>


// Initializes the GPIOA(Pin 0), Timer2 and PWM with frequence 20 KHz.
void PLAT_Init(){
	MyTimer_Struct_TypeDef T2 = { TIM2, 1800, 1}; // Def of T2
	MyGPIO_Init( GPIOA, 0, Out_Ppull);
	
	MyGPIO_Init(GPIOA, 1, AltOut_Ppull);
	MyTimer_Base_Init(&T2);
	MyTimer_PWM_Init(TIM2, 2);
}

void PLAT_Turn(int power){
	if (power < 0) {
		MyGPIO_Reset(GPIOA, 1); // Sets Direction to 0 (Turn left)
	}
	else {
		MyGPIO_Set ( GPIOA, 0); // Sets Direction to 1 (Turn right)
	}
	MyTimer_PWM_DutyCycle (TIM2, 2, abs(power));
}