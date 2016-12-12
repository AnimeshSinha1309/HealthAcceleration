/* 
* Pinset.cpp
*
* Created: 5/15/2016 12:12:48 PM
* Author: Animesh Sinha
*/


#include "Pinset.h"
#include "../drivers/Device.h"
#include <util/delay.h>

namespace atmicro
{
	// default constructor
	Pinset::Pinset(int size, PIN set[])
	{
		this->size = size;
		for(int i = 0; i < size; i++)
			this->pins[i] = set[(size-1)-i];
	}

	// default destructor
	Pinset::~Pinset()
	{
	}

	unsigned int Pinset::getData()
	{
		uint32_t data = 0;
		for (int i = 0; i < this->size; i++)
		{
			Device::setDirection(pins[i], DDR_INPUT);
			data = data * 2 + Device::getStatus(pins[i]);
		}
		return data;
	}

	void Pinset::putData(unsigned int data)
	{
		for (int i = 0; i < this->size; i++, data /= 2)
		{
			Device::setDirection(pins[i], DDR_OUTPUT);
			if (data % 2 == HIGH)
				Device::setStatus(pins[i], HIGH);
			else
				Device::setStatus(pins[i], LOW);
		}
	}
}