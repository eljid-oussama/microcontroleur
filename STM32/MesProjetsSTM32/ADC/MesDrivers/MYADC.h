//#ifndef MYTIMER_H
#define MYADC_H

#include "stm32f10x.h"
#include "MyGPIO.h"

/**
 * @brief Initialise l'ADC donn? sur le channel donn? en mode Single ou (nbconver) Conversion.
 * Le GPIO correspondant au channel donn? doit ?tre configur? en Output Push Pull
 * que cela fonctionne.
 * @example 	Port_IO_Init_Input(GPIOA, 1);
* 					  Init_ADC_Single_Conv(ADC1, 1);
 */
void start_ADC(ADC_TypeDef * ADC , char nbconver , char voie);


/*recuperation des valeurs convertis*/
uint16_t ADC_Value(ADC_TypeDef * ADC);
