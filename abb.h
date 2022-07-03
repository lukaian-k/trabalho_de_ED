//imports
#include <stdio.h>
#include <stdlib.h>
//file
#include "fila_prioridade.h"

//create variables
Abb_node *root = NULL;


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


Abb_node *remover_abb(Abb_node *root, int id, Abb_node *backup){
    if (root == NULL){
        printf(BOLD BACKGROUND_WHITE FONT_RED "Valor nao encontrado!\n" RESET); return NULL;}

    else { //procura o nó a remover
        if (root->id == id){ //remove nós, caso nao tenha filhos
            backup->id = id;
            backup->nome_aluno = root->nome_aluno;
            backup->matricula = root->matricula;
            backup->descricao = root->descricao;

            if (root->left == NULL && root->right == NULL){
                free(root); return NULL;}

            else { //remove nós, caso tenha 1 ou 2 filhos
                if (root->left != NULL && root->right != NULL){ //com 2 filhos
                    Abb_node *aux = root->left;

                    while (aux->right != NULL){
                        aux = aux->right;}

                    root->id = aux->id;
                    aux->id = id;

                    root->left = remover_abb(root->left, id, backup);
                    return root;}

                else { //com 1 filho
                    Abb_node *aux;
                    if (root->left != NULL){aux = root->left;}
                    else {aux = root->right;}

                    free(root); return aux;}}}

        else {
            backup->id = -1;
            if (id < root->id){root->left = remover_abb(root->left, id, backup);}
            else {root->right = remover_abb(root->right, id, backup);} return root;}}}


void in_ordem(Abb_node *aux){
    if (aux != NULL){
        if (aux->left != NULL){in_ordem(aux->left);}

        printf(BOLD BACKGROUND_BLUE "<<<ENCOMENDA>>> ID:");
        printf(FONT_GREEN " %d \n" RESET, aux->id);
        printf(BACKGROUND_WHITE FONT_BLACK " Nome do aluno: %s \n", aux->nome_aluno);
        printf(" Matricula do aluno: %d \n", aux->matricula);
        printf(" Descrição do livro: %s \n" RESET, aux->descricao);
        printf(BOLD FONT_BLUE "-----------------------\n" RESET);
        
        if (aux->right != NULL){in_ordem(aux->right);}}
    
    else {printf(BOLD BACKGROUND_WHITE FONT_RED "\n Não foi encontrada nenhuma encomenda pendente. \n" RESET);}}


void node_imprimir(int id, int espaco) { //funcao aux da: abb_exibir_estrutura
    for (int i=0; i<espaco; i++){printf("  ");}
    printf("(%d)\n", id);}
//exibe a estrutura da abb de forma grafica
void abb_exibir_estrutura(Abb_node *node, int espaco) {
    if (node == NULL) {
        printf(FONT_RED);
        node_imprimir(-1, espaco); return;}

    abb_exibir_estrutura(node->right, espaco+1);
    printf(FONT_GREEN); node_imprimir(node->id, espaco);
    abb_exibir_estrutura(node->left, espaco+1);}