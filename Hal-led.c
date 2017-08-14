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
/*复用模式	
	GPIO_Mode_AF_PP  复用功能的推挽输出---片内外设功能（I2C的SCL SDA)
	GPIO_Mode_AF_OD  复用功能的开漏输出---片内外设功能（*/
	
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          
		GPIO_Init(GPIOC, &GPIO_InitStructure);                          
}                                                 






void Init_TIMER(void)
{
    
		TIM_TimeBaseInitTypeDef     TIM_BaseInitStructure;   //定义一个定时器结构变量        
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE); //使能定时器8
		TIM_BaseInitStructure.TIM_Period =  999;

		TIM_BaseInitStructure.TIM_Prescaler = 99;  //自定义预分频系数为0，即定时器的时钟频率为72M提供给定时器的时钟  0~65535之间
																																													 
		TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //时钟分割为0
		TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式 从0开始向上计数 ，计数到1000后产生更新事件
																												
		TIM_TimeBaseInit(TIM8, &TIM_BaseInitStructure);    //根据指定参数初始化TIM时间基数寄存器      

		TIM_ARRPreloadConfig(TIM8, ENABLE);    //使能TIMX在ARR上的预装载寄存器  

		TIM_Cmd(TIM8, ENABLE);     //TIM8总开关：开启    

		TIM_ITConfig(TIM8,TIM_IT_Update,ENABLE); //使能定时器中断

		//NVIC_Config_PWM();   
    
}



void Init_PWM(void)
{
		u32 CCR3_Val; 
    TIM_OCInitTypeDef  TIM_OCInitStructure;  //定义一个通道输出结构            

    TIM_OCStructInit(&TIM_OCInitStructure);  //设置缺省值              
    
    TIM_OCInitStructure.TIM_Pulse = CCR3_Val;     //设置占空比，占空比=（CCRx/ARR)*100%或（TIM_Pulse/TIM_Period)*100%    
																						//PWM的输出频率为Fpwm=72M/7200=1Mhz;
	/*下面五句话就把PWM基本配置完成，再加上上面定时器的使能，TIM_Cmd(TIM4,ENABLE)  */
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//PWM模式1输出
    
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //使能输出状态，需要PWM输出才需要这行代码  
        
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  //TIM输出比较极性高，就是开始计数到ccr之前都是high ,因为这里的Led是正逻辑点亮 
                                                                                                                                
		TIM_OC3Init(TIM8, &TIM_OCInitStructure);   //根据参数初始化PWM寄存器，使能通道CCR3            

    TIM_OC3PreloadConfig(TIM8,TIM_OCPreload_Enable);   //使能TIMx在CCR3上的预装载寄存器，很关键和容易遗漏的一步        

    TIM_CtrlPWMOutputs(TIM8,ENABLE);     //设置TIM8的PWM输出为使能                 
/*  这一步只有TIM1和TIM8高级定时器使用 */
}


