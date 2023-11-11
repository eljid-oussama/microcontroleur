#ifndef MYGPIO_H
#define MYGPIO_H

#include "stm32f10x.h"

typedef struct
{
    GPIO_TypeDef *GPIO;
    char GPIO_Pin; // numero de 0 a 15
    char GPIO_Conf; // voir ci-dessous
} MyGPIO_Struct_TypeDef;

#define In_Floating 0x04 // à compléter
#define In_PullDown 0x08 // à compléter
#define In_PullUp 0x0a // à compléter
#define In_Analog 0x00 // à compléter
#define Out_Ppull 0x01 // à compléter
#define Out_OD 0x05 // à compléter
#define AltOut_Ppull 0x09 // à compléter
#define AltOut_OD 0x0d // à compléter

void MyGPIO_Init(GPIO_TypeDef *gpio, uint8_t pin , uint8_t conf );
int MyGPIO_Read(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin); // renvoie 0 ou autre chose différent de 0
void MyGPIO_Set(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef *GPIO, uint8_t GPIO_Pin);

#endif
