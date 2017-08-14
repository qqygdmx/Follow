#ifndef __HAL_LED_H 
#define __HAL_LED_H 




void Init_LED(void); 
void Init_TIMER(void);

void Init_PWM(void);
void NVIC_Config_PWM(void);
void TIM8_IRQHandler(void) ;

#endif  

