#include<stdio.h>
#include"../h/funcoes.h"

void CleanDisplay()
{
     printf("\e[H\e[2J");
}

void InsertNUll(struct client **pInit)
{
    *pInit = NULL;
}

struct acoes *searchAcoesToReturnPointer(struct acoes *pAcoes, int cod)
{
    if(pAcoes == NULL)
        return; // nao existe acao com este codigo
    if(pAcoes->codigo == cod)
        return pAcoes; //cliente encontrado, retorno o ponteiro
    else
        searchAcoesToReturnPointer(pAcoes->next, cod);
}

struct client *searchClienttoReturnPointer(struct client *pInit, int cod)
{
    if(pInit == NULL)
        return; // nao existe cliente com este codigo
    if(pInit->codigo == cod)
        return pInit; //cliente encontrado, retorno o ponteiro
    else
        searchClienttoReturnPointer(pInit->next, cod);
}


int SignUpClientInit(struct client **pInit)
{
    //ponteiro para alocação
    struct client *aux;
    struct acoes *clAux;
    
    //variaveis temporarias
    int cod;
    
    printf("\n\n\n");
    printf("******Sistema de acoes******\n\n");
    printf("**Cadastro de Clientes**\n\n");
    
    aux = (struct client*) malloc(sizeof(struct client));
    //inserindo informações na estrutura pessoa
    printf("Digite o código do cliente: ");
    scanf("%d",&cod);
    aux->codigo = cod;
    __fpurge(stdin);
    printf("Digite o Nome do cliente: ");
    gets(aux->nome);
    printf("Digite o endereco: ");
    gets(aux->endereco);
    aux->next = *pInit;
    *pInit = aux;     
    
}

void SignUpAfter(struct client *p)
{
    struct client *aux;
    
    //variaveis temporarias
    int cod;
    
    printf("\n\n\n");
    printf("******Sistema de acoes******\n\n");
    
    aux = (struct client *)malloc(sizeof(struct client));
    printf("\n\n");
    printf("Digite o código do cliente: ");
    scanf("%d",&cod);
    if(searchForClient(p, cod) == 1)
    {
        printf("cliente ja cadastrado!\n");
        return;       
    }
    else
    {
        aux->codigo = cod;
        __fpurge(stdin);
        printf("Digite o Nome do cliente: ");
        gets(aux->nome);
        printf("Digite o endereco: ");
        gets(aux->endereco);
        aux->next = p->next;
        p->next = aux;
    }
}

void showAllAcoes(struct acoes *p)
{
        if(p!= NULL)
        {
            printf("*********Acoes**********\n");
            printf("Codigo: %d\n",p->codigo);
            printf("Nome: %s\n",p->nome);
            printf("Quantidade: %d\n",p->qtdeacoes);
            showAllAcoes(p->next);
        }       
}

void showAllElements(struct client *pInit)
{
    int codigo;
    struct client *aux;
    
    printf("\n\n");
    printf("*****pesquisa Cliente***********\n\n");
    
    printf("Digite o código para pesquisa: ");
    scanf("%d",&codigo);
    
    aux = searchClienttoReturnPointer(pInit, codigo);
    
    if(aux != NULL)
    {
       
        printf("\n\n------------------------\n\n");
        printf("***CLIENTE***\n");
        printf("Codigo: %d\n",aux->codigo);
        printf("Nome: %s\n",aux->nome);
        printf("Endereco: %s\n",aux->endereco);
        showAllAcoes(aux->Acoes);
    }
    printf("\n\n");
    __fpurge(stdin);
    printf("press qlquer tecla p continuar...\n\n");
    getchar();
}

void sellAcoes(struct client *pInit)
{
    struct client *aux;
    struct acoes *auxAcao, *p;
    
    int codigo, venda, codAc;
    
    printf("\n\n");
    printf("***Venda de acoes****\n\n");
    
    printf("Codigo do cliente: ");
    scanf("%d",&codigo);
    aux = searchClienttoReturnPointer(pInit, codigo);
    
    printf("codigo da acao: ");
    scanf("%d",&codAc);
    auxAcao = searchAcoesToReturnPointer(aux->Acoes, codAc);
    
    printf("quantidade da venda: ");
    scanf("%d",&venda);
    auxAcao->qtdeacoes -= venda;
    if(auxAcao->qtdeacoes == 0)
    {
        p = auxAcao;
        aux->Acoes = p->next;
        free(p);
    }
    
    
    
}

int searchForClient(struct client *pInit, int x)
{
   if(pInit == NULL)
        return 0; // nao existe cliente com este codigo
        
   if(pInit->codigo == x)
        return 1; //cliente encontrado
   else
        searchForClient(pInit->next, x); 
        
}

int searchForAcao(struct acoes *pAcao, int cod)
{
    if(pAcao == NULL)
        return 0; // nao existe nem uma acao
    if(pAcao->codigo == cod)
        return 1; // acao encontrada
    else
        searchForAcao(pAcao->next, cod);  
}

void buyAcoes(struct client *pInit)
{
    struct acoes *clAux, *setNull, *prev;
    struct client *aux;
    
    int iAcoes, codAc, codCli, cont;
    cont = 0;
    
    setNull = NULL;
    
    printf("\n\n");
    printf("***compra de acoes***\n\n");
   
    printf("codigo do ciente: ");
    scanf("%d",&codCli);
    
    if(searchForClient(pInit, codCli) == 0)
    {
        printf("Cliente nao cadastrado\n\n");
        exit(1);
    }
    else
    {
        aux = searchClienttoReturnPointer(pInit, codCli);
        printf("Digite o codigo da acao: ");
        scanf("%d",&codAc);
        if(aux->Acoes == NULL)
        {
            clAux = (struct acoes*) malloc(sizeof(struct acoes));
            clAux->codigo = codAc;
            __fpurge(stdin);
            printf("Digite o nome da acao: ");
            gets(clAux->nome);
            __fpurge(stdin);
            printf("Digite a quantidade de acoes: ");
            scanf("%d",&iAcoes);
            clAux->qtdeacoes = iAcoes;
            clAux->next = setNull;
            prev = clAux;
            aux->Acoes = clAux;
             
        }
        else if(searchForAcao(aux->Acoes, codAc) == 0) // considerando que uma acao esta cadastrada
        {
            clAux = (struct acoes*) malloc(sizeof(struct acoes));
            clAux->codigo = codAc;
            __fpurge(stdin);
            printf("Digite o nome da acao: ");
            gets(clAux->nome);
            __fpurge(stdin);
            printf("Digite a quantidade de acoes: ");
            scanf("%d",&iAcoes);
            clAux->qtdeacoes = iAcoes;
            aux->Acoes = clAux;
            if(cont == 0)
            {
                clAux->next = prev;
                prev = clAux;
            }
            else
            {
                clAux->next = prev;
                prev = clAux;
            }
             
        }
        else
        {
            clAux = searchAcoesToReturnPointer(aux->Acoes, codAc);
            printf("Digite a quantidade de acoes: ");
            scanf("%d",&iAcoes);
            clAux->qtdeacoes += iAcoes;
        }
    }
    cont++;
}
