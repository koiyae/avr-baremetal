MCU = atmega328p
F_CPU = 16000000UL
PORT = /dev/ttyACM0

CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -std=gnu99 -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)

TARGET = main

all: $(TARGET).hex

$(TARGET).elf: main.c USART.c
	$(CC) $(CFLAGS) main.c USART.c -o $(TARGET).elf

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex

flash: $(TARGET).hex
	avrdude -c arduino -p m328p -P $(PORT) -b 115200 -U flash:w:$(TARGET).hex:i

clean:
	rm -f *.elf *.hex *.o
