#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include"includes/h/funcoes.h"

int main()
{
    struct client *init;
    
    int op, cont;
    
    cont = 0;
    
    InsertNUll(&init);
    
    while(op != 5)
    {
        CleanDisplay();   
        printf("\n\n**************Sistema de acoes**************\n\n");
        printf("Escolha a operacao\n");
        printf("1-Incluir cliente\n");
        printf("2-Compra de acoes\n");
        printf("3-Venda de acoes\n");
        printf("4-Pesquisa\n");
        printf("5-Sair\n\n");
        scanf("%d",&op);
        //limpa o Buffer do teclado
        __fpurge(stdin);
    
        if(op == 1)
        {
            if(cont == 0)
            {
                CleanDisplay();
                SignUpClientInit(&init);
                cont++;
            }
             else
             {
                CleanDisplay();
                SignUpAfter(init);
                
             }
        }
        if(op == 2)
        {
            CleanDisplay();
            buyAcoes(init);               
        }
        if(op == 3)
        {
            CleanDisplay();
            sellAcoes(init);
        }
        if(op == 4)
        {
            CleanDisplay();
            showAllElements(init);    
        }
        if(op == 5)
        {
            CleanDisplay();
            exit(1);
        }   
    }   
    
    return 0;   
}
