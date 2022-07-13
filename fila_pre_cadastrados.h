//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "structs.h"

//create variables
Fifopre_node *fifopre_start = NULL; Fifopre_node *fifopre_last = NULL; int fifopre_tam = 0;


//fuctions

void fifopre_add(char *nome, char *senha, int cpf, char cargo){
        Fifopre_node *novo = malloc(sizeof(Fifopre_node));
        novo->admin.nome = nome;
        novo->admin.senha = senha;
        novo->admin.cpf = cpf;
        novo->admin.cargo = cargo;
        
        novo->next = NULL;
    
        if (fifopre_start == NULL){ //fila vazia
            fifopre_start = novo; fifopre_last = novo; fifopre_tam++;}

        else {
            fifopre_last->next = novo;
            fifopre_last = novo; fifopre_tam++;}}


void fifopre_imprimir(Fifopre_node *aux){
    if (aux != NULL){
        printf(BACKGROUND_WHITE FONT_BLACK " %s - Cargo: %c \n" RESET, aux->admin.nome, aux->admin.cargo);
        printf(BOLD FONT_GREEN "-----------------------------\n" RESET);
        fifopre_imprimir(aux->next);}}


void add_pre_cadastrados(){
    //secretarios
    fifopre_add("Brenda Vieira", "100", 100, 'S');
    fifopre_add("Pietro Correia", "200", 200, 'S');
    fifopre_add("Noah da Costa", "300", 300, 'S');
    ////transportadores
    fifopre_add("Davi Lucca Nunes", "111", 111, 'T');
    fifopre_add("André Martins", "112", 112, 'T');
    fifopre_add("Agatha da Paz", "113", 113, 'T');
    fifopre_add("Bruna Lima", "114", 114, 'T');
    fifopre_add("Henrique Correia", "115", 115, 'T');}