#include "portinit.h"


void PortA_init (void)
{
	int x;
	SYSCTL_RCGCGPIO_R |= 0x01;
	x=0; // for delay purposes
	GPIO_PORTA_DIR_R |= 0x3C ;
	GPIO_PORTA_AFSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_AMSEL_R =0;
	GPIO_PORTA_DEN_R |= 0xFC;
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xFC;
}


void PortD_init (void)
{
	int x;
	SYSCTL_RCGCGPIO_R |= 0x08;
	x=0; // for delay purposes
	GPIO_PORTD_DIR_R |= 0x0F;
	GPIO_PORTD_AFSEL_R = 0;
	GPIO_PORTD_PCTL_R = 0;
	GPIO_PORTD_AMSEL_R =0;
	GPIO_PORTD_DEN_R |= 0x0F;
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= 0x0F;
}


void PortF_init (void)
{
	int x;
	SYSCTL_RCGCGPIO_R |= 0x20;
	x=0; // for delay purposes
	GPIO_PORTF_DIR_R = 0x02;
	GPIO_PORTF_AFSEL_R = 0;
	GPIO_PORTF_PCTL_R = 0;
	GPIO_PORTF_AMSEL_R =0;
	GPIO_PORTF_DEN_R |= 0x12;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x12;
	GPIO_PORTF_PUR_R |= 0x10;
}
