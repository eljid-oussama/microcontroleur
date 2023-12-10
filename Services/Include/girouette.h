#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f10x.h"
#include "../../Drivers/Include/MYGPIO.h"
#include "../../Drivers/Include/MYTimer.h"

void gir_init();
int readEncoderValue3(void);
void gir_srvomoteur();
void pwm_voilier();

#endif