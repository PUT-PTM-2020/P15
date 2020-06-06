#ifndef ControleMe_H_
#define ControleMe_H_
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"

bool encoding_mess(char recvBuff[], uint8_t recvDataSize, uint8_t IDconnection, uint8_t startData);
bool encoding_mess(char recvBuff[], uint8_t recvDataSize, uint8_t IDconnection, uint8_t startData);

bool recv_buff_EMPTY(void);
int find_command(char bufor[]);
void time_to_died(void);
void CM_init_USD(void);
void CM_iniy(void);




#endif
