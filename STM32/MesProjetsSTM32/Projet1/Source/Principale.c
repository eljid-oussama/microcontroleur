#include "stm32f10x.h"

// Function prototypes
void GPIO_Configuration(void);
void delay_ms(uint32_t ms);

int main(void) {
    // Initialize GPIO
    GPIO_Configuration();

    while (1) {
        // Check if the button is pressed (PC13 is low)
        if ((GPIOC->IDR & (1 << 1 )) == 0) {
            // Button is pressed, turn on the LED (PA5)
            GPIOA->BSRR = (1 << 10) ;
        } else {
            // Button is not pressed, turn off the LED (PA5)
            GPIOA->BRR = (1 << 10);
        }

        // Delay to debounce the button (you can adjust the delay as needed)
        delay_ms(50);
    }
}

void GPIO_Configuration(void) {
    // Enable the clock for GPIOA and GPIOC
	  
    RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;


    // Configure PC13 (Button) as input with pull-up
    
    GPIOC->CRL &= ~(0x0F << 4); // Clear the bits
    GPIOC->CRL |= (0x08 << 4);

    // Configure PA5 (LED) as output
    GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF10);
    GPIOA->CRL |= GPIO_CRL_MODE5_0; // Output mode, max speed 10 MHz
}

void delay_ms(uint32_t ms) {
    // Simple delay function (not precise, for demonstration purposes)
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 10000; j++) {
            __NOP(); // No operation, to prevent optimization
        }
    }
}
