#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined (STM32F40_41xxx)

#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#define EN_USART1_RX

#else

#error debug.h: No processor defined!

#endif
int DEBUG_Init(uint32_t baud_rate);

#endif


