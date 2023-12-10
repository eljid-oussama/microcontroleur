#include "../Include/MYADC.h"
#include "stm32f10x.h"

/*---------------------Single conversion ------------------*/

/* ADC a pour role de fournir un nb entier à l'image d'une tension
La resolution d'un ADC renseigne plus au moins directement sur la quantite de valeurs entieres que peut prendre le nb de sortie de l'ADC  */

/*Periode d'echantillonage Tc est l'interv de temps entre 2 prise d'échantillons successifs*/
/* --->p1 (datasheet) :il y a 2ADC (2*12bits) donc 12bits de resolution est une etendue de mesure(plage de l'entree de l'ADC) de 0 à 3.3V*/

/* p202 :start by setting the ADOV bit in the ADC_CR2 register*/

/* --->p230 ADC_DR (regular data register)*/

/*
p219  SR->EOC (end of conversion) // CR1->EOCIE (interrupt enable for EOC*/

/*p201-231 dans le registre SQR1 , on a 4 bits pour indiquer combien de canaux on veut (on en veut 1seul , donc on met L=0) , SQ->on metle channel qu'on veut */

/*ADC->CR1 |=ADC_CR1_EOCIE <-> ADC->CR1 |=(0x1<<5)*/

/* temps d'acquisition = Nb_cycle x temps de cycle*/
/*temps de cycle =1/12Mhz */

/* p225 ADC->SMPR* : on nrentre la valeur de cycle la plus proche de celle souhaitee*/

/*La partie échantillonneur bloqueur est paramétrée par le registre ADC_SMPR1 et ADC_SMPR2. C’est là qu’on
peut agir sur la durée d’échantillonnage.*/


void start_ADC( ADC_TypeDef*ADC , char nbconver , char voie ){
	if(ADC == ADC1){
	RCC->APB2ENR|= RCC_APB2ENR_ADC1EN ; //Enable clock for  ADC1
	}else{
		RCC->APB2ENR|= RCC_APB2ENR_ADC2EN ; //Enable clock for  ADC2 
	}
	
	ADC->CR2 |= ADC_CR2_ADON ; //lancement de l'ADC

 
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6 ; //change frequency to be < 14 by divding by 6
	
	
	ADC->CR2=ADC->CR2 | (1 << 0) | (1 << 20) | (7 << 17 ) ; //start conversion by setting ADON bit to 1 // le second decalage est lancer le trigger // le choix du timer(swstrart)
	
	ADC->SQR1 = ADC->SQR1 | (nbconver <<20); //le choix de nombre de conversions
	ADC->SQR3 |= voie ; //choix du voie de conversion 
	
}




uint16_t ADC_Value(ADC_TypeDef * ADC)
{
	// On lance la conversion 
	ADC->CR2 |= ADC_CR2_ADON;
	
	//on attend la fin de la conversion pour recuperer les valeurs
	while (!(ADC->SR & ADC_SR_EOC)) { }
	
	//recuperation des valeurs
	return ADC->DR;
}




	
	