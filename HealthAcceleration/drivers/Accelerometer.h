/* 
* Accelerometer.h
*
* Created: 12/3/2016 2:22:14 PM
* Author: Animesh Sinha
*/


#ifndef __ACCELEROMETER_H__
#define __ACCELEROMETER_H__

#include "AnalogInput.h"

namespace atmicro
{
	class Accelerometer
	{
	//variables
	public:
		short x, y, z;
	protected:
	private:
		ADCchannel adcx, adcy, adcz;
		
	//functions
	public:
		Accelerometer(ADCchannel x, ADCchannel y, ADCchannel z);
		~Accelerometer();
		void update();
	protected:
	private:
		Accelerometer( const Accelerometer &c );
		Accelerometer& operator=( const Accelerometer &c );

	}; //Accelerometer
}

#endif //__ACCELEROMETER_H__
