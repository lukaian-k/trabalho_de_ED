//imports
#include <stdio.h>
#include <stdlib.h>


//struct
typedef struct abb_node {
    //Dados iniciais da encomenda de um livro
    int id; //identificador

    char *nome_aluno;
    int matricula;
    char *descricao;
    
    //mecanismo p/ unir nos!
    struct abb_node *left; struct abb_node *right;
} Abb_node; Abb_node *root = NULL;


//fuctions

Abb_node *buscar(int id, Abb_node *aux){
    if (aux != NULL){
        if (aux->id == id){return aux;}

        else if (aux->left != NULL && id < aux->id){return buscar(id, aux->left);}
        else if (aux->right != NULL && id > aux->id){return buscar(id, aux->right);}

        else {return aux;}}

    else {return NULL;}}


void add_abb(Abb_node *new, Abb_node *aux, int id){
        if (aux == NULL){
            new->id = 32; root = new;} //arvore esta vazia

        else {
            if (id < aux->id){aux->left = new;}
            else {aux->right = new;}}}


Abb_node *remover_abb(Abb_node *root, int id){
    if (root == NULL){return NULL;}

    else {
        if (root->left, root->right == NULL){ //remove nós, caso nao tenha filhos
            free(root); printf("Elemento removido!\n\n"); return NULL;}

        else { //remove nós, caso tenha 1 ou 2 filhos
            if (root->left, root->right != NULL){ //com 2 filhos
                Abb_node *aux = root->left;
                while (aux->right != NULL){
                    aux = aux->right;}

                root->id = aux->id;
                aux->id = id;

                root->left = remover_abb(root->left, id); return root;}

            else { //com 1 filho
                Abb_node *aux;

                if (root->left != NULL){aux = root->left;}
                else {aux = root->right;}

                free(root); return aux;}}}}


void in_ordem(Abb_node *aux){
    if (aux != NULL){
        if (aux->left != NULL){in_ordem(aux->left);}

        printf("===ENCOMENDA=== ID: ");
        printf("%d\n", aux->id);
        printf("%s\n", aux->nome_aluno);
        printf("%d\n", aux->matricula);
        printf("%s\n", aux->descricao);
        printf("===============\n\n");
        
        if (aux->right != NULL){in_ordem(aux->right);}}
    
    else {printf("Não foi encontrada nenhuma encomenda pendente.\n\n");}}
