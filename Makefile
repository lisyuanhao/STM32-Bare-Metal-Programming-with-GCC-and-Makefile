CROSS_COMPILE ?= arm-none-eabi-

blink.o: blink.c
	$(CROSS_COMPILE)gcc -mcpu=cortex-m7 -mthumb -nostartfiles -c blink.c -o blink.o

startup.o: startup.c
	$(CROSS_COMPILE)gcc -mcpu=cortex-m7 -mthumb -nostartfiles -c startup.c -o startup.o

blink.out: blink.o startup.o simple.ld
	$(CROSS_COMPILE)ld -T simple.ld -Map=blink.map --gc-sections --strip-all -o blink.out blink.o startup.o

blink.bin: blink.out
	$(CROSS_COMPILE)objcopy -j .text -O binary blink.out blink.bin
	$(CROSS_COMPILE)size blink.out

flash: blink.bin
	openocd \
		-f interface/stlink.cfg \
		-f target/stm32h7x.cfg \
		-c "init" \
		-c "reset init" \
		-c "flash write_image erase blink.out" \
		-c "reset run" \
		-c "shutdown"
clean:
	-del /Q *.o *.bin *.out *.elf *.lst *.map blink 2>nul || echo.
