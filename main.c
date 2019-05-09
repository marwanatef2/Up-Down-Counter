#include <stdio.h>
#include "systick.h"
#include "portinit.h"

void SystemInit() {}
	

int main()
{
	// start with 7-segments displaying "0"
	GPIO_PORTA_DATA_R &= ~(0x0F << 2);
	GPIO_PORTC_DATA_R &= ~(0x0F << 4);
	
	while (1)
	{
		//check if reset switch is pressed -> reset 7-segments to 0
		if ((GPIO_PORTF_DATA_R&0x10) == 0)
		{
			// wait as long as the switch is not released
			while ((GPIO_PORTF_DATA_R&0x10) != 0x10) ;
			
			//upon release, reset
			GPIO_PORTA_DATA_R &= ~(0x0F << 2);
			GPIO_PORTC_DATA_R &= ~(0x0F << 4);
		}
		
		//increment as long as the switch button is pressed
		while ((GPIO_PORTA_DATA_R&0x40) == 0x40)
		{
			// if 1st 7-segment became "9" reset and increment the next 7-segment 
			if ((GPIO_PORTA_DATA_R&0x3C) == (0x09 <<2))
			{
				GPIO_PORTA_DATA_R &= ~(0x0F << 2);
				GPIO_PORTC_DATA_R += (1<<4);
			}
			//else incerement 
			else {
				GPIO_PORTA_DATA_R += (1<<2);
			}
			
			//delay for 0.2 sec before incrementing once again
			delay_milliseconds(200);
		}
		
		//decrement on switch button press
		if ((GPIO_PORTA_DATA_R&0x80) == 0x80)
		{
			//if 1st 7-segment became "0" decrement the next 7-segment
			if ((GPIO_PORTA_DATA_R&0x3C) == (~0x0F << 2))
			{
				GPIO_PORTC_DATA_R -= (1<<4);
			}
			//else decrement 
			else {
				GPIO_PORTA_DATA_R -= (1<<2);
			}
			
			//wait for the button release 
			while ((GPIO_PORTA_DATA_R&0x80) == 0x80) ;
		}
	}
	
	return 0;
}

