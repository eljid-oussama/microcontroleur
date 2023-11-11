#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"


void New_func (void){
			MyGPIO_Toggle(GPIOA , 8);
}
void New_func2 (void){
			MyGPIO_Toggle(GPIOB , 8);
}
void New_func3 (void){
			MyGPIO_Toggle(GPIOC , 8);
}
void New_func4 (void){
	    
			MyGPIO_Toggle(GPIOA , 6);
}


int main(void) {
    // Configuration du timer
    //RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // Valeur du prescaler (PSC) pour diviser la fréquence du compteur
    // La fréquence de base du timer est généralement la fréquence d'horloge du bus APB1.
    // Supposons que la fréquence du bus APB1 est de 72 MHz.
    // Pour une période de 500 ms, nous pouvons utiliser PSC = 71999.
    //TIM2->PSC = 7199;
    
    // Valeur du compteur pour atteindre une période de 500 ms
    // La fréquence d'horloge du timer après avoir été divisée par le PSC est de 1 kHz (1 ms par tick).
    // Donc, pour 500 ms, nous avons besoin d'ARR = 500.
    
	//TIM2->ARR = 4999;
	
	//lanecement du compteur CNT
  //TIM2->CR1 = TIM2->CR1 | ( 1 << 0);
	//demander au prof : la périodicité d’appel au handler du Timer en mettant un point d’arrêt au début de ce handle?? 
  
	 /* 
		MyGPIO_Init(GPIOA, 6, Out_Ppull );
    MyTimer_Base_Init(TIM1 , 4999 , 7199);
	  MyTimer_ActiveIT (TIM1 , 5 ,  New_func );
	
	  MyTimer_Base_Init(TIM2 , 10000 , 60000);
	  MyTimer_ActiveIT (TIM2 , 6 ,  New_func2 );
		
		MyTimer_Base_Init(TIM3		, 4999 , 7199);
	  MyTimer_ActiveIT (TIM3 , 7  ,  New_func3);
		
		
		MyTimer_Base_Init(TIM4 , 4999 , 7199);
	  MyTimer_ActiveIT (TIM4 , 4 ,  New_func4 );
*/

		MyTimer_PWM(TIM1 , 2 , 719);	
		MyGPIO_Init(GPIOA, 9, AltOut_Ppull );
    MyTimer_Base_Init(TIM1 , 4999 , 7199);
	  MyTimer_ActiveIT (TIM1 , 5 ,  New_func );
	
		MyTimer_PWM(TIM2 , 2 , 719);	
		MyGPIO_Init(GPIOA, 1, AltOut_Ppull );
    MyTimer_Base_Init(TIM2 , 4999 , 7199);
	  MyTimer_ActiveIT (TIM2 , 5 ,  New_func );
		/*
			
		MyTimer_PWM(TIM3 , 3 , 100);	
		MyGPIO_Init(GPIOC, 6, Out_Ppull );
    MyTimer_Base_Init(TIM3 , 4999 , 7199);
	  MyTimer_ActiveIT (TIM3 , 5 ,  New_func );
		
		MyTimer_PWM(TIM4 , 3 , 719);	
		MyGPIO_Init(GPIOA, 7, Out_Ppull );
    MyTimer_Base_Init(TIM4 , 4999 , 7199);
	  MyTimer_ActiveIT (TIM4 , 5 ,  New_func );
		*/
    while (1) {
        // Votre code ici
    }
    
    return 0;
}
