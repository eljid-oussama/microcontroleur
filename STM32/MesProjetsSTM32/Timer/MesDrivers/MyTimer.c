#include "MyTimer.h"
#include "stm32f10x.h"

void (*TIM1_ptr) (void) ;
void (*TIM2_ptr) (void) ;
void (*TIM3_ptr) (void) ;
void (*TIM4_ptr) (void) ;


void MyTimer_Base_Init(TIM_TypeDef*Timer , uint16_t arr , uint16_t psc){
	
	if(Timer == TIM1){
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(Timer == TIM2){
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(Timer == TIM3){
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(Timer == TIM4){
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	
	
	Timer->PSC = psc ;
	Timer->ARR = arr ;
	
	Timer_Start(Timer);
	
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer , char Prio , void (*IT_function ) (void ) ){
		//activation d'interruption
	Timer->DIER =  Timer->DIER | (1<<0) ;
	
	//configuration des interruptions pr chaque Timer
	if(Timer == TIM1){
		NVIC->ISER[0] = NVIC->ISER[0] | (1 << 25);
		NVIC->IP[25] = (Prio << 4);
		TIM1_ptr = IT_function ;
	}
	if(Timer == TIM2){
		NVIC->ISER[0] = NVIC->ISER[0] | (1 << 28);
		NVIC->IP[28] = (Prio << 4);
		TIM2_ptr = IT_function ;
	}
	if(Timer == TIM3){
		NVIC->ISER[0] = NVIC->ISER[0] | (1 << 29);
		NVIC->IP[29] = (Prio << 4);
		TIM3_ptr = IT_function ;
	}
	if(Timer == TIM4){
		NVIC->ISER[0] = NVIC->ISER[0] | (1 << 30);
		NVIC->IP[30] = (Prio << 4);
		TIM4_ptr = IT_function ;
	}
	
}

//Configuration des handlers des timers

void TIM1_UP_IRQHandler(void) { 
	TIM1->SR = TIM1->SR & ~TIM_SR_UIF; //metre le flag d'interru a 0 
	(*TIM1_ptr)();
	
	
}

void TIM2_IRQHandler(void) {
  TIM2->SR = TIM2->SR & ~TIM_SR_UIF;	
	(*TIM2_ptr)();
	
}

void TIM3_IRQHandler(void) { 
	TIM3->SR = TIM3->SR & ~TIM_SR_UIF;
	(*TIM3_ptr)();
	
}

void TIM4_IRQHandler(void) { 
	TIM4->SR = TIM4->SR & ~TIM_SR_UIF;
	(*TIM4_ptr)();
	
	
}

void MyTimer_PWM(TIM_TypeDef * Timer , int Channel , int duree){
	if(Timer == TIM1) {
		Timer->BDTR = Timer->BDTR | (1 << 15);
	}
	if(Channel == 1 ){
	Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
	Timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
	
	Timer->CCER |= TIM_CCER_CC1E; 
	Timer->CCR1 = duree ;
	}
	if(Channel == 2 ){
	Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
	Timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
	
	Timer->CCER |= TIM_CCER_CC2E; 
	Timer->CCR2 = duree ;
	}
	if(Channel == 3 ){
	Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
	Timer->CCMR2 |= TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;
	
	Timer->CCER |= TIM_CCER_CC3E; 
	Timer->CCR3 = duree ;
	}
	if(Channel == 4 ){
	Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
	Timer->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;
	
	Timer->CCER |= TIM_CCER_CC4E; 
	Timer->CCR4 = duree ;
	}
	
}
	
	
	


