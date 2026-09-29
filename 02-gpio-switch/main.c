#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB5);
    PORTB &= ~(1 << PB5);

    while(1) {
        if (PINB & (1 << PB3))
            PORTB |= (1 << PB5);
        else
            PORTB &= ~(1 << PB5);
    }

    return 0;
}

/*
O código acima é responsável por trabalhar nos 3 principais registradores E/S do ATmega328P:
DDRB, PORTB e PINB são registradores de 8 bits que controlam o mesmo conjunto de 8 pinos (PB0 a PB7 - O bit N 
corresponde ao pino N).

DDRB: Data Direction Register B - responsável pela definição de um pino como entrada ou saída. (0 entrada e 1 saida)
PORTB: Registrador de escrita - A sua função muda conforme a direção do pino
        Se o pino é saída (DDRB em 1), PORTB define o nível que sai: 0 é terra, 1 é 5V.
        Se o pino é entrada (DDRB em 0), PORTB não escreve nada, mas liga ou desliga o pull-up internet. 1 liga o resistor
            e 0 deixa o pino flutuando.
PINB: Registrador de leitura. É só leitura e mostra o estado elétrico real do pino, seja ele entrada ou saída. É o único
      que pode mudar sem que o código mexa em nada, porque que mo muda é, na verdade, o mundo físico. Por isso a importância
      de volatile ao trabalhar com ele.

Basicamente, atribuí entrada ao PINB3 e o conectei a um switch numa protoboard, de modo que o led acendesse
sempre que ele fosse pressionado.
*/