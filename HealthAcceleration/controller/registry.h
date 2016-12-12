/*
 * registry.h
 *
 * Created: 4/15/2016 12:57:09 AM
 *  Author: Animesh Sinha
 */ 


#ifndef REGISTRY_H_
#define REGISTRY_H_

// Pin Configuration setup

namespace atmicro
{
	#define HIGH true
	#define LOW false
	
	#define DDR_OUTPUT true
	#define DDR_INPUT false 

	enum PORT {
		IOPORTA = 0, IOPORTB = 8, IOPORTC = 16, IOPORTD = 24
	};
	enum PIN {
		IOPINA0 =  0, IOPINA1 =  1, IOPINA2 =  2, IOPINA3 =  3,
		IOPINA4 =  4, IOPINA5 =  5, IOPINA6 =  6, IOPINA7 =  7,
		IOPINB0 =  8, IOPINB1 =  9, IOPINB2 = 10, IOPINB3 = 11,
		IOPINB4 = 12, IOPINB5 = 13, IOPINB6 = 14, IOPINB7 = 15,
		IOPINC0 = 16, IOPINC1 = 17, IOPINC2 = 18, IOPINC3 = 19,
		IOPINC4 = 20, IOPINC5 = 21, IOPINC6 = 22, IOPINC7 = 23,
		IOPIND0 = 24, IOPIND1 = 25, IOPIND2 = 26, IOPIND3 = 27,
		IOPIND4 = 28, IOPIND5 = 29, IOPIND6 = 30, IOPIND7 = 31
	};
	enum POSITION {
		IOPIN0 = 0, IOPIN1 = 1, IOPIN2 = 2, IOPIN3 = 3,
		IOPIN4 = 4, IOPIN5 = 5, IOPIN6 = 6, IOPIN7 = 7
	};

	enum ADCchannel {
		ADC0 = 0, ADC1 = 1, ADC2 = 2, ADC3 = 3,
		ADC4 = 4, ADC5 = 5, ADC6 = 6, ADC7 = 7
	};
}

#endif /* REGISTRY_H_ */