#include "stm32f10x.h"
int main(void)
{
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 <<4 );
	
	// configuration du PC8 input floating input 
  GPIOC->CRH = GPIOC->CRH & ~(0xf << 0) ;
	GPIOC->CRH = GPIOC->CRH | (0x004 << 0) ;

//configuration du PC10 en output push/pull 
  GPIOC->CRH = GPIOC->CRH & ~(0xf << 8) ;
	GPIOC->CRH = GPIOC->CRH | (0x01 << 8) ;
	
	
  
while(1){
	if(GPIOC->IDR & (0x01 << 8 )){
		//le bouton est presse -> LED allumer 
			GPIOC ->ODR = GPIOC ->ODR  & (0 << 10) ;
		  }else{
				//le bouton est non pressé -> LED est éteint
				GPIOC ->ODR = GPIOC ->ODR  | ( 1 << 10) ;
		
}

	}

	/*
	//configuration du PA5 en output push/pull
	GPIOA->CRL = GPIOA->CRL & ~(0xf << 20) ;
	GPIOA->CRL = GPIOA->CRL | (0x01 << 20) ;
	
	//configuration du PC13 en input floating input 
	GPIOC->CRH = GPIOC->CRH & ~(0xf << 20) ;
	GPIOC->CRH = GPIOC->CRH | (0x004 << 20) ;
	
	while(1){
		if(GPIOC->IDR & (0x01 << 13 )){
			
			//le bouton est presse -> LED allumer 
			GPIOA ->ODR = GPIOA ->ODR  & (0 << 5) ;
		}else{
				//le bouton est non pressé -> LED est éteint
				GPIOA ->ODR = GPIOA ->ODR  | (1 << 5) ;
		
}
}*/
	

}
