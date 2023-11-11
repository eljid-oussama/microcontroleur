#include "MYADC.h"
#include "stm32f10x.h"


void start_ADC( ADC_TypeDef*ADC , char nbconver , char voie ){
	RCC->APB2ENR|= RCC_APB2ENR_ADC1EN ; //Enable ADC 

 
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6 ; //change frequency to be < 14 by divding by 6
	
	
	ADC->CR2=ADC->CR2 | (1 << 0) | (1 << 20) | (7 << 17 ) ; //start conversion by setting ADON bit to 1 // le second decalage est lancer le trigger // le choix du timer(swstrart)
	
	ADC->SQR1 = ADC->SQR1 | (nbconver <<20); //le choix de nombre de conversions
	ADC->SQR3 |= voie ; //choix du voie de conversion 
	
}



	
	