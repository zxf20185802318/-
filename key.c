#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

void KEY_Init(void) 
{ 
 	GPIO_InitTypeDef GPIO_Initzzz;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

	GPIO_Initzzz.GPIO_Pin  =GPIO_Pin_3|GPIO_Pin_4;
	GPIO_Initzzz.GPIO_Mode = GPIO_Mode_IPU; 
 	GPIO_Init(GPIOE, &GPIO_Initzzz);

	GPIO_Initzzz.GPIO_Pin  = GPIO_Pin_0;
	GPIO_Initzzz.GPIO_Mode = GPIO_Mode_IPD;   
	GPIO_Init(GPIOA, &GPIO_Initzzz);

}

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;
if(mode) key_up=1;  
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10);
		key_up=0;
		if(KEY0==0)
			return KEY0_PRES;
		else if(KEY1==0)
			return KEY1_PRES;
		else if(WK_UP==1)
			return WKUP_PRES;
	}
	else if
		(KEY0==1&&KEY1==1&&WK_UP==0)
	key_up=1; 	    
 	return 0;
}
