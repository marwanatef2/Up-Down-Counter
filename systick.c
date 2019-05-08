#include "systick.h"

// delay for 1 ms
void systick_delay(void)
{
	// systick initialization
	NVIC_ST_CTRL_R = 0 ;
	NVIC_ST_RELOAD_R = 80000;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= 0x05;
	
	// wait as long as the count flag is not asserted 
	while ((NVIC_ST_CTRL_R&0x10000) == 0) ;
}

// delay for given time (in ms)
void delay_milliseconds (unsigned long int msecs)
{
	//repeat the delay 1 ms for msecs times
	while (msecs--)
		systick_delay();
}

