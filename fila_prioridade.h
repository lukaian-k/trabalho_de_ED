//imports
#include <stdio.h>
#include <stdlib.h>


//structs
typedef struct pedido {
    int identificador; //id
    int prioridade; //de 0 à 100

    //informações ja existentes
    char *nome_aluno;
    int matricula;
    char *descricao;
    //novas informações
    char *nome_responsavel;
    char *nome_campus_aluno;
    char *nome_campus_livro;
} Pedido;


typedef struct fifop_node {
    Pedido *p;
    //mecanismo p/ unir nos!
    struct fifop_node *next;
} Fifop_node;
Fifop_node *fifop_start = NULL; Fifop_node *fifop_last = NULL; int fifop_tam = 0;


//fuctions

void add_fila(int identificador, int prioridade, char *nome_aluno, int matricula, char *descricao, char *nome_responsavel, char *nome_campus_aluno, char *nome_campus_livro){
        Pedido *p = malloc(sizeof(Pedido));
        p->identificador = identificador;
        p->prioridade = prioridade;
        p->nome_aluno = nome_aluno;
        p->matricula = matricula;
        p->descricao = descricao;
        p->nome_responsavel = nome_responsavel;
        p->nome_campus_aluno = nome_campus_aluno;
        p->nome_campus_livro = nome_campus_livro;
        
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