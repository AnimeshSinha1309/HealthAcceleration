/* 
* EEPROM.cpp
*
* Created: 5/11/2016 10:10:57 PM
* Author: Animesh Sinha
*/


#include "EEPROM.h"
#include <avr/io.h>

namespace atmicro {
	// default constructor
	EEPROM::EEPROM()
	{
	} //EEPROM

	// default destructor
	EEPROM::~EEPROM()
	{
	} //~EEPROM

	unsigned char EEPROM::read(unsigned int address)
	{
		while(EECR & (1<<EEWE));
		EEAR = address;
		EECR |= 1<<EERE;
		return EEDR;
	}

	void EEPROM::write(unsigned int address, unsigned char data)
	{
		while(EECR & (1<<EEWE));
		EEAR = address;
		EEDR = data;
		EECR |= 1<<EEMWE;
		EECR |= 1<<EEWE;
	}
}