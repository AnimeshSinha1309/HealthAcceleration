/* 
* DigitalOutput.cpp
*
* Created: 4/10/2016 12:32:16 PM
* Author: Manish Sinha
*/


#include "DigitalOutput.h"

namespace atmicro 
{
	// default constructor
	DigitalOutput::DigitalOutput(PIN pin)
	{
		this->pin = pin;
		this->status = false;
		initialize();
	} //DigitalOutput

	// default destructor
	DigitalOutput::~DigitalOutput()
	{
		setDirection(pin, DDR_INPUT);
		setStatus(pin, LOW);
	} //~DigitalOutput

	void DigitalOutput::on()
	{
		setStatus(pin, HIGH);
		status = true;
	}

	void DigitalOutput::off()
	{
		setStatus(pin, LOW);
		status = false;
	}

	bool DigitalOutput::toggle()
	{
		if (status == false)
			on();
		else if(status == true)
			off();
		return status;
	}

	void DigitalOutput::initialize()
	{
		setDirection(pin, DDR_OUTPUT);
		setStatus(pin, LOW);
	}
}