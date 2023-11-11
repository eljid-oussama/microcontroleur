#include "stm32f10x.h"
#include "MyTimer.h"
int main(void) {
    // Configuration du timer
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // Valeur du prescaler (PSC) pour diviser la fréquence du compteur
    // La fréquence de base du timer est généralement la fréquence d'horloge du bus APB1.
    // Supposons que la fréquence du bus APB1 est de 72 MHz.
    // Pour une période de 500 ms, nous pouvons utiliser PSC = 71999.
    TIM2->PSC = 7199;
    
    // Valeur du compteur pour atteindre une période de 500 ms
    // La fréquence d'horloge du timer après avoir été divisée par le PSC est de 1 kHz (1 ms par tick).
    // Donc, pour 500 ms, nous avons besoin d'ARR = 500.
    
	TIM2->ARR = 4999;
	
	//lanecement du compteur CNT
  TIM2->CR1 = TIM2->CR1 | ( 1 << 0);
    

    while (1) {
        // Votre code ici
    }
    
    return 0;
}
