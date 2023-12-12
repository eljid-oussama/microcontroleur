#ifndef MYPLATEAU_H
#define MYPLATEAU_H

#include "stm32f10x.h"

void PLAT_Init();
void PLAT_Turn(int8_t power);
void PLAT_Update();

#endif