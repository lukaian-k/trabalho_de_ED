//imports
#include <stdio.h>
#include <stdlib.h>


//structs
typedef struct pedido {
    int identificador;
    char *nome_aluno;
    //... demais dados
    int prioridade;
} Pedido;


typedef struct fifop_node {
    Pedido *p;
    //mecanismo p/ unir nos!
    struct fifop_node *next;
} Fifop_node;
Fifop_node *fifop_start = NULL; Fifop_node *fifop_last = NULL; int fifop_tam = 0;


//fuctions

void add_fila(int identificador, char *nome_aluno, int prioridade){
        Pedido *p = malloc(sizeof(Pedido));
        p->identificador = identificador;
        p->nome_aluno = nome_aluno;
        p->prioridade = prioridade;
        
        Fifop_node *novo = malloc(sizeof(Fifop_node));
        novo->p = p;
        novo->next = NULL;
    
        if (fifop_start == NULL){ //fila vazia
            fifop_start = novo; fifop_last = novo; fifop_tam++;}

        //adiciona de acordo com a prioridade! :D
        else if(fifop_start->p->prioridade < prioridade){
            novo->next = fifop_start;
            fifop_start = novo; fifop_tam++;}
        
        else {
            if (fifop_last->p->prioridade > prioridade){
                fifop_last->next = novo;
                fifop_last = novo;}

            else {
                Fifop_node *aux = fifop_start;
                while (aux->next->p->prioridade < prioridade){
                    aux = aux->next;}
                
                novo->next = aux->next;
                aux->next = novo;}
                
            fifop_tam++;}}


void imprimir(){
    Fifop_node *aux = fifop_start;
    for (int i=0; i<fifop_tam; i++){
        printf("Identificador: %d\n", aux->p->identificador);
            aux = aux->next;}}


Pedido remover_fila(){
    Pedido pedido;
        //remover!
        if (fifop_start != NULL){ //remover do antigo inicio da lista!
            Fifop_node *lixo = fifop_start;
            fifop_start = fifop_start->next;
            pedido.identificador = lixo->p->identificador;
            //...
            free(lixo); fifop_tam--;
            
            if(fifop_tam == 1){
                fifop_last = NULL;}} return pedido;}