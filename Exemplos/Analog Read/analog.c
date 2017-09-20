/*
	analog.c
	Autor: Guilherme Prearo
	Função: Lê o valor de tensão da porta C0 convertido em um valor digital e então seta o PWM de modoque a intensidade do LED em D6 seja proporcional à tensão
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() {
	//Configura a porta D6 como saída 
	DDRB |= _BV(PB5) ;
	
	//Vref = AVcc; Bits ajustados a esquerda; Canal 0
	ADMUX = (1 << REFS0) | (1 << ADLAR) | (1 << MUX0);
	//Habilita a conversão AD
	ADCSRA  = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) ;

	unsigned char result = 0 ;
	while (1) {
		//Inicia a conversão AD
		ADCSRA |= (1 << ADSC) ;
		//Espera a conversão terminar
		while (!(ADCSRA & (1 << ADIF))) ;
		//Configura o duty cycle conforme a entrada analógica
		result = ADCH ;

		if (result > 127) {
			PORTB |= (1 << PORTB5) ;
		} else {
			PORTB &= ~(1 << PORTB5) ;
		}
		//Espera um pouco antes da próxima conversão
		_delay_ms(10) ;
	}
	return 0 ;
}
