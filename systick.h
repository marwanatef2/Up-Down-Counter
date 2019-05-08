#ifndef SYSTICK
#define SYSTICK


#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))


void systick_delay(void);

void delay_milliseconds (unsigned long int msecs);


#endif