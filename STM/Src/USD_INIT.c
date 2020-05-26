#include <UDS_INIT.h>
#include <stdbool.h>
#include "dwt_stm32_delay.h"


uint16_t 										_main_dist_front = 0;
uint16_t 										_main_dist_left = 0;
uint16_t 										_main_dist_right = 0;

bool											_FLAG_reduce_speed = false;  //FLAGA OGRANICZAJĄCA PRĘDKOŚĆ - JEŻELI FLAGA BĘDZIE MIAŁA WARTOŚĆ TRUE, NASTĄPI ZREDUKOWANIE PRĘDKOŚCI

uint32_t UDS_distance(GPIO_TypeDef* GPIO_TRIG, uint16_t GPIO_PIN_TRIG, GPIO_TypeDef* GPIO_ECHO, uint16_t GPIO_PIN_ECHO  )
{
	uint32_t local_time = 0;
	HAL_GPIO_WritePin(GPIO_TRIG, GPIO_PIN_TRIG, GPIO_PIN_SET);
	DWT_Delay_us(5);
	HAL_GPIO_WritePin(GPIO_TRIG, GPIO_PIN_TRIG, GPIO_PIN_RESET);

	while(!HAL_GPIO_ReadPin(GPIO_ECHO, GPIO_PIN_ECHO));

	while(HAL_GPIO_ReadPin(GPIO_ECHO, GPIO_PIN_ECHO))
	{
		local_time++;
		DWT_Delay_us(1);
	}

	return local_time /58;
}


bool USD_set_lock(){

	_main_dist_front	=	UDS_distance(GPIOC,		GPIO_PIN_15,	GPIOC,	GPIO_PIN_14 );
	_main_dist_left		=	UDS_distance(GPIOE,		GPIO_PIN_5,		GPIOE,	GPIO_PIN_4 );
	_main_dist_right	=	UDS_distance(GPIOC,		GPIO_PIN_13,	GPIOE,	GPIO_PIN_6 );

	if(((_main_dist_front <= 35) && ( _main_dist_front > 25)) 			||
			((_main_dist_left	<= 35) && ( _main_dist_left > 25)) 	||
			((_main_dist_right <= 35) && ( _main_dist_left > 25)) 		)
	{
		//_FLAG_reduce_speed = true;
	}

	if((_main_dist_front <= 25) || (_main_dist_left	<= 25) || (_main_dist_right <= 25)){
		return false;
	} else {
		_FLAG_reduce_speed = false;
		return true;
	}
}

bool USD_reduce_speed(){
	if(_FLAG_reduce_speed == true)
		return true;
	else
		return false;
}
