#ifndef _NVIC_H
#define _NVIC_H


#if defined (STM32F40_41xxx)
#include "misc.h"


#else

#error nvic.h: No processor defined!

#endif
int NVICGROUP_Init(void);

#endif /*_NVIC_H*/
