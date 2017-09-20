/*
	blink.c
	Autor: Guilherme Prearo
	Função: Pisca um LED na porta B5 com um período de 1s
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() {
	//Configura a porta B5 como output
	//O macro _BV(DDB5) equivale a (1 << DDB5)
	DDRB |= 1 << DDB5 ;

	while (1) {
		//Define a saída da porta B5 como nível lógico alto
		PORTB |= _BV(PORTB5) ;
		//Espera por 1000ms
		_delay_ms(1000) ;
		//Define a saída da porta B5 como nível lógico baixo
		PORTB &= ~_BV(PORTB5);
		//Espera mais 1000ms
		_delay_ms(1000) ;

	}
	return 0 ;
}
