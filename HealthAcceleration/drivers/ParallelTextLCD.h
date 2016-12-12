/* 
* ParallelTextLCD.h
*
* Created: 4/12/2016 1:05:34 AM
* Author: Animesh Sinha
*/


#ifndef __TEXTLCD_H__
#define __TEXTLCD_H__

#include "Output.h"


namespace atmicro
{
	class ParallelTextLCD : public Output
	{
	//variables
	protected:
		PORT dataPort;
		PIN pinEN, pinRW, pinRS;
		int rowPositions[4] = {0, 64, 20, 84};

	//functions
	public:
		ParallelTextLCD(PORT portData, PIN pinRS, PIN pinRW, PIN pinEN);
		~ParallelTextLCD();
		void initialize();
		void integer(int x, int y, int num);
		void integer(int num);
		void string(int x, int y, const char* str);
		void string(const char* str);
		void position(int x, int y);
		void clear();
		void cursor(bool visible, bool blink);
		void character(unsigned char chr);
		void character(int x, int y, unsigned char chr);
		void command(unsigned char cmd);
	protected:
		void wait_busy(void);
		void action_enable(void);
	private:
		ParallelTextLCD( const ParallelTextLCD &c );
		ParallelTextLCD& operator=( const ParallelTextLCD &c );
	}; //TextLCD
}

#endif //__TEXTLCD_H__