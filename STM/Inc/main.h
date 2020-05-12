/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PGIO_Input_Pin GPIO_PIN_4
#define PGIO_Input_GPIO_Port GPIOE
#define GPIO_Output_TRIG_czujnik3___bia_y_Pin GPIO_PIN_5
#define GPIO_Output_TRIG_czujnik3___bia_y_GPIO_Port GPIOE
#define GPIO_Input_Pin GPIO_PIN_6
#define GPIO_Input_GPIO_Port GPIOE
#define GPIO_Output_Pin GPIO_PIN_13
#define GPIO_Output_GPIO_Port GPIOC
#define GPIO_Input__ECHO_czujnik1__br_zowy_Pin GPIO_PIN_14
#define GPIO_Input__ECHO_czujnik1__br_zowy_GPIO_Port GPIOC
#define GPIO_Output__TRIG_czujnik1__czerwony_Pin GPIO_PIN_15
#define GPIO_Output__TRIG_czujnik1__czerwony_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
