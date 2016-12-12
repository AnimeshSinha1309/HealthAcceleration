/* 
* EEPROM.h
*
* Created: 5/11/2016 10:11:02 PM
* Author: Animesh Sinha
*/


#ifndef __EEPROM_H__
#define __EEPROM_H__

namespace atmicro {
	class EEPROM
	{
	//functions
	public:
		EEPROM();
		~EEPROM();
		unsigned char read(unsigned int address);
		void write(unsigned int address, unsigned char data);
	protected:
	private:
		EEPROM( const EEPROM &c );
		EEPROM& operator=( const EEPROM &c );

	}; //EEPROM
}

#endif //__EEPROM_H__
