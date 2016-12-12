/* 
* Pinset.h
*
* Created: 5/15/2016 12:12:49 PM
* Author: Animesh Sinha
*/


#ifndef __PINSET_H__
#define __PINSET_H__

#include "registry.h"
#include <stdarg.h>

namespace atmicro
{
	class Pinset
	{
	//variables
	public:
		short size = 0;
	protected:
		PIN pins[];
	private:

	//functions
	public:
		Pinset(int size, PIN set[]);
		~Pinset();
		unsigned int getData();
		void putData(unsigned int data);
	protected:
	private:
		Pinset( const Pinset &c );
		Pinset& operator=( const Pinset &c );

	}; //Pinset
}

#endif //__PINSET_H__