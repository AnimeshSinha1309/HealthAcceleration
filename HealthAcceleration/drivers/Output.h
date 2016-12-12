/* 
* Output.h
*
* Created: 4/11/2016 9:06:43 PM
* Author: Animesh Sinha
*/


#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "Device.h"

namespace atmicro
{
	class Output : public Device
	{
	//functions
	public:
		virtual void initialize()=0;//make Output not instantiable
	}; //Output
}

#endif //__OUTPUT_H__