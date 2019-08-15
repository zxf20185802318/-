#ifndef _led_h
#define _led_h
#include "sys.h"

#define LED0 PBout(5)
#define LED1 PEout(5)

void LED_Init(void);

#endif 
