#include "stm32f10x.h"
#include "MyGPIO.h"

int  main (void) {
	
MyGPIO_Init(GPIOC, 12 , Out_OD );

	//Test GPIO Driver
	//uint8_t pin =0 , port =0 , conf=0;
	
	/*GPIO_TypeDef * gpio[] = {GPIOA, GPIOB, GPIOC };
	for(port=0;port<3;port++){
		for(conf=0;conf<10;conf++) {
			for(pin=0;pin<16;pin++) MyGPIO_Init(gpio[port], pin,conf);
		}
   }*/
	
}




	
	