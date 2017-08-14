/**
  ******************************************************************************
  * @file    main.c 
  * @author  Alan
  * @version V1.0
  * @date    2017-03-14
  * @brief   
  */ 
#include "stm32f10x_it.h"
#include "Hal_led.h" 
#include "Hal_Delay.h"

uint16_t led_fx=1;  
uint16_t led_dt=0;


int main(void)  
{  
		Init_LED();  
		Init_TIMER();  
		Init_PWM();  
		Delay_Init();
		GPIO_SetBits(GPIOC,GPIO_Pin_8);  
		GPIO_ResetBits(GPIOC,GPIO_Pin_8); 
		while(1) 
		{  
				DelayMs(1);  
				led_dt	+=1;
				led_dt	=	led_dt%999;
				TIM_SetCompare3(TIM8,led_dt);  
		}     
}  
/**
  ******************************************************************************
  2017/7/27
	调试过程中LED灯一直没有完成LED的
  */ 
  
