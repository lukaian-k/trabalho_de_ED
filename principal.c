//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "fuctions_system.h"


int main(){
    //create variables
    int resp;
    
    while (resp != 0){
        printf("\n===SISTEMA DE ENCOMENDA DE LIVRO===\n\n");
        printf(" 1 - Encomendar um livro.\n" //sem pedir senha
               " 2 - Remover uma encomenda de livro.\n" //secretario - pedir senha
               " 3 - Remover um pedido de livro.\n" //transportadores - pedir senha
               " 0 - Sair do sistema!\n"
               "\nDigite a funcionalidade desejada: "); scanf("%d", &resp);

        switch (resp){
            case 1: //encomendar um livro
                encomendar(); break;

            case 2:
                //validacao: cpf e senha
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