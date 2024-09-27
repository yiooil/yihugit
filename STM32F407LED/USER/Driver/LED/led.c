#include "led.h"

// 高电平亮 低电平灭

#if defined (STM32F40_41xxx)

#include "stm32f4xx_gpio.h"
#define __LED_CONFIG_IO_OUTPUT(port, pin)  {GPIO_InitTypeDef GPIO_InitStructure; \
            GPIO_InitStructure.GPIO_Pin = pin; \
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
            GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; \
            GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; \
            GPIO_Init(port, &GPIO_InitStructure);}

#define __LED_IO_SET(port, pin, value)  {   if(1==value)  \
                                              GPIO_SetBits(port, pin);  \
                                            else        \
                                              GPIO_ResetBits(port, pin);  \
                                        }


#endif

/******************************************************************************
 * @brief     初始化LED   //LED_Init(&gled,GPIOC, GPIO_Pin_13);
 *
 * @param[in]  led   :  led结构体指针
 * @param[in]  port  :  引脚端口
 * @param[in]  pin   :  引脚
 *
 * @return     0, 表示初始化成功, 其他值表示失败
 *
 ******************************************************************************/

int LED_Init(struct LED_CLASS *led,int count)
{
  int i = 0;
    if(!led)
        return -1;

    //配置引脚 默认输出
  for(i = 0; i < count;i++) {
#if defined (STM32F40_41xxx)
    assert_param(IS_GPIO_ALL_PERIPH((led+i)->led_info.port));
    if (led->led_info.port  == GPIOA)       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  
    else if (led->led_info.port  == GPIOB)  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 
    else if (led->led_info.port  == GPIOC)  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 
    else if (led->led_info.port  == GPIOD)  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 
    else if (led->led_info.port  == GPIOE)  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 
    else if (led->led_info.port  == GPIOF)  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); 
    else if (led->led_info.port  == GPIOG)  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE); 
    else printf("LED_Init port no\r\n");    

#endif
    __LED_IO_SET((led+i)->led_info.port, (led+i)->led_info.pin, !((led+i)->led_info.led_on_level));
    __LED_CONFIG_IO_OUTPUT((led+i)->led_info.port, (led+i)->led_info.pin);
    (led+i)->led_info.init = true;
    (led+i)->led_info.status = false;

  }

  return 0;
}


/******************************************************************************
 * @brief      打开led
 *
 * @param[in]  led   :  led结构体指针
 *
 * @return     0, 表示正常, 其他值表示失败
 *
 ******************************************************************************/
int LED_On(struct LED_CLASS *led)
{
    if(!led || !led->led_info.init)
        return -1;

    __LED_IO_SET(led->led_info.port, led->led_info.pin, led->led_info.led_on_level);
    led->led_info.status = true;
    return 0;
}

/******************************************************************************
 * @brief      关闭led
 *
 * @param[in]  led   :  led结构体指针
 *
 * @return     0, 表示正常, 其他值表示失败
 *
 ******************************************************************************/

int LED_Off(struct LED_CLASS *led)
{
    if(!led || !led->led_info.init)
        return -1;

    __LED_IO_SET(led->led_info.port, led->led_info.pin, !led->led_info.led_on_level);
    led->led_info.status = false;
   return 0;

}
/******************************************************************************
 * @brief      设置led状态
 *
 * @param[in]  led   :  led结构体指针
 * @param[in]  status:  led开关状态
 *
 * @return     0, 表示正常, 其他值表示失败
 *
 ******************************************************************************/


int LED_SetStatus(struct LED_CLASS *led,bool status)
{

    if (!led || !led->led_info.init)
        return -1;  //初始化引脚之后
    
    led->led_info.status = status;

    return 0;

}
/******************************************************************************
 * @brief      刷新led状态
 *
 * @param[in]  led   :  led结构体指针
 *
 * @return     0, 表示正常, 其他值表示失败
 *
 ******************************************************************************/

int LED_RefreshStatus(struct LED_CLASS *led)
{
    if (!led || !led->led_info.init)
        return -1;  //初始化引脚之后
    
    if (led->led_info.status == true) {
        __LED_IO_SET(led->led_info.port, led->led_info.pin, led->led_info.led_on_level);   //低电平亮
    } else {
        __LED_IO_SET(led->led_info.port, led->led_info.pin, !led->led_info.led_on_level);   //高电平灭
    }

    return 0;

}


