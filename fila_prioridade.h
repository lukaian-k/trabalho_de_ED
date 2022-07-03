//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "fila_pre_cadastrados.h"

//create variables
Fifop_node *fifop_start = NULL; Fifop_node *fifop_last = NULL; int fifop_tam = 0;


//fuctions

void add_fila(int id, int prioridade, char *nome_aluno, int matricula, char *descricao, char *nome_responsavel, char *nome_campus_aluno, char *nome_campus_livro){
        Pedido *pedido = malloc(sizeof(Pedido));
        pedido->id = id;
        pedido->prioridade = prioridade;
        pedido->nome_aluno = nome_aluno;
        pedido->matricula = matricula;
        pedido->descricao = descricao;
        pedido->nome_responsavel = nome_responsavel;
        pedido->nome_campus_aluno = nome_campus_aluno;
        pedido->nome_campus_livro = nome_campus_livro;
        
        Fifop_node *novo = malloc(sizeof(Fifop_node));
        novo->pedido = pedido;
        novo->next = NULL;
    
        if (fifop_start == NULL){ //fila vazia
            fifop_start = novo; fifop_last = novo; fifop_tam++;}

        //adiciona de acordo com a prioridade! :D
        else if(fifop_start->pedido->prioridade <= prioridade){
            novo->next = fifop_start;
            fifop_start = novo; fifop_tam++;}
        
        else {
            if (fifop_last->pedido->prioridade >= prioridade){
                fifop_last->next = novo;
                fifop_last = novo;}

            else {
                Fifop_node *aux = fifop_start;
                while (aux->next->pedido->prioridade <= prioridade){
                    aux = aux->next;}
                
                novo->next = aux->next;
                aux->next = novo;}
                
            fifop_tam++;}}


void imprimir(Fifop_node *aux){
    if (aux != NULL){
        printf(BOLD BACKGROUND_WHITE FONT_GREEN " Identificador: %d \n", aux->pedido->id);
        printf(FONT_BLUE " Nome do responsavel: %s \n", aux->pedido->nome_responsavel);
        printf(FONT_BLACK " Nome do aluno: %s \n", aux->pedido->nome_aluno);
        printf(" Matricula do aluno: %d \n", aux->pedido->matricula);
        printf(" Nome do campus do aluno: %s \n", aux->pedido->nome_campus_aluno);
        printf(" Descrição do livro: %s \n", aux->pedido->descricao);
        printf(" Campus onde o livro se encontra: %s \n", aux->pedido->nome_campus_livro);
        printf(FONT_RED " Prioridade do pedido: %d \n" RESET, aux->pedido->prioridade);
        printf(BOLD FONT_GREEN "-----------------------------\n" RESET);
        imprimir(aux->next);}}


Pedido *remover_fila(){
    Pedido *backup;
        //remover!
        if (fifop_start != NULL){ //remover do antigo inicio da lista!
            Fifop_node *lixo = fifop_start;
            fifop_start = fifop_start->next;
            backup = lixo->pedido;
            //...
            free(lixo); fifop_tam--;
            
            if(fifop_tam == 1){
                fifop_last = NULL;} return backup;}}