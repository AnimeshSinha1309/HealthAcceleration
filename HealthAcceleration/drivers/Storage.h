/* 
* Storage.h
*
* Created: 4/13/2016 1:09:09 AM
* Author: Animesh Sinha
*/


#ifndef __STORAGE_H__
#define __STORAGE_H__

#include "Device.h"

namespace atmicro
{
	class Storage : public Device
	{
	//functions
	public:
		virtual ~Storage();
		virtual void Method1()=0;//make Storage not instantiable
		virtual void Method2();
		void Method3();

	}; //Storage
}
#endif //__STORAGE_H__
