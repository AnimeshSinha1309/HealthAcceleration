/* 
* PushButtonSwitch.h
*
* Created: 4/16/2016 10:02:02 AM
* Author: Manish Sinha
*/


#ifndef __PUSHBUTTONSWITCH_H__
#define __PUSHBUTTONSWITCH_H__

#include "Input.h"

namespace atmicro
{
	class PushButtonSwitch : public Input
	{
	//variables
	protected:
		PIN pin;
		bool pullState;
		bool status;

	//functions
	public:
		PushButtonSwitch(PIN pin, bool pullState = HIGH);
		~PushButtonSwitch();
		void initialize();
		bool isPressed(); //debounced status
		bool undebouncedStatus(); //state without debouncing
	protected:
	private:
		PushButtonSwitch( const PushButtonSwitch &c );
		PushButtonSwitch& operator=( const PushButtonSwitch &c );
	
	}; //PushButtonSwitch
}

#endif //__PUSHBUTTONSWITCH_H__