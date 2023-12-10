#include "../Include/MYGPIO.h"
#include <stdio.h>

void MyGPIO_Init ( GPIO_TypeDef * GPIO, char GPIO_Pin, char GPIO_Conf){
	
	
	/* Turns on the clock of needed GPIO*/
	if (GPIO == GPIOA){
		RCC->APB2ENR |= (0x01 << 2);
	}
	else if (GPIO == GPIOB) {
		RCC->APB2ENR |= (0x01 << 3);
	}
	else if (GPIO == GPIOC){
		RCC->APB2ENR |= (0x01 << 4);
	}
	else { /* GPIO == GPIOD */
		RCC->APB2ENR |= (0x01 << 5);
	}
	
	
	/* Sets the mode on the specific pin */
		/* Case when pin <= 7 so CRL */

	if (GPIO_Pin <= 7) {
		GPIO->CRL &= ~(0xF << 4*GPIO_Pin);
		if (GPIO_Conf == 0xF){ // Case when its In_PullUp
			GPIO->CRL |= (0x8 << 4*GPIO_Pin); // Sets pin to PullUp
			GPIO->ODR |= (0x1 << GPIO_Pin); // Sets ODR of Pin to 1
		}
		
		else {
			GPIO->CRL |= (GPIO_Conf << 4*GPIO_Pin);
			GPIO->ODR &= ~(0x1 << GPIO_Pin); // Sets ODR of Pin to 0
		}
	}
	
	/* Case when pin > 7 so CRH */
	else {
		GPIO->CRH &= ~(0xF << 4*(GPIO_Pin-8));
		if (GPIO_Conf == 0xF){ // Case when its In_PullUp
			GPIO->CRH |= (0x8 << 4*(GPIO_Pin-8)); // Sets pin to PullUp
			GPIO->ODR |= (0x1 << GPIO_Pin); // Sets ODR of Pin to 1
		}
		
		else {
			GPIO->CRH |= (GPIO_Conf << 4*(GPIO_Pin-8));
			GPIO->ODR &= ~(0x1 << GPIO_Pin); // Sets ODR of Pin to 0
		}
	}
}


int MyGPIO_Read ( GPIO_TypeDef * GPIO, char GPIO_Pin){
	if (GPIO->IDR & (0x1 << GPIO_Pin)){
		return 0;
	}
	else {
		return 1;
	}
}
	

void MyGPIO_Set ( GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR |= (0x1 << GPIO_Pin);
}

void MyGPIO_Reset ( GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR &= ~(0x1 << GPIO_Pin);
}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO, char GPIO_Pin){
	if (GPIO->ODR & (0x1 << GPIO_Pin)){
		GPIO->ODR &= ~(0x1 << GPIO_Pin);
	}
	else {
		GPIO->ODR |= (0x1 << GPIO_Pin);
	}
}