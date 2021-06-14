/*
 * Multi_Timer.c
 */

#include "multi_timer.h"


//timer handle list head.
static Timer_TypeDef* head_handle = NULL;

//Timer ticks
static uint32_t _timer_ticks = 0;

/**
  * @brief  Initializes the timer struct handle.
  * @param  handle: the timer handle strcut.
  * @param  timeout_cb: timeout callback.
  * @param  repeat: repeat interval time.
  * @param  counter: Cycle timing times.
  * @retval None
  */
void timer_init(Timer_TypeDef* handle, void (*timeout_cb)(), uint32_t timeout, uint32_t counter)
{
    // memset(handle, sizeof(struct Timer), 0);
    handle->timeout_cb = timeout_cb;
    handle->repeat     = timeout;
    handle->timeout    = 0;
    handle->counter    = counter;
}

/**
  * @brief  Start the timer work, add the handle into work list.
  * @param  btn: target handle strcut.
  * @retval 0: succeed. -1: already exist.
  */
int timer_start(Timer_TypeDef* handle)
{
	Timer_TypeDef* target = head_handle;
    while(target)
    {
        if(target == handle)
            return -1;  //already exist.
        target = target->next;
    }
    handle->timeout = _timer_ticks + handle->repeat;  //start ticks++
    handle->next 	= head_handle;
    head_handle     = handle;
    return 0;
}

/**
  * @brief  Stop the timer work, remove the handle off work list.
  * @param  handle: target handle strcut.
  * @retval None
  */
void timer_stop(Timer_TypeDef* handle)
{
	Timer_TypeDef** curr;
    for(curr = &head_handle; *curr;)
    {
    	Timer_TypeDef* entry = *curr;
        if(entry == handle)
        {
            *curr = entry->next;
            //			free(entry);
        }
        else
            curr = &entry->next;
    }
}

/**
  * @brief  main loop.
  * @param  None.
  * @retval None
  */
void timer_loop(void)
{
	Timer_TypeDef* target;
    for(target = head_handle; target; target = target->next)
    {
        if(_timer_ticks >= target->timeout)
        {
        	if(target->counter == Timer_Loop)
        	{
        		target->timeout = _timer_ticks + target->repeat;
        	}
        	else
        	{
        		target->counter = target->counter - 1;

				if(target->counter == 0)
				{
					timer_stop(target);
				}
				else
				{
					target->timeout = _timer_ticks + target->repeat;
				}
        	}
        	target->timeout_cb();
        }
    }
}

void timer_init_start(Timer_TypeDef* handle, void (*timeout_cb)(), uint32_t timeout, uint32_t counter)
{
    // memset(handle, sizeof(struct Timer), 0);
    handle->timeout_cb = timeout_cb;
    handle->repeat     = timeout;
    handle->timeout    = 0;
    handle->counter    = counter;

    timer_start(handle);
}
/**
  * @brief  background ticks, timer repeat invoking interval 1ms.
  * @param  None.
  * @retval None.
  */
void timer_ticks(void)
{
    _timer_ticks++;
}

