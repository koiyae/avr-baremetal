#include <avr/io.h>
#include <util/delay.h>
#include "pin_defines.h"
#include "USART.h"

int main(void) {
    char serial_character;
    
    LED_DDR = 0xff;
    initUSART();
    printString("Hello, World!\r\n");

    for (;;) {
        serial_character = receiveByte();
        transmitByte(serial_character);
        transmitByte(':');
        printBinaryByte(serial_character);
        transmitByte('\r');
        transmitByte('\n');
        LED_PORT = serial_character;
    }
    
    return 0;
}