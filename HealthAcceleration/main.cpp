/*
 * HealthAcceleration.cpp
 *
 * Created: 12/11/2016 10:08:26 PM
 * Author : Animesh Sinha
 */ 

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
#define MAXDRIFT 500
#define DCOUNT 20
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
		com.transmit(0x3e);
	}
}