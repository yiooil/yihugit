#ifndef _DELAY_H_
#define _DELAY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#if defined(STM32F40_41xxx)

#include "misc.h"
#else 
    #error delay.h: No processor defined!
#endif

void Delay_Init(uint8_t SYSCLK);
void Delay_ms(uint32_t ms);
void Delay_us(uint32_t us);



#endif

