#include "nvic.h"



int NVICGROUP_Init(void)
{
  #if defined (STM32F40_41xxx)
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    return 0;
  #endif
}

