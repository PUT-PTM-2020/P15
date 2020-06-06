#ifndef UDS_INIT_H_
#define UDS_INIT_H_
#include <stdbool.h>

#include "main.h"

//BASIC FUNCTION
uint32_t UDS_distance(GPIO_TypeDef* GPIO_TRIG, uint16_t GPIO_PIN_TRIG, GPIO_TypeDef* GPIO_ECHO, uint16_t GPIO_PIN_ECHO );
bool USD_set_lock(void);
bool USD_reduce_speed(void);

//COMPLEX FUNCTION
bool USD_init();



#endif
