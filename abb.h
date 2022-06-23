#include <stdio.h>
#include <stdlib.h>


typedef struct node_abb {
    //Dados iniciais da encomenda de um livro
    int id; //identificador
    char *nome_aluno;
    int matricula;
    char *descricao;
    
    //mecanismo p/ unir nos!
    struct node_abb *left; struct node_abb *right;
} Node_abb; Node_abb *root = NULL;


Node_abb *buscar(int id, Node_abb *aux){
    if (aux != NULL){
        if (aux->id == id){return aux;}

        else if (aux->left != NULL && id < aux->id){return buscar(id, aux->left);}
        else if (aux->right != NULL && id > aux->id){return buscar(id, aux->right);}

        else {return aux;}}

    else {return NULL;}}


void add_abb(int id, char *nome_aluno, int matricula, char *descricao){
    Node_abb *aux = buscar(id, root);
    
    if (aux != NULL && aux->id == id){printf("Insercao invalida!\n");}

    else {
        Node_abb *novo = malloc(sizeof(Node_abb));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->left = NULL; novo->right = NULL;
        
        if (aux == NULL){root = novo;} //arvore esta vazia

        else {
            if (id < aux->id){aux->left = novo;}
            
            else {aux->right = novo;}}}}


Node_abb *remover_abb(Node_abb *root, int id){
    if (root == NULL){return NULL;}

    else {
        if (root->left, root->right == NULL){ //remove nós, caso nao tenha filhos
            free(root); printf("Elemento removido!\n"); return NULL;}

        else { //remove nós, caso tenha 1 ou 2 filhos
            if (root->left, root->right != NULL){ //com 2 filhos
                Node_abb *aux = root->left;
                while (aux->right != NULL){
                    aux = aux->right;}

                root->id = aux->id;
                aux->id = id;

                root->left = remover_abb(root->left, id); return root;}

            else { //com 1 filho
                Node_abb *aux;

                if (root->left != NULL){aux = root->left;}
                else {aux = root->right;}

                free(root); return aux;}}}}


void in_ordem(Node_abb *aux){
    if (aux->left != NULL){in_ordem(aux->left);}

    printf("%d\n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
    
    if (aux->right != NULL){in_ordem(aux->right);}}