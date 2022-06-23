#include <stdio.h>
#include <stdlib.h>


typedef struct pedido {
    int identificador;
    char *nome_aluno;
    //... demais dados
    int prioridade;
} Pedido;


typedef struct node_fifo {
    Pedido *p;
    //mecanismo p/ unir nos!
    struct node_fifo *prox;
} Node_fifo;
Node_fifo * inicio = NULL; Node_fifo *fim = NULL; int tam = 0;


void add_fila(int identificador, char *nome_aluno, int prioridade){
        Pedido *p = malloc(sizeof(Pedido));
        p->identificador = identificador;
        p->nome_aluno = nome_aluno;
        p->prioridade = prioridade;
        
        Node_fifo *novo = malloc(sizeof(Node_fifo));
        novo->p = p;
        novo->prox = NULL;
    
        if (inicio == NULL){ //fila vazia
            inicio = novo; fim = novo; tam++;}

        else { //adiciona de acordo com a prioridade! :D
            //modificar!
            fim->prox = novo;
            fim = novo; tam++;}}


void imprimir(){
    Node_fifo *aux = inicio;
    for (int i=0; i<tam; i++){
        printf("Identificador: %d\n", aux->p->identificador);
            aux = aux->prox;}}


Pedido remover_fila(){
    Pedido pedido;
        //remover!
        if (inicio != NULL){ //remover do antigo inicio da lista!
            Node_fifo *lixo = inicio;
            inicio = inicio->prox;
            pedido.identificador = lixo->p->identificador;
            //...
            free(lixo); tam--;
            
            if(tam == 1){
                fim = NULL;}} return pedido;}