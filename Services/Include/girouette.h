#ifndef MYPLATEAU_H
#define MYPLATEAU_H

#include "MyGPIO.h"
#include "MyTimer.h"
#include "stm32f10x.h"

void gir_init();
int gir_ecouter();
void CNT_zero(void);
int readEncoderValue3(void);

#endif