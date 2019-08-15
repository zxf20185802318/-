#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
 #include "usart.h"


int main(void)
{
	vu8 key=0;
	u16 a,b,i,j;
  a=5200;
  b=4800;	
	LED_Init();
  delay_init();
	KEY_Init();
	LED0=1;
	LED1=1;
	while(1)
	{
		key=KEY_Scan(0);
		if(key==KEY0_PRES)
			while(1)
		{
			 LED0=1;
		LED1=0;
		delay_ms(300);	
		LED0=0;
		LED1=1;
		delay_ms(300);
		}
  	else if(key==KEY1_PRES)
		{
	    for(j=0;j<1000;j++)
			{
				for(i=0;i<=a;i++)
				{
					LED0=0;
					delay (i);
					LED0=1;
					delay(a-i);
				}
				for(i=0;i<b;i++)
				{
					 LED0=0;
					 delay(b-i);
					 LED0=1;
					 delay(i);
				 }
		   }
		}
		else delay_ms(20);
	}

}
