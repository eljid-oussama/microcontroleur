#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

#define In_Floating 0x4
#define In_PullDown 0x8
#define In_PullUp 0xF
#define In_Analog 0x0
#define Out_Ppull 0x01
#define Out_OD 0x7
#define AltOut_Ppull 0x9
#define AltOut_OD 0xC

void MyGPIO_Init ( GPIO_TypeDef * GPIO, char GPIO_Pin, char GPIO_Conf);
int MyGPIO_Read ( GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Set ( GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Reset ( GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Toggle ( GPIO_TypeDef * GPIO, char GPIO_Pin);

#endif
