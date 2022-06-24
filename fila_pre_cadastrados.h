//imports
#include <stdio.h>
#include <stdlib.h>


typedef struct temp {

} Temp;


typedef struct temp2 {

} Temp2;


typedef struct fifopre_node {

    //mecanismo p/ unir nos!
    struct fifopre_node *next;
} Fifopre_node;
Fifopre_node *fifopre_start = NULL; Fifopre_node *fifopre_last = NULL; int fifopre_tam = 0;


void fifopre_add(int identificador, char *nome_aluno, int prioridade){
        Pedido *p = malloc(sizeof(Pedido));
        p->identificador = identificador;
        p->nome_aluno = nome_aluno;
        p->prioridade = prioridade;
        
        Fifopre_node *novo = malloc(sizeof(Fifopre_node));
        novo->p = p;
        novo->next = NULL;
    
        if (fifopre_start == NULL){ //fila vazia
            fifopre_start = novo; fifopre_last = novo; fifopre_tam++;}

        else { //adiciona de acordo com a prioridade! :D
            //modificar!
            fifopre_last->next = novo;
            fifopre_last = novo; fifopre_tam++;}}


void fifopre_imprimir(){
    Fifopre_node *aux = fifopre_start;
    for (int i=0; i<fifopre_tam; i++){
        printf("Identificador: %d\n", aux->p->identificador);
            aux = aux->next;}}


Pedido fifopre_remover(){
    Pedido pedido;
        //remover!
        if (fifopre_start != NULL){ //remover do antigo inicio da lista!
            Fifopre_node *lixo = fifopre_start;
            fifopre_start = fifopre_start->next;
            pedido.identificador = lixo->p->identificador;
            //...
            free(lixo); fifopre_tam--;
            
            if(fifopre_tam == 1){
                fifopre_last = NULL;}} return pedido;}