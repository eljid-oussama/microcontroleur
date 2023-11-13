#include "stm32f10x.h" 

void MyTimer_Base_Init(TIM_TypeDef * Timer , uint16_t arr , uint16_t psc){
	
	if(Timer == TIM1){
		RCC->APB1ENR |= RCC_APB1ENR_TIM1EN;
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
	
	Timer->CR1 = Timer->CR1 | ( 1 << 0);
}