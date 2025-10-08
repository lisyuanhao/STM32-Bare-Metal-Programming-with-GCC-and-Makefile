#include <stdint.h>
extern uint32_t _estack;

extern uint32_t _load_text;
extern uint32_t _text_ram;
extern uint32_t _edata;

extern uint32_t _bss;
extern uint32_t _ebss;

// ¨ç¼ÆÁn©ú
void reset_handler(void);
void nmi_handler(void);
int main(void);

__attribute__((section(".isr_vector")))
uint32_t *vector_table[] = {
    (uint32_t *) &_estack,
    (uint32_t *) reset_handler,
    (uint32_t *) nmi_handler,
};

__attribute__((section(".reset_handler")))
void reset_handler(void){
    uint32_t *src, *dst;
    src = &_load_text;
    dst = &_text_ram;
    while (dst < &_edata) *dst++ = *src++;
    for(dst = &_bss; dst < &_ebss; dst++) 
        *dst = 0;
    
    main();
}

void nmi_handler(void){
    while(1);
}