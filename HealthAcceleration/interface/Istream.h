/* 
* Istream.h
*
* Created: 11/17/2016 12:35:05 PM
* Author: Animesh Sinha
*/


#ifndef __ISTREAM_H__
#define __ISTREAM_H__

#define BUFFER_SIZE 25

#include "../drivers/Keypad.h"

namespace atmicro {
	class Istream
	{
	//variables
	public:
		char stream[BUFFER_SIZE];
		int length = 0;
	protected:
		char keymap[4][4] = {
			{'1', '2', '3', 'A'},
			{'4', '5', '6', 'B'},
			{'7', '8', '9', 'C'},
			{'*', '0', '#', 'D'}
		};
	private:
		int disabledKey;

	//functions
	public:
		Istream();
		~Istream();
		void update(Keypad& pad);
		void push(const char chr);
		void clear();
	protected:
	private:

	}; //Istream
}
#endif //__ISTREAM_H__
