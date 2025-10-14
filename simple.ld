MEMORY 
{ 
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024k 
    RAM (rwx) : ORIGIN = 0x24000000, LENGTH = 512k 
} 

ENTRY(reset_handler)

SECTIONS 
{
    .flash :{
        KEEP(*(.isr_vector));
        KEEP(*(.reset_handler));
        _load_text = .;
    } > FLASH

    .text_ram : AT(_load_text){
        _text_ram = .;
        *(.text)
        *(.text*)
        _load_data = .;        
    } > RAM

    .data :AT (_load_data){ 
        _data = .;
        *(.data)
        *(.data*)
        _edata = . ;
    } > RAM 

    .bss : {
        _bss = . ;
        *(.bss)
        *(.bss*)
        _ebss = . ;
    } > RAM 

    _end = . ;
    _estack = ORIGIN(RAM) + LENGTH(RAM);

    /DISCARD/ : {
        *(.glue_7)
        *(.glue_7t)  
        *(.vfp11_veneer)
        *(.v4_bx)
        *(.iplt)
        *(.rel.dyn)
        *(.rel.iplt)
        *(.igot.plt)
    }
}
