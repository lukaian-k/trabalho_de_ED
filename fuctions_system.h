//imports
#include <stdio.h>
#include <stdlib.h>
//files
#include "abb.h"
#include "fila_prioridade.h"
//#include "fila_pre_cadastrados.h"


void encomendar(){
    //criar um funcao para gerar id unico (:D)
    int id = 0;

    Abb_node *aux = buscar(id, root);
    Abb_node *new = malloc(sizeof(Abb_node));
        
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