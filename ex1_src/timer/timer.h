#ifndef TIMER_H
#define TIMER_H

#include "../main.h"

/* Function Prototypes */
/**
 * @brief Initializes a timer and enables its interrupt. 
 * The ISR is called TimerISR( ).
 * 
 * Time of exectuion: 5ms
 */
void TimerInit(void);

/**
 * @brief Interrupt service routine
 * 
 * It is called every 1 ms once the TimerInit( ) function is executed.
 * 
 * Time of exectuion: - 
 */
void TimerISR(void);

/**
 * @brief Returns the number of us on the Timer since its initialization.
 * 
 * Time of exectuion: - 
 */
uint32_t TimeGetUs(void);

#endif /* TIMER_H */