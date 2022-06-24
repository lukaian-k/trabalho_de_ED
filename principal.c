//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "fuctions_system.h"


int main(){
    int resp; printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    
    while (resp != 0){
        printf(" 1 - Encomendar um livro.\n"
               " 2 - Remover uma encomenda de livro.\n"
               " 3 - Remover um pedido de livro.\n"
               " 0 - Sair do sistema!\n"
               "Digite a funcionalidade desejada: "); scanf("%d", &resp);

        switch (resp){
            case 1: //encomendar um livro
                encomendar(); break;

            case 2: break;

            case 3: break;
            
            default: break;}}
        
    return 0;}
            
        /*if(resp == 1){
            //encomendar um livro
            printf(" Digite o nome do aluno:\n");
            char * nome = malloc(sizeof(char));
            scanf(" %[^\n]s", nome);
            //... matricula e descricao..
            //criar um funcao para gerar id unico (:D)
            //add_abb(id, nome, matricula, descricao);
        }else if(resp == 2){
            //remover uma encomenda de livro da ABB (id)
            //para remover eu preciso:
            //1 - visualizar as encomendas (in_ordem)
            in_ordem();
            //2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            //int retorno = verificar(cpf, senha);
            if(retorno == 1){
                //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                //4 - setar novos dados (faltando)
                //5 - add_fila(....);
            }else if(resp == 3){
               
                //2 - verificar o usuario
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", &cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                    if(retorno == 1){
                        //remover da fila de prioridade}}}*/