#ifndef ControleMe_H_
#define ControleMe_H_
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"

int encoding_CMD(char recvBuff[], int startData, char command[]);
int encoding_mess(char recvBuff[]);
bool recv_buff_EMPTY(void);
void CM_init_USD(void);
void CM_init_ControleMe(void);
void CM_init_RECV(void);


#endif
