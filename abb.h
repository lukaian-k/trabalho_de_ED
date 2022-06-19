#include <stdio.h>
#include <stdlib.h>


typedef struct vertice{
    //Dados iniciais da encomenda de um livro
    int id; //identificador
    char *nome_aluno;
    int matricula;
    char *descricao;
    
    //mecanismo p/ unir nos!
    struct vertice *esq;
    struct vertice *dir;
} Vertice;
Vertice *raiz = NULL;


Vertice *buscar(int id, Vertice *aux){
    if (aux != NULL){
        if (aux->id == id){
            return aux;}
            
        else if (id < aux->id){
            if (aux->esq != NULL){
                return buscar(id, aux->esq);}
            else {
                return aux;}}

        else if (id > aux->id){
            if (aux->dir != NULL){
                return buscar(id, aux->dir);}
            else {
                return aux;}}}
    else {
        return NULL;}}


void add_abb(int id, char *nome_aluno, int matricula, char *descricao){
    Vertice *aux = buscar(id, raiz);
    
    if (aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");}
    
    else {
        Vertice *novo = malloc(sizeof(Vertice));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL; novo->dir = NULL;
        
        if (aux == NULL){//arvore esta vazia
            raiz = novo;}
        
        else {
            if (id < aux->id){
                aux->esq = novo;}
            else {
                aux->dir = novo;}}}}


void in_ordem(Vertice *aux){
    if (aux->esq != NULL){
        in_ordem(aux->esq);}

    printf("%d\n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
    
    if (aux->dir != NULL){
        in_ordem(aux->dir);}}