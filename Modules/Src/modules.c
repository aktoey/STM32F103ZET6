/*
 * Modules.c
 */

#include "modules.h"

struct Button btn1;
struct Button btn2;

pFun pfSYSTICK_ISR[ALL_IDXS];
pFun pfISR[ALL_ISRS];

void timer1_callback(void);
void timer2_callback(void);
void BTN1_PRESS_DOWN_Handler(void* btn);
void BTN2_PRESS_DOWN_Handler(void* btn);

void Hal_Regist_ISR(ISR_TYPE isr, SYSTICK_ISR_IDX index, pFun pf)
{
    if(pf == NULL) return;

    if(isr ==  SYSTICK_ISR && index < ALL_IDXS)
    {
    	pfSYSTICK_ISR[index] = pf;
    }
    else if(isr !=  SYSTICK_ISR && isr < ALL_ISRS)
    {
        pfISR[isr] = pf;
    }
}

void SysTick_Handler_Callback(void)
{
	for(uint8_t i = 0; i < ALL_IDXS; i++)
	{
		if(pfSYSTICK_ISR[i] != NULL)
			(*pfSYSTICK_ISR[i])();
	}
}

void Multi_Timer_Init(void)
{
	Hal_Regist_ISR(SYSTICK_ISR,MULTITIMER_ISR_IDX,timer_ticks);

	timer_init(&Multi_Timer[DELAY5S_TIMER_IDX], timer1_callback, 5000, 1); //1s loop
	timer_init(&Multi_Timer[LOOP500MS_TIMER_IDX], timer2_callback, 500, Timer_Loop); //50ms delay

	timer_start(&Multi_Timer[DELAY5S_TIMER_IDX]);
	timer_start(&Multi_Timer[LOOP500MS_TIMER_IDX]);
}

uint8_t read_button1_GPIO()
{
	return HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin);
}

uint8_t read_button2_GPIO()
{
	return HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
}

void Multi_Button_Init(void)
{
	Hal_Regist_ISR(SYSTICK_ISR,MULTIBUTTON_ISR_IDX,button_ticks);
	button_init(&btn1, read_button1_GPIO, 0);
	button_init(&btn2, read_button2_GPIO, 0);

	button_attach(&btn1, PRESS_DOWN,       BTN1_PRESS_DOWN_Handler);

	/*
	button_attach(&btn1, PRESS_UP,         BTN1_PRESS_UP_Handler);
	button_attach(&btn1, PRESS_REPEAT,     BTN1_PRESS_REPEAT_Handler);
	button_attach(&btn1, SINGLE_CLICK,     BTN1_SINGLE_Click_Handler);
	button_attach(&btn1, DOUBLE_CLICK,     BTN1_DOUBLE_Click_Handler);
	button_attach(&btn1, LONG_PRESS_START, BTN1_LONG_PRESS_START_Handler);
	button_attach(&btn1, LONG_PRESS_HOLD,  BTN1_LONG_PRESS_HOLD_Handler);
	*/

	button_attach(&btn2, PRESS_DOWN,       BTN2_PRESS_DOWN_Handler);

	/*
	button_attach(&btn2, PRESS_UP,         BTN2_PRESS_UP_Handler);
	button_attach(&btn2, PRESS_REPEAT,     BTN2_PRESS_REPEAT_Handler);
	button_attach(&btn2, SINGLE_CLICK,     BTN2_SINGLE_Click_Handler);
	button_attach(&btn2, DOUBLE_CLICK,     BTN2_DOUBLE_Click_Handler);
	button_attach(&btn2, LONG_PRESS_START, BTN2_LONG_PRESS_START_Handler);
	button_attach(&btn2, LONG_PRESS_HOLD,  BTN2_LONG_PRESS_HOLD_Handler);
	*/

	button_start(&btn1);
	button_start(&btn2);
}

void timer1_callback(void)
{
	HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
	printf("timer1\r\n");
}

void timer2_callback(void)
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	printf("timer2\r\n");
}

void BTN1_PRESS_DOWN_Handler(void* btn)
{
	printf("BTN1_PRESS_DOWN\r\n");
}

void BTN2_PRESS_DOWN_Handler(void* btn)
{
	printf("BTN2_PRESS_DOWN_Handler\r\n");
}

