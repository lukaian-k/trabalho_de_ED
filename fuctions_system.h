//imports
#include <stdio.h>
#include <stdlib.h>
//files
#include "abb.h"
#include "fila_prioridade.h"
//#include "fila_pre_cadastrados.h"

//create variables
int add_esq_ou_dir = 0;


//fuctions

int gerador_id(){
    if (add_esq_ou_dir == 0){
        add_esq_ou_dir = 1;
        Abb_node *aux = buscar(0, root);

        if (aux != NULL && aux->id > 0){return aux->id/2;}
        for (int i=3; i<32; i++){
            aux = buscar(i, root);
            if (aux != NULL && aux->id != i){return i;}}}

    else {
        add_esq_ou_dir = 0;
        Abb_node *aux = buscar(64, root);
        
        if (aux != NULL && aux->id < 64){return 64-(64-aux->id)/2;}
        for (int i=61; i>32; i--){
            aux = buscar(i, root);
            if (aux != NULL && aux->id != i){return i;}}}}


void encomendar(){
    int id = gerador_id();
    
    Abb_node *new = malloc(sizeof(Abb_node));
    Abb_node *aux = buscar(id, root);
    

    if (aux != NULL && aux->id == id){printf("Insercao invalida!\n\n");}

    else {
        new->id = id;
            
        printf("Digite o nome do aluno:\n");
        char *nome_aluno = malloc(sizeof(char)); scanf(" %[^\n]s", nome_aluno);
        new->nome_aluno = nome_aluno;
            
        //... matricula e descricao.. Dados iniciais da encomenda de um livro
        printf("Digite a matricula do aluno:\n");
        int matricula; scanf("%d", &matricula);
        new->matricula = matricula;

        printf("Escreva a descricao do livro:\n");
        char *descricao = malloc(sizeof(char)); scanf(" %[^\n]s", descricao);
        new->descricao = descricao;

        new->left = NULL; new->right = NULL;
        add_abb(new, aux, id);}}


void remover_encomenda(){
    in_ordem(root);
    root = remover_abb(root, 0);}