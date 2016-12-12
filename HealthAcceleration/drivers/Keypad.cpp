/* 
* Keypad.cpp
*
* Created: 11/15/2016 4:16:47 PM
* Author: Animesh Sinha
*/


#include "Keypad.h"
#include "../controller/registry.h"

#define DEBOUNCE_MINCYCLES 3
#define DEBOUNCE_MAXCYCLES 100
#define DEBOUNCE_CONFIDFRAC 0.7

namespace atmicro
{
	// default constructor
	Keypad::Keypad(PORT port)
	{
		this->port = port;
		initialize();
	} //Keypad

	// default destructor
	Keypad::~Keypad()
	{
		setDirection(port, 0x00);
		setStatus(port, 0x00);
	} //~Keypad

	void Keypad::initialize()
	{
		setDirection(port, 0x0F);
		setStatus(port, 0xFF);
	}
	
	KeypadMatrix Keypad::undebouncedStatus()
	{
		KeypadMatrix result;
		for (int i = 0; i < 4; i++)
		{
			setStatus(IOPORTA, (POSITION)i, LOW);
			for (int j = 0; j < 4; j++)
				result.set(i, j, switchPressed((PIN)(port + 4 + j)));
			setStatus(IOPORTA, (POSITION)i, HIGH);			
		}
		return result;
	}

	KeypadMatrix Keypad::isPressed()
	{	
		KeypadMatrix result;
		for (int i = 0; i < 4; i++)
		{
			setStatus((PIN)(port + i), LOW);
			for (int j = 0; j < 4; j++)
			result.set(i, j, switchPressed((PIN)(port + 4 + j)));
			setStatus((PIN)(port + i), HIGH);
		}
		return result;
	}

	bool Keypad::isPressed(short x, short y)
	{
		bool result = false;
		setStatus((PIN)(port + x), LOW);
		result = switchPressed((PIN)(port + 4 + y));
		setStatus((PIN)(port + x), HIGH);
		return result;
	}

	bool Keypad::switchPressed(PIN pin)
	{
		bool result = LOW;
		for (double i = 0.0, high = 0.0; i < DEBOUNCE_MAXCYCLES; i++)
		{
			if (!getStatus(pin))
			high++;
			// conditions to break the loop and accept result
			if (i > DEBOUNCE_MINCYCLES && high/i >= DEBOUNCE_CONFIDFRAC)
			{
				result = HIGH;
				break;
			}
			if (i > DEBOUNCE_MINCYCLES && (1 - high/i) >= DEBOUNCE_CONFIDFRAC)
			{
				result = LOW;
				break;
			}
			if (i == DEBOUNCE_MAXCYCLES - 1)
			{
				if (high/i > 0.5)
					result = HIGH;
				else
					result = LOW;
				break;
			}
		}
		// Reporting the status and updating variables
		return result;
	}
}