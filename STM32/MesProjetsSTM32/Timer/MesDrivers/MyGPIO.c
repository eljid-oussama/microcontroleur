#include "stm32f10x.h"
#include "MyGPIO.h"

void MyGPIO_Init(GPIO_TypeDef *gpio, uint8_t pin, uint8_t conf) {
    
	  if(gpio == GPIOA){
			RCC->APB2ENR |= (0x01 << 2) ;
		}
		
		if(gpio == GPIOB){
			RCC->APB2ENR |= (0x01 << 3) ;
		}
		
		if(gpio == GPIOC){
			RCC->APB2ENR |= (0x01 << 4) ;
		}
		
	 
    if (pin < 8) {
			gpio->CRL &= ~(0xF << (pin * 4));
    if (conf == 0x0a) {
        gpio->CRL = gpio->CRL | (0x08 << (pin * 4));
        gpio->ODR = gpio->ODR | (1 << pin);
    } else if (conf == 0x08) {
        gpio->CRL = gpio->CRL | (0x08 << (pin * 4));
        gpio->ODR = gpio->ODR | (0 << pin);
    } else {
        gpio->CRL = gpio->CRL | (conf << (pin * 4));
    }
}
	if (pin > 7){
		// pin > 7 : même chose avec CRH
       // pin -= 8; // Pour aligner les bits de configuration sur CRH
        gpio->CRH &= ~(0xF << ((pin-8) * 4));
       if (conf == 0x0a) {
        gpio->CRH = gpio->CRH | (0x08 << ((pin - 8) * 4));
        gpio->ODR = gpio->ODR | (1 << pin);
    } else if (conf == 0x08) {
        gpio->CRH = gpio->CRH | (0x08 << ((pin - 8) * 4));
        gpio->ODR = gpio->ODR | (0 << pin);
    } else {
        gpio->CRH = gpio->CRH | (conf << ((pin - 8) * 4));
    }
			
    }
    
    
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