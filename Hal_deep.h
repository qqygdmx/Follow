#ifndef __HAL_DEEP_H 
#define __HAL_DEEP_H 



#define BEEP_H GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define BEEP_L GPIO_ResetBits(GPIOA,GPIO_Pin_4)


void BEEP_Init(void); 
void beepQuiet(void);
void beepSound(unsigned short usFreq);
#endif  



