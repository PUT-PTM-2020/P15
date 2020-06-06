#include <ESP_INIT.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ESP_RESET_ 									"AT+RST"						//RESET WIFI
#define ESP_COMMUNICATION_TEST_						"AT"							//TEST KOMUNIKACJI
#define ESP_SET_MODE_(mode)							"AT+CWMODE="mode				//USTAWIENIE TRYBU PRACY 1 - Client; 2 -AP; 3 AP + Client
#define ESP_CONNECT_TO_WIFI(wifi,pass)				"AT+CWJAP=\""wifi",\""pass		//POŁĄCZENIE Z WIFI
#define ESP_CREATE_A_WIFI(wifi_name, wifi_pass)		"AT+CWSAP\""wifi_name",\""wifi_pass
#define ESP_SET_MUX(mux)							"AT+CIPMUX="mux					//OBSŁUGA POŁĄCZENIA
#define ESP_SET_SERVER(mode,port)					"AT+CIPSERVER="mode","port		//USTAWIENIE SERVERA NA DANYM PORCIE
#define ESP_CLOCE_CONNECTION(connectionNumber)		"AT+CIPCLOSE="connectionNumber
#define ESP_SEND_MESSAGE							"AT+CIPSEND"					//Wysyła wiadomośc do klienta

#define STATUS_OK									"OK\r\n"
#define STATUS_ERROR								"ERROR\r\n"
#define CLIENT										"1"
#define ACCESS_POINT								"2"
#define ACCESS_POINT_CLIENT							"3"
#define MANY_CONNECTION								"1"
#define WIFI_NAME									"Promil_Magnus\""
#define WIFI_PASS									"wpiszcochcesz\""
#define SERVER_START								"1"
#define SERVER_STOP									"0"
#define SERVER_PORT									"8080"

#define SIZE_BUFFER_RECV 							100
#define TIME_TO_WAIT_FOR_CMD						1000							//1000ms
#define TIME_TO_WAIT_FOR_CMD_TO_CONTROLE			20

char _reciveMessageBuff[SIZE_BUFFER_RECV];

extern UART_HandleTypeDef huart2;

void _ESP_reset_buffer(void){
	 memset(_reciveMessageBuff, 0, strlen(_reciveMessageBuff));
}

void ESP_send_command(char* command)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)command, strlen(command), 100);
	HAL_UART_Transmit(&huart2, "\r\n", 2, 1);

}

void ESP_send_news(char* command){
	HAL_UART_Transmit(&huart2, ESP_SEND_MESSAGE, strlen(ESP_SEND_MESSAGE), 10);
	HAL_UART_Transmit(&huart2, (uint8_t *)command, strlen(command), 50);
	HAL_UART_Transmit(&huart2, "\r\n", 2, 1);
}

void ESP_recv_cmd(void){
	HAL_UART_Receive(&huart2, _reciveMessageBuff, SIZE_BUFFER_RECV, TIME_TO_WAIT_FOR_CMD);
}

void ESP_recv_cmd_to_controle(char* recv_buff){
	HAL_UART_Receive(&huart2, recv_buff, SIZE_BUFFER_RECV, TIME_TO_WAIT_FOR_CMD_TO_CONTROLE);
}

bool ESP_find_command(char buffor[], char send_command[], char command[])
{
	int find_command_size = strlen(command), x = 0;

	int size_end = strlen(buffor);
	int i = strlen(buffor-(find_command_size+1) );
	for(int i = strlen((size_end-find_command_size)); i<size_end; i++)	{
		if (buffor[i]==command[x]){
			x++;
		}
	}

	if(x == find_command_size){
		return true;}
	else{
		return false;}
}

bool ESP_find_control_command(char buffor[], char command[]){

	int find_command_size = strlen(command), x = 0;

	int size_end = strlen(buffor);
	for(int i =10; i<size_end; i++)	{
		if (buffor[i]==command[x]){
			if(x==0){
				size_end = i + find_command_size;
			}
			x++;
		}
	}

	if(x == find_command_size){
		return true;}
	else{
		return false;}

}

bool EMPTY_buff(char buffor[], int buff_size){
	int empty_test = 0;
	for(int i = 0; i < buff_size; i++ ){
		if(buffor[i] == '\0'){
			empty_test++;
		}
	}

	if((empty_test >= (0.9*buff_size)) && (empty_test <= buff_size)){
		return true;
	}
	else{
		return false;
	}
}

void ESP_Init(void){

		// RESET WIFI
		ESP_send_command(ESP_RESET_);
		HAL_Delay(1000);
		_ESP_reset_buffer();

		//COMUNICATION TEST
		while(!ESP_find_command(_reciveMessageBuff, ESP_COMMUNICATION_TEST_, STATUS_OK)){					//Test komunikacji
				ESP_send_command(ESP_COMMUNICATION_TEST_);
				ESP_recv_cmd();
		}

		_ESP_reset_buffer();

		//SET MODE
		while(!ESP_find_command(_reciveMessageBuff, ESP_SET_MODE_(ACCESS_POINT_CLIENT), STATUS_OK)){								//Ustawienie trybu pracy
				ESP_send_command(ESP_SET_MODE_(CLIENT));
				ESP_recv_cmd();
		}

		_ESP_reset_buffer();

		//SET MUX
		while(!ESP_find_command(_reciveMessageBuff, ESP_SET_MUX(MANY_CONNECTION), STATUS_OK)){				//Ustawienie trybu pracy
				ESP_send_command(ESP_SET_MUX(MANY_CONNECTION));
				ESP_recv_cmd();
		}

		_ESP_reset_buffer();

		//WIFI CONNECT
		while(!ESP_find_command(_reciveMessageBuff, ESP_CONNECT_TO_WIFI(WIFI_NAME,WIFI_PASS), STATUS_OK)){
				ESP_send_command(ESP_CONNECT_TO_WIFI(WIFI_NAME,WIFI_PASS));
				ESP_recv_cmd();
		}

		_ESP_reset_buffer();

		//START SERVER
		while(!ESP_find_command(_reciveMessageBuff, ESP_SET_SERVER(SERVER_START,SERVER_PORT), STATUS_OK)){				//Ustawienie trybu pracy
				ESP_send_command(ESP_SET_SERVER(SERVER_START,SERVER_PORT));
				ESP_recv_cmd();

		}

		//IF THE MODULE OBTAINS COMMUNICATION, IT LIGHTS UP THE RED LED
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
		_ESP_reset_buffer();

		int test = 0;

}




