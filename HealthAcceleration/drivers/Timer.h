/* 
* Timer.h
*
* Created: 4/13/2016 1:08:10 AM
* Author: Animesh Sinha
*/


#ifndef __TIMER_H__
#define __TIMER_H__

#include "Device.h"

namespace atmicro 
{
	class Timer : public Device
	{
	//functions
	public:
		virtual ~Timer();
		virtual void Method1()=0;//make Timer not instantiable
		virtual void Method2();
		void Method3();

	}; //Timer
}

#endif //__TIMER_H__
