#include "stm32f10x.h"
#include "Hal_led.h" 
#include "misc.h" 

uint8_t indexWave[] = {1,1,2,2,3,4,6,8,10,14,19,25,33,44,59,80,
    107,143,191,255,255,191,143,107,80,59,44,33,25,19,14,10,8,6,4,3,2,2,1,1};
    
    

void Init_LED(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;                 

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC |RCC_APB2Periph_AFIO,ENABLE);    
																												

		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;            
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
/*����ģʽ	
	GPIO_Mode_AF_PP  ���ù��ܵ��������---Ƭ�����蹦�ܣ�I2C��SCL SDA)
	GPIO_Mode_AF_OD  ���ù��ܵĿ�©���---Ƭ�����蹦�ܣ�*/
	
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          
		GPIO_Init(GPIOC, &GPIO_InitStructure);                          
}                                                 






void Init_TIMER(void)
{
    
		TIM_TimeBaseInitTypeDef     TIM_BaseInitStructure;   //����һ����ʱ���ṹ����        
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE); //ʹ�ܶ�ʱ��8
		TIM_BaseInitStructure.TIM_Period =  999;

		TIM_BaseInitStructure.TIM_Prescaler = 99;  //�Զ���Ԥ��Ƶϵ��Ϊ0������ʱ����ʱ��Ƶ��Ϊ72M�ṩ����ʱ����ʱ��  0~65535֮��
																																													 
		TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ʱ�ӷָ�Ϊ0
		TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ ��0��ʼ���ϼ��� ��������1000����������¼�
																												
		TIM_TimeBaseInit(TIM8, &TIM_BaseInitStructure);    //����ָ��������ʼ��TIMʱ������Ĵ���      

		TIM_ARRPreloadConfig(TIM8, ENABLE);    //ʹ��TIMX��ARR�ϵ�Ԥװ�ؼĴ���  

		TIM_Cmd(TIM8, ENABLE);     //TIM8�ܿ��أ�����    

		TIM_ITConfig(TIM8,TIM_IT_Update,ENABLE); //ʹ�ܶ�ʱ���ж�

		//NVIC_Config_PWM();   
    
}



void Init_PWM(void)
{
		u32 CCR3_Val; 
    TIM_OCInitTypeDef  TIM_OCInitStructure;  //����һ��ͨ������ṹ            

    TIM_OCStructInit(&TIM_OCInitStructure);  //����ȱʡֵ              
    
    TIM_OCInitStructure.TIM_Pulse = CCR3_Val;     //����ռ�ձȣ�ռ�ձ�=��CCRx/ARR)*100%��TIM_Pulse/TIM_Period)*100%    
																						//PWM�����Ƶ��ΪFpwm=72M/7200=1Mhz;
	/*������仰�Ͱ�PWM����������ɣ��ټ������涨ʱ����ʹ�ܣ�TIM_Cmd(TIM4,ENABLE)  */
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//PWMģʽ1���
    
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //ʹ�����״̬����ҪPWM�������Ҫ���д���  
        
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  //TIM����Ƚϼ��Ըߣ����ǿ�ʼ������ccr֮ǰ����high ,��Ϊ�����Led�����߼����� 
                                                                                                                                
		TIM_OC3Init(TIM8, &TIM_OCInitStructure);   //���ݲ�����ʼ��PWM�Ĵ�����ʹ��ͨ��CCR3            

    TIM_OC3PreloadConfig(TIM8,TIM_OCPreload_Enable);   //ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ������ܹؼ���������©��һ��        

    TIM_CtrlPWMOutputs(TIM8,ENABLE);     //����TIM8��PWM���Ϊʹ��                 
/*  ��һ��ֻ��TIM1��TIM8�߼���ʱ��ʹ�� */
}


