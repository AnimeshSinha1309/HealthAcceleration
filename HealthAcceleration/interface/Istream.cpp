/*
* Istream.cpp
*
* Created: 11/17/2016 12:35:04 PM
* Author: Animesh Sinha
*/


#include "Istream.h"
#include <string.h>

namespace atmicro
{
	// default constructor
	Istream::Istream()
	{
		clear();
		disabledKey = 100;
	} //Istream

	// default destructor
	Istream::~Istream()
	{
	} //~Istream
	
	void Istream::update(Keypad& pad)
	{
		KeypadMatrix data = pad.isPressed();
		if (data.get(disabledKey/4, disabledKey%4) == false)
		disabledKey = 100;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (data.get(i, j) && disabledKey != i*4 + j)
				{
					push(keymap[i][j]);
					disabledKey = i*4 + j;
				}
	}
	
	void Istream::push(char chr)
	{
		if (length == BUFFER_SIZE)
		{
			clear();
			return;
		}
		stream[length] = chr;
		length++;
		stream[length] = '\0';
	}
	
	void Istream::clear()
	{
		for (int i = 0; i < BUFFER_SIZE; i++)
			stream[i] = ' ';
		stream[0] = '\0';
		length = 0;
	}
}