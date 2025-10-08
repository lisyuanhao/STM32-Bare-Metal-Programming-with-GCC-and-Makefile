#define AHB4_GPIOB 0x58020400
#define AHB4_RCC 0x58024400

#define RCC_AHB4ENR_OFFSET 0x0E0
#define GPIO_MODER_OFFSET 0x00
#define GPIO_OTYPER_OFFSET 0x04
#define GPIO_BSRR_OFFSET 0x18

#define RCC_AHB4ENR (*((volatile unsigned long *)(AHB4_RCC + RCC_AHB4ENR_OFFSET)))
#define GPIO_MODER (*((volatile unsigned long *)(AHB4_GPIOB + GPIO_MODER_OFFSET)))
#define GPIO_OTYPER (*((volatile unsigned long *)(AHB4_GPIOB + GPIO_OTYPER_OFFSET)))
#define GPIO_BSRR (*((volatile unsigned long *)(AHB4_GPIOB + GPIO_BSRR_OFFSET)))

#define LED_ON() (GPIO_BSRR = (0x1))
#define LED_OFF() (GPIO_BSRR = (0x1 << 16))