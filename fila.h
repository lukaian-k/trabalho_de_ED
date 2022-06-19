#include <stdio.h>
#include <stdlib.h>


typedef struct pedido{
    int identificador;
    char *nome_aluno;
    //... demais dados
    int prioridade;
} Pedido;


typedef struct node{
    Pedido *p;
    //mecanismo p/ unir nos!
    struct node *prox;
} Node;
Node * inicio = NULL; Node * fim = NULL; int tam = 0;


void add_fila(int identificador, char *nome_aluno, int prioridade){
        Pedido *p = malloc(sizeof(Pedido));
        p->identificador = identificador;
        p->nome_aluno = nome_aluno;
        p->prioridade = prioridade;
        
        Node *novo = malloc(sizeof(Node));
        novo->p = p;
        novo->prox = NULL;
    
        if (inicio == NULL){ //fila vazia
            inicio = novo; fim = novo; tam++;}

        else { //adiciona de acordo com a prioridade! :D
            //modificar!
            fim->prox = novo;
            fim = novo; tam++;}}


void imprimir(){
    Node *aux = inicio;
    for (int i=0; i<tam; i++){
        printf("Identificador: %d\n", aux->p->identificador);
            aux = aux->prox;}}


Pedido remover_fila(){
    Pedido pedido;
        //remover!
        if (inicio != NULL){ //remover do antigo inicio da lista!
            Node *lixo = inicio;
            inicio = inicio->prox;
            pedido.identificador = lixo->p->identificador;
            //...
            free(lixo); tam--;
            
            if(tam == 1){
                fim = NULL;}}
    return pedido;}