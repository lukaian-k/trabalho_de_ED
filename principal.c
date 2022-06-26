//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "fuctions_system.h"


int main(){
    //create variables
    int resp;
    
    while (resp != 0){
        printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
        printf(" 1 - Encomendar um livro.\n"
               " 2 - Remover uma encomenda de livro.\n"
               " 3 - Remover um pedido de livro.\n"
               " 0 - Sair do sistema!\n"
               "Digite a funcionalidade desejada: "); scanf("%d", &resp);

        switch (resp){
            case 1: //encomendar um livro
                encomendar(); break;

            case 2:
                remover_encomenda(); break;

            case 3:
                break;

            case 1815: //OPCAO ESPECIAL (Ada Lovelace - reference)
                printf("\n\n===Exibir estrutura da ABB (Graficamente)===\n\n");
                abb_exibir_estrutura(root, 1);
                printf("\n============================================\n\n\n"); break;
            
            default:
                printf("\n\nSelecione uma opção valida!\n\n"); break;}}
        
    return 0;}
            
/*
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
                        //remover da fila de prioridade}}}
*/