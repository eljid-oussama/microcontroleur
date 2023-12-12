#include "../Include/girouette.h"
#include "../../Drivers/Include/MYGPIO.h"
#include "../../Drivers/Include/MYTimer.h"
#include <stdio.h>
#include <stdbool.h>

int angle_gr ; //Girouette angle
int angle_v; // Angle of voilier
int percentARR ; // Percentage ARR
bool flag =true ; //Drapeu pour angle 0

void gir_init(){
	MyTimer_Struct_TypeDef T3 = { TIM3, 1439, 0}; // Def of T3
	//CONFIGURATION INPUTS
	MyGPIO_Init(GPIOA, 6 , In_Floating); //input A
	MyGPIO_Init(GPIOA, 7 , In_Floating ); //input B
	MyGPIO_Init(GPIOA, 8 , In_Floating ); //input X
	
	//CONFIGURERATION TIM3

	
	
	
	while(flag){
		if (!MyGPIO_Read(GPIOA, 8)){ 
	       flag = false;
			TIM_encode(&T3);
			pwm_voilier();

		}
}
	
}


int readEncoderValue3(void) {
    // Lire la valeur du codeur incrémental (chaine A)
    return ((TIM3->CNT)/4); //angle de rotation
}


void gir_srvomoteur(){
   angle_gr = readEncoderValue3(); //recuperation de l'angle de rotation de la girouette
	
	if((angle_gr >= 0 && angle_gr <= 45) || (angle_gr >= 315 && angle_gr < 360)) // Calcul en vent avant
	{
		angle_v = 0;
	}
	else if((angle_gr > 45 && angle_gr < 180)) // Calcul en Babord
	{
		angle_v = (2*angle_gr/3)-30;
	}
	else // Calcul en Tribord
	{
		angle_v = -(2*angle_gr/3)+210;
	}
	
	percentARR = (5*angle_v)/90+5; // Calcules sur photo
  MyTimer_PWM_DutyCycle (TIM4, 1, percentARR); //Regle CCR1

}


void pwm_voilier(){
	MyTimer_Struct_TypeDef T4 = { TIM4, 60000, 25}; // Def of T4
	MyGPIO_Init(GPIOB, 6 , AltOut_Ppull);
	 //calcul de la arr et psc voir la fiche
		MyTimer_Base_Init(&T4);
	MyTimer_PWM_Init (TIM4 , 1);
	

	
		
	

	
	
	
}
	
