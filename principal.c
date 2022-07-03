//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "fuctions_system.h"

//detectando o sistema operacional
#ifdef __unix__
    char clear[] = "clear";

#elif defined(_WIN32) || defined(WIN32)
    char clear[] = "cls";

#endif


int main(){
    add_pre_cadastrados();

    //create variables
    int resp;
    
    while (1){
        system(clear); printf(RESET BOLD BACKGROUND_BLUE "\n<<< SISTEMA DE ENCOMENDA DE LIVRO >>>\n-------------------------------------\n");
        printf(RESET BACKGROUND_WHITE FONT_BLUE " 1 - Encomendar um livro.            \n" //sem pedir senha
               " 2 - Remover uma encomenda de livro. \n" //secretario - pedir senha
               " 3 - Remover um pedido de livro.     \n" //transportadores - pedir senha
               " 4 - Exibir encomendas.              \n"
               " 5 - Exibir pedidos.                 \n"
               " 6 - Exibir usuarios cadastrados.    \n"
               " 0 - Sair do sistema!                \n"
               RESET FONT_BLUE "\nDigite a funcionalidade desejada: "); scanf("%d", &resp);

        switch (resp){
            case 1: //encomendar um livro
                system(clear); encomendar(); quit("voltar"); break;

            case 2:
                system(clear); remover_encomenda(); quit("voltar"); break;

            case 3:
                system(clear); remover_pedido(); quit("voltar"); break;

            case 4:
                system(clear); in_ordem(root); quit("voltar"); break;

            case 5:
                system(clear);
                if (fifop_start != NULL){imprimir(fifop_start);}
                else {printf(BOLD BACKGROUND_WHITE FONT_RED "\nNão existe nenhum pedido cadastrado no momento.\n\n" RESET);}
                quit("voltar"); break;

            case 6:
                system(clear); printf(BOLD BACKGROUND_BLUE "\n<<< Usuarios cadastrados >>>\n\n" RESET);
                fifopre_imprimir(fifopre_start);
                quit("voltar"); break;

            case 1815: //OPCAO ESPECIAL (Ada Lovelace - reference)
                system(clear); printf(BOLD BACKGROUND_WHITE FONT_BLUE "\n\n<<< Exibir estrutura da ABB (Graficamente) >>>\n----------------------------------------------\n\n" RESET);
                abb_exibir_estrutura(root, 1);
                printf(BOLD BACKGROUND_WHITE FONT_BLUE "\n==============================================\n\n\n" RESET); 
                quit("voltar"); break;

            case 0:
                system(clear); printf(BOLD BACKGROUND_WHITE FONT_GREEN " Programa finalizado! \n\n" RESET); exit(1);
            
            default:
                printf(BOLD FONT_RED "\n\nSelecione uma opção valida!\n" RESET); quit("voltar"); break;}}}