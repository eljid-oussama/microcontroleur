#ifndef MYTIMER_H
#define MYTIMER_H

#include "stm32f10x.h"

typedef struct {
    TIM_TypeDef *timer; // TIM1 à TIM4
    unsigned short ARR;
    unsigned short PSC;
} MyTimer_Struct_TypeDef;

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer);
void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (* Pnt_fun) (void));
void MyTimer_PWM_Init (TIM_TypeDef * Timer, char Channel);
void MyTimer_PWM_DutyCycle (TIM_TypeDef * Timer, char Channel, int procentARR);

#define MyTimer_Base_Start(Timer) Timer->CR1 |= 0x1
#define MyTimer_Base_Stop(Timer) Timer->CR1 &= ~(0x1)
#endif