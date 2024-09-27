#ifndef __LED_H_
#define __LED_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


#ifndef NULL
#define NULL ((void*)0)
#endif

#if  defined(STM32F40_41xxx)

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
typedef    GPIO_TypeDef*  LED_GPIO_Port_t;

#else

    #error led.h: No processor defined!
#endif

typedef struct led_t{
    LED_GPIO_Port_t port;  //所使用的端口
    uint32_t pin;          //所使用的引脚
    uint8_t led_on_level;  //led亮的时候  IO的电平状态
    bool status;           //status == true  led亮
    bool init;             //初始化标志 
  
}LED_t;

typedef struct LED_CLASS{
   LED_t led_info;

  struct LED_CLASS* ledclass;
  int (*LED_InitCall)(struct LED_CLASS *led,int count);
  int (*LED_OnCall)( struct LED_CLASS *led);
  int (*LED_OffCall)(struct LED_CLASS *led);
  int (*LED_SetStatusCall)(struct LED_CLASS *led,bool status);
  int (*LED_RefreshStatusCall)(struct LED_CLASS *led);
  
}LED_Class;

int LED_Init(struct LED_CLASS *led,int count);
int LED_On(struct LED_CLASS *led);
int LED_Off(struct LED_CLASS *led);
int LED_SetStatus(struct LED_CLASS *led,bool status);
int LED_RefreshStatus(struct LED_CLASS *led);
extern LED_Class LED1;
#endif
