#include <ENG_CONTROL.h>
#include "UDS_INIT.h"
#include <ControleMe.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"


int _RESET 					=			0;
int _SET					=			1;
int _SPEED_TURN				=			0;

void check_period(){										//WYKORZYSTYWANA DO USTAWIENIA PRĘDKOŚCI
	if(!USD_reduce_speed()){
		if((TIM4->CCR1 != 1999) || (TIM4->CCR2 != 1999)){
			TIM4->CCR1 = 1999;
			TIM4->CCR2 = 1999;
		}
	} else {												//JEŻELI CZUJNIKI ZACZNĄ WYKRYWAĆ PRZESZKODĘ< TO ZREDUKUJE PRĘDKOŚĆ
		if((TIM4->CCR1 != 999) || (TIM4->CCR2 != 999)){
			TIM4->CCR1 = 999;
			TIM4->CCR2 = 999;
		}
	}
}

void check_and_set_period(int ccr){							//WYKORZYSTYWANA DO ZMIANY KIERUNKU JAZDY
	if((TIM4->CCR1 != ccr) || (TIM4->CCR2 != ccr)){
		TIM4->CCR1 = ccr;
		TIM4->CCR2 = ccr;
	}
}

void check_and_set_period_2(int ccr1, int ccr2){			//WYKORZYSTYWANA DO SKRĘCANIA
	if(USD_reduce_speed() == false){								//JEŻELI CZUJNIKI ZACZNĄ WYKRYWAĆ PRZESZKODĘ< TO ZREDUKUJE PRĘDKOŚĆ
		if((TIM4->CCR1 != ccr1) || (TIM4->CCR2 != ccr2)){
			TIM4->CCR1 = ccr1;
			TIM4->CCR2 = ccr2;
		}
	} else {
		if((TIM4->CCR1 != (ccr1/2)) || (TIM4->CCR2 != (ccr2/2))){
			TIM4->CCR1 = ccr1/2;
			TIM4->CCR2 = ccr2/2;
		}
	}
}



void ENG_forward()
{
	check_period();

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
}

void ENG_back() //UNUSED
{
	check_period();

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
}


void ENG_left()
{
	if(_SPEED_TURN < 100)
		check_and_set_period(799);
	else if(_SPEED_TURN >= 100)
		check_period();

	_SPEED_TURN++;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
}

void ENG_left_turn()
{
	check_and_set_period_2(1299, 1999); //1599

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
}

void ENG_right()
{
	_SPEED_TURN = 0;
	check_and_set_period(799);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
}

void ENG_right_turn()
{
	check_and_set_period_2(1999, 1299); //1599
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
}
void ENG_break_()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);

}

void ENG_choose(int choose){
	if(choose == 1)
	{
		ENG_left();
	}
	else if (choose == 2 )
	{
		ENG_left_turn();
	}
	else if (choose == 3){
		ENG_forward();
	}
	else if (choose == 4){
		ENG_right_turn();
	}
	else if (choose == 5){
		ENG_right();
	}
}

void ENG_just_a_turn(int choose){
	if(choose == 1){
		ENG_left();
	}
	else if (choose == 5){
		ENG_right();
	}
}
