/*
 * HealthAcceleration.cpp
 *
 * Created: 12/11/2016 10:08:26 PM
 * Author : Animesh Sinha
 */ 

#include <avr/io.h>
#include "atmicro.h"

AnalogInput x(ADC0);
AnalogInput y(ADC1);
AnalogInput z(ADC2);
ParallelTextLCD lcd(IOPORTB, IOPIND2, IOPIND7, IOPIND5);
void handler(int value, ADCchannel pin);
#define xm 600
#define ym 600
#define zm 600
#define DRIFT 300
int dangerlevel = 0, safetylevel = 0;


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
	if(pin == ADC0)
	{
		lcd.integer(0, 0, value);
		lcd.string(" ");
	}
	else if(pin == ADC1)
	{
		lcd.integer(5, 0, value);
		lcd.string(" ");
	}
	else if(pin == ADC2)
	{
		lcd.integer(10, 0, value);
		lcd.string(" ");
	}
	
	int a = sqrt(pow(x.value-xm, 2)+pow(y.value-ym,2)+pow(z.value-zm,2));
	if(fabs(a) > DRIFT)
	{
		dangerlevel++;
		safetylevel = 0;
	}
	else if (safetylevel > 50)
	{
		dangerlevel = 0;
	}
	else
	{
		safetylevel++;
	}
	lcd.integer(0, 1, dangerlevel);
	lcd.string("  ");
	lcd.integer(10, 1, a);
	lcd.string("  ");
}
