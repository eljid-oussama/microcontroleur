#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f10x.h"

void gir_init();
int gir_ecouter();
void CNT_zero(void);
int readEncoderValue3(void);

#endif