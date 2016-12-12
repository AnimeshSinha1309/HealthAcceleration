/* 
* USART.h
*
* Created: 6/19/2016 5:57:49 PM
* Author: Manish Sinha
*/


#ifndef __USART_H__
#define __USART_H__

#include "Communication.h"

namespace atmicro
{
	class USART : public Communication
	{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		USART(unsigned int baud);
		~USART();
		void initialize();
		void transmit(unsigned char data);
		void transmit(const char* data);
		unsigned char receive(void);
	protected:
	private:
		USART( const USART &c );
		USART& operator=( const USART &c );

	}; //USART
}

#endif //__USART_H__