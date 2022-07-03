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
        else if(fifop_start->pedido->prioridade < prioridade){
            novo->next = fifop_start;
            fifop_start = novo; fifop_tam++;}
        
        else {
            if (fifop_last->pedido->prioridade > prioridade){
                fifop_last->next = novo;
                fifop_last = novo;}

            else {
                Fifop_node *aux = fifop_start;
                while (aux->next->pedido->prioridade < prioridade){
                    aux = aux->next;}
                
                novo->next = aux->next;
                aux->next = novo;}
                
            fifop_tam++;}}


void imprimir(Fifop_node *aux){
    if (aux != NULL){
        printf("Identificador: %d\n", aux->pedido->id);
        imprimir(aux->next);}}


Pedido remover_fila(){
    Pedido pedido;
        //remover!
        if (fifop_start != NULL){ //remover do antigo inicio da lista!
            Fifop_node *lixo = fifop_start;
            fifop_start = fifop_start->next;
            pedido.id = lixo->pedido->id;
            //...
            free(lixo); fifop_tam--;
            
            if(fifop_tam == 1){
                fifop_last = NULL;}} return pedido;}