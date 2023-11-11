#include "stm32f10x.h"
#include "MyGPIO.h"

void MyGPIO_Init(MyGPIO_Struct_TypeDef *gpio, uint8_t pin, uint8_t conf) {
    
    RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
    if (pin < 8) {
        // Mettre à 0 les 4 bits dans CRL
        gpio->CRL &= ~(0xF << (pin * 4));
        
        // Ecrire à la bonne position les 2 bits MODE
        gpio->CRL |= (conf & 0x03) << (pin * 4);
        
        // Ecrire à la bonne position les 2 bits CNF
        gpio->CRL |= (conf & 0x0C) << ((pin * 4) + 2);
    } else {
        // pin > 7 : même chose avec CRH
        pin -= 8; // Pour aligner les bits de configuration sur CRH
        
        // Mettre à 0 les 4 bits dans CRH
        gpio->CRH &= ~(0xF << (pin * 4));
        
        // Ecrire à la bonne position les 2 bits MODE
        gpio->CRH |= (conf & 0x03) << (pin * 4);
        
        // Ecrire à la bonne position les 2 bits CNF
        gpio->CRH |= (conf & 0x0C) << ((pin * 4) + 2);
    }
    
    // Éventuellement, écrire ODR pour certaines configurations ici.
}


	// renvoie 0 ou autre chose différent de 0
int MyGPIO_Read(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin){
	 
	if(GPIO->IDR & (0x01 << GPIO_Pin)){
		return 0 ;
	}else{
		return 1 ;
	}
}

void MyGPIO_Set(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin){
	
	//Utilisation du BSRR on met 1 dans le bit coorespondant au pin 
	GPIO->BSRR|= (0x01<<GPIO_Pin);
}

void MyGPIO_Reset(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin){
	//Mettre à 0 la broche du port 
	GPIO->BRR|=(0x01<<GPIO_Pin);
}


void MyGPIO_Toggle(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin) {
    
        //  basculer l'état de la pin 0 1 -> 1 / 1 1 -> 0
        GPIO->ODR ^= (1 << GPIO_Pin);
    
}
	


		




