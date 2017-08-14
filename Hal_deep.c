

#include "stm32f10x.h"
#include "Hal_deep.h" 



void BEEP_Init(void) 
{ 

	GPIO_InitTypeDef GPIO_InitStructure; 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	BEEP_L;
}
void beepQuiet(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure; 
	//TIM_Cmd(TIM3, DISABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_4); 
}

void beepSound(unsigned short usFreq) 
{ 
	GPIO_InitTypeDef GPIO_InitStructure; 
	unsigned long ulVal; 

	if((usFreq<=8000000/65536UL)||(usFreq>20000)) 
	{ 
		beepQuiet();
	} 

	else 
	{
		//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; //TIM_CH2 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//ulVal=8000000/usFreq;  
		//TIM3->ARR =ulVal;  
		//TIM_SetCompare2(TIM3,ulVal /2);
		//TIM_Cmd(TIM3, ENABLE); 
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
	}
}
