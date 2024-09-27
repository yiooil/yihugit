/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup Template_Project
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;
RCC_ClocksTypeDef RCC_Clocks;

/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       files (startup_stm32f40_41xxx.s/startup_stm32f427_437xx.s/
       startup_stm32f429_439xx.s/startup_stm32f401xx.s or startup_stm32f411xe.s)
       before to branch to application main.
       To reconfigure the default setting of SystemInit() function, 
       refer to system_stm32f4xx.c file */
  

//  LED_Class LED[2] = {{
//    .led_info = {GPIOF, GPIO_Pin_9, 0},
//    .LED_InitCall = LED_Init,
//    .LED_OnCall = LED_On,
//    .LED_OffCall = LED_Off,
//    .LED_SetStatusCall = LED_SetStatus,
//    .LED_RefreshStatusCall = LED_RefreshStatus,
//    .ledclass = NULL
//  },
//  {
//    .led_info = {GPIOF, GPIO_Pin_10, 0},
//    .LED_InitCall = LED_Init,
//    .LED_OnCall = LED_On,
//    .LED_OffCall = LED_Off,
//    .LED_SetStatusCall = LED_SetStatus,
//    .LED_RefreshStatusCall = LED_RefreshStatus,
//    .ledclass = NULL
//}
//};

  NVICGROUP_Init(); 
  DEBUG_Init(115200);
  Delay_Init(168);

  /* SysTick end of count event each 10ms */
  RCC_GetClocksFreq(&RCC_Clocks);



  while (1)
  {
//    LED[0].LED_OnCall(&LED[0]);
//    LED[1].LED_OnCall(&LED[1]);
//    Delay_ms(500);
//    LED[0].LED_OffCall(&LED[0]);
//    LED[1].LED_OffCall(&LED[1]);
    Delay_ms(500);
    printf("hello world\r\n");
  }
}




