/*
 * Multi_Timer.h
 */

#ifndef _MULTI_TIMER_H_
#define _MULTI_TIMER_H_

#include "stdint.h"
#include "stddef.h"

#ifndef Timer_Loop
#define Timer_Loop 0xFFFFFFFF
#endif

typedef struct Timer{
    uint32_t timeout;
    uint32_t repeat;
    uint32_t counter;
    void (*timeout_cb)(void);
    struct Timer* next;
}Timer_TypeDef;

typedef enum enum_MULTITIMER_IDX
{
	START_TIMER_IDX = 0,
	DELAY5S_TIMER_IDX = START_TIMER_IDX,
	LOOP500MS_TIMER_IDX,
	END_TIMER_IDX = LOOP500MS_TIMER_IDX,
    ALL_TIMER
}MULTITIMER_IDX;

Timer_TypeDef Multi_Timer[ALL_TIMER];

#ifdef __cplusplus  
extern "C" {  
#endif  

void timer_init_start(Timer_TypeDef* handle, void (*timeout_cb)(), uint32_t timeout, uint32_t counter);
void timer_init(Timer_TypeDef* handle, void(*timeout_cb)(), uint32_t timeout, uint32_t repeat);
int  timer_start(Timer_TypeDef* handle);
void timer_stop(Timer_TypeDef* handle);
void timer_ticks(void);
void timer_loop(void);

#ifdef __cplusplus
} 
#endif

#endif
