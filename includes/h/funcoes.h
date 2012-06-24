#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include"struct.h"
/* cabecalho das funcoes*/

void CleanDisplay();
void InsertNUll(struct client **pInit);
struct client *searchClienttoReturnPointer(struct client *pInit, int cod);
struct acoes *searchAcoesToReturnPointer(struct acoes *pAcoes, int cod);
int SignUpClientInit(struct client **pInit);
void SignUpAfter(struct client *p);
void showAllAcoes(struct acoes *p);
void showAllElements(struct client *pInit);
void sellAcoes(struct client *pInit);
int searchForClient(struct client *pInit, int x);
int searchForAcao(struct acoes *pAcao, int cod);
void buyAcoes(struct client *pInit);
