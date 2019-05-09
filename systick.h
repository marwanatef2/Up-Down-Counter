#ifndef SYSTICK
#define SYSTICK


#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))


// fn that uses systick registers for accurate delay of 1 ms
void systick_delay(void);

// fn that gives delay in required msecs
void delay_milliseconds (unsigned long int msecs);


#endif
