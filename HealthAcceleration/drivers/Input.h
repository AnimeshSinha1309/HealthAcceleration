/* 
* Input.h
*
* Created: 4/13/2016 1:07:43 AM
* Author: Animesh Sinha
*/


#ifndef __INPUT_H__
#define __INPUT_H__

#include "Device.h"

namespace atmicro
{
	class Input : public Device
	{
	//functions
	public:
		virtual void initialize()=0;//make Output not instantiable
	}; //Input
}

#endif //__INPUT_H__