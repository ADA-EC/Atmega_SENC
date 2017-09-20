/*
	button.c
	Autor: Guilherme Prearo
	Função: Acende o LED da porta 13 do arduino (PB5) enquanto o
			botão da porta 12 (PB4) estiver pressionado.
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() {
	//Configura a porta B5 como output
	//O macro _BV(DDB5) equivale a (1 << DDB5)
	DDRB |= 1 << DDB5 ;
	DDRB &= ~(0 << DDB4) ;

	while (1) {
		if (PINB & (1 << PINB4)) {
			PORTB |= (1 << PORTB5) ;
		} else {
			PORTB &= ~(1 << PORTB5) ;
		}
	}
	return 0 ;
}
