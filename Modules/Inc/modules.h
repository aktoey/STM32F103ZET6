/*
 * Modules.h
 */

#ifndef _MODULES_H_
#define _MODULES_H_

#include <stdio.h>
#include "multi_timer.h"
#include "multi_button.h"
#include "gpio.h"

typedef void (*pFun)(void);

/***************************************************************************//**
* @ enum define,为各个功能模块需要在SysTick_Handler里注册函数提供索引
******************************************************************************/
typedef enum enum_SYSTICK_ISR_IDX
{
	START_ISR_IDX = 0,
	MULTITIMER_ISR_IDX = START_ISR_IDX,
	MULTIBUTTON_ISR_IDX,
	END_ISR_IDX = MULTIBUTTON_ISR_IDX,
    ALL_IDXS
}SYSTICK_ISR_IDX;

typedef enum enum_ISR_TYPE
{
	START_ISR = 0,
	SYSTICK_ISR = START_ISR,
	UART0_TX_ISR,
	UART0_RX_ISR,
	UART1_TX_ISR,
	UART1_RX_ISR,
	END_ISR = UART1_RX_ISR,
	ALL_ISRS
}ISR_TYPE;

void Hal_Regist_ISR(ISR_TYPE isr, SYSTICK_ISR_IDX index, pFun pf);
void SysTick_Handler_Callback(void);
void Multi_Timer_Init(void);
void Multi_Button_Init(void);
#endif

