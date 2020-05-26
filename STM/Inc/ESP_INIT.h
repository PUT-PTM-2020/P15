#ifndef ESP_INIT_H_
#define ESP_INIT_H_
#include <stdbool.h>

#include "main.h"

void ESP_send_command(char *command);
void ESP_recv_cmd(void);
void ESP_recv_cmd_to_controle(char* recv_buff, int size_of_buff);
bool ESP_find_command(char buffor[], char send_command[], char command[]);
bool ESP_find_control_command(char buffor[], char command[]);
void ESP_Init();


#endif
