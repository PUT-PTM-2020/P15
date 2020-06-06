#ifndef ESP_INIT_H_
#define ESP_INIT_H_
#include <stdbool.h>

#include "main.h"

//BASIC FUNCTION
void ESP_send_command(char *command);
void ESP_send_news(char* command);
void ESP_recv_cmd(void);
void ESP_recv_cmd_to_controle(char* recv_buff);
bool ESP_find_command(char buffor[], char send_command[], char command[]);
bool ESP_find_control_command(char buffor[], char command[]);

//EXTENDED FUNCTION
bool EMPTY_buff(char buffor[], int buff_size);

//COMPLEX FUNCTIONS
void ESP_Init();


#endif
