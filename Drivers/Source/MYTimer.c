#include "../Include/MYTimer.h"
#include <stdio.h>
void (* TIM1_pnt_fun) (void);
void (* TIM2_pnt_fun) (void);
void (* TIM3_pnt_fun) (void);
void (* TIM4_pnt_fun) (void);

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer){
	if (Timer->timer == TIM1){
		RCC->APB2ENR |= (0x1 << 11);
	}
	else if (Timer->timer == TIM2){
		RCC->APB1ENR |= (0x1 << 0);
	}
	else if (Timer->timer == TIM3){
		RCC->APB1ENR |= (0x1 << 1);
	}
	// TIM4
	else {
		RCC->APB1ENR |= (0x1 << 2);
	}
	Timer->timer->ARR = Timer->ARR;
	Timer->timer->PSC = Timer->PSC;
	MyTimer_Base_Start(Timer->timer);
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*Pnt_fun) (void)){
	
	Timer->DIER |= 0x1; // Enables UIE
	if ( Timer == TIM1) {
		NVIC->ISER[0] |= (0x1 << 25); // Enables NVIC
		NVIC->IP[25] |= (Prio << 4); // Sets priority (Shitft by 4 because STM version only considers 4 leftmost bits )
		TIM1_pnt_fun = Pnt_fun; // Sets @ of the handler function
	}
	else if (Timer == TIM2) {
		NVIC->ISER[0] |= (0x1 << 28); // Enables NVIC
		NVIC->IP[28] |= (Prio << 4); // Sets priority (Shitft by 4 because STM version only considers 4 leftmost bits )
		TIM2_pnt_fun = Pnt_fun; // Sets @ of the handler function
	}
	else if (Timer == TIM3){
		NVIC->ISER[0] |= (0x1 << 29); // Enables NVIC
		NVIC->IP[29] |= (Prio << 4); // Sets priority (Shitft by 4 because STM version only considers 4 leftmost bits )
		TIM3_pnt_fun = Pnt_fun; // Sets @ of the handler function
	}
	
	//TIM4
	else {
		NVIC->ISER[0] |= (0x1 << 30); // Enables NVIC
		NVIC->IP[30] |= (Prio << 4); // Sets priority (Shitft by 4 because STM version only considers 4 leftmost bits )
		TIM4_pnt_fun = Pnt_fun; // Sets @ of the handler function
	}
}

void MyTimer_PWM_Init (TIM_TypeDef * Timer, char Channel){
	
	if ( Timer == TIM1) {
		TIM1->BDTR |= (0x1 << 15); // Sets the MOE to 1
	}
	
	switch (Channel){
		case 1:
					Timer->CCMR1 &= ~(7 << 4); // Delete current values of OC1M
					Timer->CCMR1 |= (6 << 4); // Sets OC1M to 110, PWM Mode 1
					Timer->CCER |= (0x1); // Sets CC1E to 1, On - OC1 signal is output on the corresponding output pin.
			break;
			
		case 2:
					Timer->CCMR1 &= ~(7 << 12); // Delete current values of OC2M
					Timer->CCMR1 |= (6 << 12); // Sets OC2M to 110, PWM Mode 1
					Timer->CCER |= (0x1 << 4); // Sets CC2E to 1, On - OC1 signal is output on the corresponding output pin.
			break;
		
		case 3:
				Timer->CCMR2 &= ~(7 << 4); // Delete current values of OC3M
				Timer->CCMR2 |= (6 << 4); // Sets OC3M to 110, PWM Mode 1
				Timer->CCER |= (0x1 << 8); // Sets CC3E to 1, On - OC1 signal is output on the corresponding output pin.
			break;
			
		default: // Case '4'				
				Timer->CCMR2 &= ~(7 << 12); // Delete current values of OC4M
				Timer->CCMR2 |= (6 << 12); // Sets OC4M to 110, PWM Mode 1
				Timer->CCER |= (0x1 << 12); // Sets CC4E to 1, On - OC1 signal is output on the corresponding output pin.
			break;
	}
}

void MyTimer_PWM_DutyCycle (TIM_TypeDef * Timer, char Channel, int percentARR){
	switch (Channel){
		case 1:
			Timer->CCR1 &= ~(0xFFFF);
			Timer->CCR1 |= (Timer->ARR) * percentARR/100;
			break;
			
		case 2:
			Timer->CCR2 &= ~(0xFFFF);
			Timer->CCR2 |= (Timer->ARR) * percentARR/100;
			break;
		
		case 3:
			Timer->CCR3 &= ~(0xFFFF);
			Timer->CCR3 |= (Timer->ARR) * percentARR/100; 
			break;
			
		default: // Case '4'
			Timer->CCR4 &= ~(0xFFFF);
			Timer->CCR4 |= (Timer->ARR) * percentARR/100;
			break;
			}
}

void TIM_encode(MyTimer_Struct_TypeDef * Timer){
	MyTimer_Base_Init(Timer);	
	 
	Timer->timer->CCMR1 |= (1 << 0); //CC1S
  Timer->timer->CCMR1 |= (1 << 8); //CC2S
	
	Timer->timer->SMCR = 3;// SMS encoder 3
	Timer->timer->CR1 |= (1 << 0);
	Timer->timer->CNT = 0;

  Timer->timer->CCER |= (1 << 0) ;
	Timer->timer->CCER |= (1 << 4) ;
	
	
} 


void TIM1_IRQHandler(void){
	(* TIM1_pnt_fun)();
	TIM1->SR &= ~(0x1 << 0); // Turns off UIF 
}

void TIM2_IRQHandler(void){
	(* TIM2_pnt_fun)();
	TIM2->SR &= ~(0x1 << 0); // Turns off UIF 
}

void TIM3_IRQHandler(void){
	(* TIM3_pnt_fun)();
	TIM3->SR &= ~(0x1 << 0); // Turns off UIF 
}

void TIM4_IRQHandler(void){
	(* TIM4_pnt_fun)();
	TIM4->SR &= ~(0x1 << 0); // Turns off UIF 
}
	
	