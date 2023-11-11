#include "stm32f10x.h"
#include "MyTimer.h"
int main(void) {
    // Configuration du timer
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // Valeur du prescaler (PSC) pour diviser la fr�quence du compteur
    // La fr�quence de base du timer est g�n�ralement la fr�quence d'horloge du bus APB1.
    // Supposons que la fr�quence du bus APB1 est de 72 MHz.
    // Pour une p�riode de 500 ms, nous pouvons utiliser PSC = 71999.
    TIM2->PSC = 7199;
    
    // Valeur du compteur pour atteindre une p�riode de 500 ms
    // La fr�quence d'horloge du timer apr�s avoir �t� divis�e par le PSC est de 1 kHz (1 ms par tick).
    // Donc, pour 500 ms, nous avons besoin d'ARR = 500.
    
	TIM2->ARR = 4999;
	
	//lanecement du compteur CNT
  TIM2->CR1 = TIM2->CR1 | ( 1 << 0);
    

    while (1) {
        // Votre code ici
    }
    
    return 0;
}
