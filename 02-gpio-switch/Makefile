MCU	   = atmega328p
F_CPU  = 160000000UL
PORT   = /dev/ttyACM0

CC     = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

all: main.hex

main.elf: main.c
	$(CC) $(CFLAGS) -o main.elf main.c

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

flash: main.hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b 115200 -U flash:w:main.hex:i

clean:
	rm -f main.elf main.hex
 