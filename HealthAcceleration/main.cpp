/*
 * HealthAcceleration.cpp
 *
 * Created: 12/11/2016 10:08:26 PM
 * Author : Animesh Sinha
 */ 

#define BOARDLOCAL

#ifdef BOARDLOCAL

	#include <avr/io.h>
	#include "atmicro.h"
	
	int main()
	{
		ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
		USART com(9600);
		DigitalOutput buzzer(IOPINC0);
		int i = 0;
		while(1)
		{
			if(com.receive() == 0x05)
			{
				lcd.string(0, 0, "Emergency Alert!");
				if(i > 10) buzzer.toggle();
				i++;
			}
			else if(com.receive() == 0xA0)
			{
				lcd.string(0, 0, "Totally Safe.   ");
				buzzer.off();
			}
			else
			{
				lcd.string(0, 0, "It all looks OK.");
				buzzer.off();
			}
			_delay_ms(100);
		}
	}

#endif

#ifdef BOARDHUMAN

#include <avr/io.h>
#include "atmicro.h"

AnalogInput x(ADC2);
AnalogInput y(ADC1);
AnalogInput z(ADC0);
DigitalOutput led(IOPIND4);
PushButtonSwitch sw(IOPINC0);
USART com(9600);

void handler(int value, ADCchannel pin);
#define xm 500
#define ym 600
#define zm 600
#define MAXDRIFT 400
#define DCOUNT 5
#define SCOUNT 50

int dangerlevel = 0, safetylevel = 0;
bool fallen = false;

int main(void)
{
	x.setCallback(handler);
	y.setCallback(handler);
	z.setCallback(handler);
	x.startConversion();
	while (1)
	{
		if (fallen)
		{
			com.transmit(0x05);
		}
		else
		{
			com.transmit(0xA0);
		}
	}
}

ISR(ADC_vect)
{
	_delay_ms(10);
	if(x.isLive())
	{
		x.process();
		y.startConversion();
	}
	if(y.isLive())
	{
		y.process();
		z.startConversion();
	}
	if(z.isLive())
	{
		z.process();
		x.startConversion();
	}
}

void handler(int value, ADCchannel pin)
{
	int a = sqrt(pow(x.value-xm, 2)+pow(y.value-ym,2)+pow(z.value-zm,2));
	if(fabs(a) > MAXDRIFT && fabs(a) < 10000)
	{
		dangerlevel++;
		safetylevel = 0;
	}
	else if (safetylevel > SCOUNT)
	{
		dangerlevel = 0;
		safetylevel = 0;
	}
	else
	{
		safetylevel++;
	}

	if(sw.isPressed())
	{
		fallen = false;
		led.off();
	}
	if (dangerlevel > DCOUNT)
	{
		led.on();
		fallen = true;
	}
}
#endif