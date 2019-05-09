#include "portinit.h"


#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))

#define GPIO_PORTC_DATA_R       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_R      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_DEN_R        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_R       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_R         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_R      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile unsigned long *)0x4000652C))
	
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))	
	
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))	


//use port A pins 2,3,4,5 as general purpose digital output for 1st 7-segment decoder
//and pins 6 & 7 as digital input for 2 switches
void PortA_init (void)
{
	SYSCTL_RCGCGPIO_R |= 0x01;
	GPIO_PORTA_DIR_R |= 0x3C ;
	GPIO_PORTA_AFSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_AMSEL_R =0;
	GPIO_PORTA_DEN_R |= 0xFC;
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xFC;
}

//use port C pins 4,5,6,7 as general purpose digital output for 2nd 7-segment decoder
void PortC_init (void)
{
	SYSCTL_RCGCGPIO_R |= 0x04;
	GPIO_PORTC_DIR_R |= 0xF0;
	GPIO_PORTC_AFSEL_R = 0;
	GPIO_PORTC_PCTL_R = 0;
	GPIO_PORTC_AMSEL_R =0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R |= 0xF0;
}

//use port F 4 "SW 1" as a digital input for the 3rd switch
void PortF_init (void)
{
	SYSCTL_RCGCGPIO_R |= 0x20;
	GPIO_PORTF_DIR_R &= ~0x10;
	GPIO_PORTF_AFSEL_R = 0;
	GPIO_PORTF_PCTL_R = 0;
	GPIO_PORTF_AMSEL_R =0;
	GPIO_PORTF_DEN_R |= 0x10;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x10;
	GPIO_PORTF_PUR_R |= 0x10;
}

