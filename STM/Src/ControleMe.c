#include <ControleMe.h>
#include <UDS_INIT.h>
#include <ESP_INIT.h>
#include <ENG_CONTROL.h>
#include <stdbool.h>
#include <string.h>



#define SIZE_RECIVE_BUFF						100
#define DEFAULT_MESSAGE							"+IPD,ID,DATA_SIZE:MESSAGE"

char 											_reciveMessagebuff[SIZE_RECIVE_BUFF] = {0};
char											_forward[] = {'F','o','r','w','a','r','d','\r','\n'};
char											_left[] = {'L','e','f','t','\r','\n'};
char 											_right[] = {'R','i','g','h','t','\r','\n'};
int												_check_command;
int												_FLAG_move = 0;
int												_FLAG_weit = 0;						//Kiedy dostanie pakiet to flaga ustawia się na 0
bool											_FLAG_Distance = true; 				//Jeżeli nie wykryje przeszkody flaga ustawiona na TRUE - można się poruszac
bool											_FLAG_Process_data = false;
bool											_FLAG_Receiving_message = true;	//FALSE - NIE ODBIERA NIC
int												test_na_30_sek = 0;


int encoding_mess(char recvBuff[]){													//DEKODOWANIE DANYCH - SPRAWDZENIE POPRAWNOŚCI
	int startData = 0;
	int recv_size = strlen(recvBuff), check_value = 0;
	char recvDataSize;
	while(recvBuff[startData] != '+'){
		startData++;
	}
	if(recvBuff[startData++] == '+'){
		if(recvBuff[startData++] == 'I') { check_value++; }
		if(recvBuff[startData++] == 'P') { check_value++; }
	if(recvBuff[startData++] == 'D') { check_value++; }
		if(recvBuff[startData++] == ',') { check_value++; }
		if(recvBuff[startData] == '0')  { check_value++; }
		if(check_value == 5){
			startData+=2;
			recvDataSize = recvBuff[startData];
			startData++;
		}
	}

	if((recvDataSize > 0) && (check_value == 5)){
		if (recvDataSize == '4'){												//PRAWOSKRĘT
			memset(recvBuff, 0, recv_size);
			return 5;
		}
		else if (recvDataSize == '5'){											//LEWOSKRĘT
			memset(recvBuff, 0, recv_size);
			return 4;
		}else if(recvDataSize == '6'){											//LEWO
			memset(recvBuff, 0, recv_size);
			return 1;
		}
		else if (recvDataSize == '7'){											//PRAWO
			memset(recvBuff, 0, recv_size);
			return 2;
		}
		else if (recvDataSize == '9'){											//PRZÓD
			memset(recvBuff, 0, recv_size);
			return 3;
		}

	}

	memset(recvBuff, 0, recv_size);
	return 0;
}


bool recv_buff_EMPTY()
{
	int check =0;
	for(int i = 0; i < sizeof(_reciveMessagebuff); i++) {
		if(_reciveMessagebuff[i] == '\0') {
			check++;
		}
	}
	//TEST
	if((check >(0.9*sizeof(_reciveMessagebuff))) && (check <sizeof(_reciveMessagebuff))){
		check = sizeof(_reciveMessagebuff);
		test_na_30_sek++;
	}

	if(check==sizeof(_reciveMessagebuff)){
		return true;
	} else {
		return false;
	}
}


void CM_init_USD(){
	if(!USD_set_lock()){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		//_FLAG_Distance = false;										//WYKRYCIE PRZESZKODY POWODUJE ZABLOKOWOANIE OPCJI PORUSZANIA SIĘ W KIERUNKACH: LEWOSKRĘT, PRZÓD, PRAWOSKRĘT
	}else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		_FLAG_Distance = true;
	}
}

void CM_init_RECV(){
	if(!_FLAG_Process_data){

		/*if(!_FLAG_Receiving_message){
			_FLAG_Receiving_message = true;
		}*/

		ESP_recv_cmd_to_controle(_reciveMessagebuff, sizeof(_reciveMessagebuff));

		if(recv_buff_EMPTY()){
			_FLAG_weit++;
			if(_FLAG_weit >= 25){
				ENG_break_();
				_FLAG_weit = 0;
			}
		} /*else{
			_FLAG_Receiving_message = false;
		}*/

	} else {
		_FLAG_weit = 0;
	}
}

/*#define		LEWO				=			1
#define 		PRAWO				=			2
#define 		PRZOD				=			3
#define 		LEWOSKRET			=			4
#define			PRAWOSKRET			=			5*/


void CM_init_ControleMe(){
	/*if(!_FLAG_Receiving_message){*/
		if(!recv_buff_EMPTY()){
 			_FLAG_Process_data= true;									//JEŻELI DANE SĄ PRZETWARZANE TO NIE MOŻNA ODBIERAĆ KOLEJNYCH PAKIETÓW

			_check_command = encoding_mess(_reciveMessagebuff);			//ODKODOWANIE WIADOMOŚCI

			if(_check_command==1){										//PRZETWARZANIE WIDOMOŚCI
				ENG_left();
			} else if (_check_command==2){
				ENG_right();
			} else if ((_check_command==3) && (_FLAG_Distance)){
				ENG_forward();
			}
			else if ((_check_command==4) && (_FLAG_Distance)){
				ENG_left_turn();
			}else if ((_check_command==5) && (_FLAG_Distance)){
				ENG_right_turn();
			}else if (((_check_command==3) || (_check_command==4) || (_check_command==5)) && (!_FLAG_Distance)){
				ENG_break_();
			}

			memset(_reciveMessagebuff, 0, sizeof(_reciveMessagebuff));

			_FLAG_Process_data= false;									//ZAKOŃCZENIE PRZETWARZANIA DANYCH - MOŻNA ZACZĄC POBIERAĆ KOLEJNY PAKIET
		}
	//}
}





