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

//definindo cores (ANSI)
#define RESET "\033[0;0m"
//fonts
#define FONT_GRAY "\033[1;37m"
#define FONT_BLACK "\033[1;30m"
#define FONT_RED "\033[1;31m"
#define FONT_BLUE "\033[1;94m"
//backgrounds
#define BACKGROUND_BLACK "\033[1;40m"
#define BACKGROUND_GRAY "\033[1;47m"


int main(){
    //create variables
    int resp;
    
    while (resp != 0){
        system(clear);
        printf(BACKGROUND_BLACK "\n<<< SISTEMA DE ENCOMENDA DE LIVRO >>>\n-------------------------------------\n");
        printf(BACKGROUND_GRAY FONT_BLUE " 1 - Encomendar um livro.\n" //sem pedir senha
               " 2 - Remover uma encomenda de livro.\n" //secretario - pedir senha
               " 3 - Remover um pedido de livro.    \n" //transportadores - pedir senha
               " 4 - Exibir encomendas.             \n"
               " 5 - Exibir pedidos.                \n"
               " 6 - Exibir usuarios cadastrados.   \n"
               " 0 - Sair do sistema!               \n"
               RESET FONT_BLUE "\nDigite a funcionalidade desejada: "); scanf("%d", &resp);

        switch (resp){
            case 1: //encomendar um livro
                system(clear); encomendar(); quit(); break;

            case 2:
                system(clear); remover_encomenda(); quit(); break;

            case 3:
                system(clear); remover_pedido(); quit(); break;

            case 4:
                system(clear); in_ordem(root); quit(); break;

            case 5:
                system(clear);
                if (fifop_start != NULL){imprimir(fifop_start);}
                else {printf("\nNão existe nenhum pedido cadastrado no momento.\n\n");}
                
                quit(); break;

            case 6:
                system(clear); printf("\n<<< Usuarios cadastrados >>>\n\n");
                fifopre_imprimir(fifopre_start);
                quit(); break;

            case 1815: //OPCAO ESPECIAL (Ada Lovelace - reference)
                system(clear); printf("\n\n<<< Exibir estrutura da ABB (Graficamente) >>>\n-----------------------------------\n\n");
                abb_exibir_estrutura(root, 1);
                printf("\n============================================\n\n\n"); 
                quit(); break;
            
            default:
                printf("\n\nSelecione uma opção valida!\n\n"); break;}}
        
    system(clear); printf("Programa finalizado!\n\n"); return 0;}