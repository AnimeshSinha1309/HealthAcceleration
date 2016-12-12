/* 
* DigitalOutput.h
*
* Created: 4/10/2016 12:32:17 PM
* Author: Manish Sinha
*/


#ifndef __LED_H__
#define __LED_H__

#include "Output.h"

namespace atmicro
{
	class DigitalOutput : public Output
	{
	//variables
	protected:
		bool status; 
		PIN pin;

	//functions
	public:
		DigitalOutput(PIN pin);
		~DigitalOutput();
		void on(); // Switches the DigitalOutput on
		void off(); // Switches the DigitalOutput off
		bool toggle(); // Changes the state of DigitalOutput from on to off or back
		void initialize(); // Initializes the DigitalOutput port
	}; //DigitalOutput
}

#endif //__LED_H__