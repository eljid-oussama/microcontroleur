//#ifndef MYTIMER_H
#define MYTIMER_H

#include "stm32f10x.h"
#include "MyGPIO.h"

typedef struct
{
    TIM_TypeDef *Timer; // TIM1 à TIM4
    unsigned short ARR;
    unsigned short PSC;
} MyTimer_Struct_TypeDef;

/*
*****************************************************************************************
* @brief
* @param -> Paramètre sous forme d'une structure (son adresse) contenant les
* informations de base
* @Note -> Fonction à lancer systématiquement avant d'aller plus en détail dans les
* configurations plus fines (PWM, codeur inc...)
*************************************************************************************************
char prio de  0 à 15 
@Note : La f o n c ti o n MyTime r_Base_ Ini t d oi t a v oi r e te l a n cee au p r e al a bl e

*/
void MyTimer_Base_Init(TIM_TypeDef *Timer , uint16_t arr , uint16_t psc);
void MyTimer_ActiveIT (TIM_TypeDef * Timer , char Prio , void (*IT_function ) (void ) ) ;
void MyTimer_PWM(TIM_TypeDef * Timer , int Channel , int duree);
#define Timer_Start(Timer) Timer->CR1 = Timer->CR1 | ( 1 << 0);      
#define Timer_Stop(Timer) Timer->CR1 = Timer->CR1 & ~( 1 << 0);
