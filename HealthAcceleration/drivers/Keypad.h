/* 
* Keypad.h
*
* Created: 11/15/2016 4:16:48 PM
* Author: Manish Sinha
*/


#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "Input.h"

namespace atmicro
{
	class KeypadMatrix
	{
	public:
		bool data[4][4];
		bool get(int x, int y)
		{
			return data[x][y];
		}
		void set(int x, int y, bool val)
		{
			data[x][y] = val;
		}
	}; //KeypadMatrix

	class Keypad : public Input
	{
	//variables
	public:
		PORT port;
		KeypadMatrix status;
	protected:
	private:

	//functions
	public:
		Keypad(PORT port);
		~Keypad();
		void initialize();
		KeypadMatrix isPressed();
		bool isPressed(short x, short y);
		KeypadMatrix undebouncedStatus();
		static bool switchPressed(PIN pin);
	protected:
	private:
	}; //Keypad
}

#endif //__KEYPAD_H__
