#include <ControleMe.h>
#include <UDS_INIT.h>
#include <ESP_INIT.h>
#include <ENG_CONTROL.h>
#include <stdbool.h>
#include <string.h>


#define SIZE_RECIVE_BUFF						100
#define DEFAULT_MESSAGE(ID,DATA_SIZE)			"+IPD,0,"DATA_SIZE":"
#define BAN_DRIVING_MESS						"dg"
char 											_reciveMessagebuff[SIZE_RECIVE_BUFF] = {0};
int												_FLAG_weit = 0;
bool											_FLAG_Distance = true; 				//Jeżeli nie wykryje przeszkody flaga ustawiona na TRUE - można się poruszac
bool											_FLAG_i_m_moving = false;
bool											_FLAG_just_a_turn = false;
int												_FLAG_course = 0;
													/*
													 * LEFT = 1
													 * LEFT_TURN = 2
													 * FORWARD = 3
													 * RIGHT_TURN = 5
													 * RIGHT = 6
													 */



int find_command(char bufor[])
{
	int i = 0, check_cmd = 0, size = strlen(bufor);
	while(bufor[i] != ':') {
		i++;
		if(i == size){
			break;
		}
	}
	i++;

	while((bufor[i]!='\r')){
		i++;
		check_cmd++;
		if((bufor[i]=='\n')||(bufor[i]=='\0')||( strlen(bufor) == i)){
			break;
		}
	}

	if(check_cmd == 4){
		return 1;
	} else if (check_cmd == 3){
		return 2;
	} else if (check_cmd == 7){
		return 3;
	}else if (check_cmd == 2){
		return 4;
	}else if (check_cmd == 5){
		return 5;
	} else {
		return 0;
	}
}

void time_to_died(){
	_FLAG_weit++;

	if(_FLAG_just_a_turn){
		_FLAG_just_a_turn = false;
	}else if (_FLAG_i_m_moving){
		_FLAG_i_m_moving= false;
	}

	if(_FLAG_weit == 15){
		ENG_break_();
		_FLAG_weit =0;
	}
}

bool check_pin_state(){
	if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) ||
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == GPIO_PIN_SET) ||
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == GPIO_PIN_SET) ||
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) == GPIO_PIN_SET)) {
		return true;
	}
	else{
		return false;
	}
}


void CM_init(){

	while(EMPTY_buff(_reciveMessagebuff, sizeof(_reciveMessagebuff))){
		ESP_recv_cmd_to_controle(_reciveMessagebuff);
		if(check_pin_state()){
			time_to_died();
		}
	}

	if(!EMPTY_buff(_reciveMessagebuff, sizeof(_reciveMessagebuff))){

		int choose = find_command(_reciveMessagebuff);

		if((choose >0) && (choose <=5)){
			if(USD_init()){
				if(_FLAG_just_a_turn){
					_FLAG_just_a_turn = false;
				}
				_FLAG_i_m_moving = true;

				_FLAG_weit =0;
				ENG_choose(choose);

				choose = 0;
			}
			else {
				if((check_pin_state()) && (_FLAG_i_m_moving)){
					ENG_break_();
				}
				if(_FLAG_i_m_moving){
					_FLAG_i_m_moving = false;
				}

				_FLAG_just_a_turn = true;
				ESP_send_news(BAN_DRIVING_MESS);

				if((choose == 1)||(choose == 5)){
					_FLAG_weit =0;
					ENG_just_a_turn(choose);
				}
				choose = 0;
			}
		}else {
			time_to_died();
			choose = 0;
		}
	}
	else
	{
			time_to_died();
	}

	memset(_reciveMessagebuff, '\0', strlen(_reciveMessagebuff));
}



