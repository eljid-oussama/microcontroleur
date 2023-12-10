#include "../Include/girouette.h"
#include "../../Drivers/Include/MYGPIO.h"
#include "../../Drivers/Include/MYTimer.h"
#include <stdio.h>


void gir_init(){
	MyTimer_Struct_TypeDef T3 = { TIM3, 1439, 0}; // Def of T3
	//CONFIGURATION INPUTS
	MyGPIO_Init(GPIOA, 6 , In_Floating); //input A
	MyGPIO_Init(GPIOA, 7 , In_Floating ); //input B
	MyGPIO_Init(GPIOA, 8 , In_Analog ); //input X
	MyGPIO_Init(GPIOA,  13, Out_Ppull );
	
	//CONFIGURERATION  TIM2 & TIM3
	MyTimer_Base_Init(&T3);
	
	MyGPIO_Init(GPIOC, 7 , AltOut_Ppull ); //input X
	
	
}


int readEncoderValue3(void) {
    // Lire la valeur du codeur incrémental (chaine A)
	 printf("%d\n",(int)(TIM3->CNT >> 2));
    return ((int)(TIM3->CNT >> 2)); //angle de rotation
}
//

//void CNT_zero(void){
//	if (MyGPIO_Read(GPIOA, 8)){
//	TIM3->CNT = 0x0000;
//	MyGPIO_Set(GPIOA, 13);
//	}
//}


int gir_ecouter(){
}