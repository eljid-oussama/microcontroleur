#ifndef USART_H
#define USART_H
#include <stdio.h>
#include <stdint.h>
#include "stm32f10x.h"

void USART_Init(USART_TypeDef * Usart);
void USART_Init_RX(USART_TypeDef * Usart);
void USART_Init_TX(USART_TypeDef * Usart);
void USART_RX_IRQ_Init(USART_TypeDef * Usart, int priority);
int8_t get_command();

#endif