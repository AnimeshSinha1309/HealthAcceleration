/* 
* Accelerometer.cpp
*
* Created: 12/3/2016 2:22:14 PM
* Author: Animesh Sinha
*/


#include "Accelerometer.h"
#include <avr/interrupt.h>

namespace atmicro
{
	// default constructor
	Accelerometer::Accelerometer(ADCchannel chx, ADCchannel chy, ADCchannel chz)
	{
		//setting the values
		adcx = chx; adcy = chy; adcz = chz;
		x = 0; y = 0; z = 0;
		//setting global config
		ADMUX &= ~((1<<REFS0) | (1<<REFS1));
		ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
		ADCSRA |= ADCconfig::PS16 << ADPS0;
		ADMUX |= ADCconfig::IREF << REFS0;
		ADCSRA |= 1<<ADIE;
		ADCSRA |= 1<<ADEN;
		sei();
		//initializing and starting ADC conversion
		ADMUX &= (0b11100000);
		ADMUX |= adcx;
		ADCSRA |= 1 << ADSC;
	} //Accelerometer

	// default destructor
	Accelerometer::~Accelerometer()
	{
	} //~Accelerometer

	void Accelerometer::update()
	{
		if ((ADMUX & 0b00011111) == adcx)
		{
			uint16_t lowerX = ADCL;
			x = (ADCH << 8) | lowerX;
			ADMUX &= (0b11100000);
			ADMUX |= adcy;
		}
		else if ((ADMUX & 0b00011111) == adcy)
		{
			uint16_t lowerY = ADCL;
			y = (ADCH << 8) | lowerY;
			ADMUX &= (0b11100000);
			ADMUX |= adcz;
		}
		else if ((ADMUX & 0b00011111) == adcz)
		{
			uint16_t lowerZ = ADCL;
			z = (ADCH << 8) | lowerZ;
			ADMUX &= (0b11100000);
			ADMUX |= adcx;
		}
		ADCSRA |= 1 << ADSC;
	}
}