#include "reg.h"

int global = 123;

int main(void){
    unsigned int c = 0;
    
    c = global;
    
    RCC_AHB4ENR |= (1 << 1);    
    GPIO_MODER &= ~(0x3 << 0);  
    GPIO_MODER |= (0x1 << 0);    
    GPIO_OTYPER &= ~(0x1 << 0);  
    
    while (1){
        LED_ON();
        for(c = 0; c < 100000; c++);
        LED_OFF();
        for(c = 0; c < 100000; c++);
    }
}
