//#ifndef MYTIMER_H
#define MYTIMER_H

#include "stm32f10x.h"
#include "MyGPIO.h"

typedef struct
{
    TIM_TypeDef *Timer; // TIM1 � TIM4
    unsigned short ARR;
    unsigned short PSC;
} MyTimer_Struct_TypeDef;

/*
*****************************************************************************************
* @brief
* @param -> Param�tre sous forme d'une structure (son adresse) contenant les
* informations de base
* @Note -> Fonction � lancer syst�matiquement avant d'aller plus en d�tail dans les
* configurations plus fines (PWM, codeur inc...)
*************************************************************************************************
*/
void MyTimer_Base_Init(TIM_TypeDef *Timer , uint16_t arr , uint16_t psc);

#define MyTimer_Base_Start(Timer) (...)
#define MyTimer_Base_Stop(Timer) (...)
