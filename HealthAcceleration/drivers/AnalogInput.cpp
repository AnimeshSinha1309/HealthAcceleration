/* 
* AnalogInput.cpp
*
* Created: 4/28/2016 10:58:39 PM
* Author: Manish Sinha
*/


#include "AnalogInput.h"
#include <avr/interrupt.h>
#include <avr/io.h>

namespace atmicro
{
	// default constructor
	AnalogInput::AnalogInput(ADCchannel pin)
	{
		this->pin = pin;
		this->value = 0;
		globablInit();
	} //AnalogInput

	AnalogInput::AnalogInput(ADCchannel pin, void (*func)(int, ADCchannel))
	{
		this->pin = pin;
		this->value = 0;
		globablInit();
		setCallback(func);
	}

	// default destructor
	AnalogInput::~AnalogInput()
	{
		if(isLive())
		{
			ADMUX &= (0b11100000);
			stopConversion();
		}
	} //~AnalogInput

	bool AnalogInput::isLive()
	{
		return (ADMUX & 0b00011111) == pin;
	}

	void AnalogInput::globablInit(ADCconfig::VREF vref, ADCconfig::ADPS adps)
	{
		ADMUX &= ~((1<<REFS0) | (1<<REFS1));
		ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
		ADCSRA |= adps << ADPS0;
		ADMUX |= vref << REFS0;
		ADCSRA |= 1<<ADIE;
		ADCSRA |= 1<<ADEN;
		sei();
	}

	void AnalogInput::initialize()
	{
		ADMUX &= (0b11100000);
		ADMUX |= pin;
	}

	int AnalogInput::readValue()
	{
		if (this->isLive())
		{
			uint16_t value8bit = ADCL;
			this->value = (ADCH << 8) | value8bit;
			return this->value;
		}
		else
		{
			return this->value;
		}
	}

	void AnalogInput::startConversion()
	{
		this->initialize();
		ADCSRA |= 1 << ADSC;
	}

	void AnalogInput::stopConversion()
	{
		ADCSRA &= ~(1 << ADSC);
	}

	void AnalogInput::setCallback(void (*func)(int, ADCchannel))
	{
		callback = func;
	}

	void AnalogInput::process()
	{
		readValue();
		callback(value, pin);
	}
}