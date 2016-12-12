/* 
* USART.cpp
*
* Created: 6/19/2016 5:57:48 PM
* Author: Animesh Sinha
*/


#include "USART.h"
#include <util/delay.h>
#include <avr/interrupt.h>

namespace atmicro
{
	// default constructor
	USART::USART(unsigned int baud)
	{
		UBRRH = (unsigned char) baud>>8;
		UBRRL = (unsigned char) baud;
		initialize();
	} //USART

	// default destructor
	USART::~USART()
	{
		UCSRB = 0x00;
		UCSRC = 0x00;
		UDR = 0x00;
	} //~USART

	void USART::initialize()
	{
		UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
		UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		sei();
	}

	void USART::transmit(unsigned char data)
	{
		while (!(UCSRA & (1<<UDRE)));
		UDR = data;
	}

	void USART::transmit(const char* data)
	{
		while(*data > 0)
		{
			transmit(*data++);
			_delay_ms(1);
		}
	}

	unsigned char USART::receive(void)
	{
		while (!(UCSRA & (1<<RXC)));
		return UDR;
	}	
}