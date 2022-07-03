//imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//file
#include "abb.h"

//create variables
int add_esq_ou_dir = 0;


//fuctions

void quit(char *text){
    while (getchar() != 'q'){printf(RESET BOLD BACKGROUND_WHITE FONT_RED "\n\nPressione: q, para %s: ", text);} printf(RESET "\n");}


Fifopre_node *verificar_senha(Fifopre_node *aux, char cargo){
    int cpf; char senha[100];
    printf(BOLD BACKGROUND_BLUE FONT_WHITE "\n<<<Login>>>" RESET);

    printf(BACKGROUND_WHITE FONT_BLACK "\n Digite seu cpf: "); scanf("%d", &cpf);

    for (int i=0; i<fifopre_tam; i++){
        if (cargo == aux->admin.cargo && cpf == aux->admin.cpf){
            printf(" Digite sua senha: "); scanf(" %[^\n]s", &senha);

            if (strcasecmp(senha, aux->admin.senha) == 0){
                printf(BOLD FONT_GREEN "\nSenha correta!\n\n" RESET); return aux;}

            else {printf(BOLD FONT_RED "\nSenha incorreta!\n\n" RESET); return NULL;}}
        aux = aux->next;}

    printf(BOLD FONT_RED "\nNão há nenhum usuario cadastrado com esse CPF que possa usar essa função.\n\n" RESET); return 0;}


int gerador_id(){
    if (add_esq_ou_dir == 0){
        add_esq_ou_dir = 1;
        Abb_node *aux = buscar(0, root);

        if (aux != NULL && aux->id > 0){return aux->id/2;}

        for (int i=32; i>5; i-=2){
            aux = buscar(i, root);
            if (aux != NULL && aux->id != i){return i;}}
        for (int i=31; i>2; i-=2){
            aux = buscar(i, root);
            if (aux != NULL && aux->id != i){return i;}}}

    else {
        add_esq_ou_dir = 0;
        Abb_node *aux = buscar(64, root);
        
        if (aux != NULL && aux->id < 64){return 64-(64-aux->id)/2;}

        for (int i=32; i<59; i+=2){
            aux = buscar(i, root);
            if (aux != NULL && aux->id != i){return i;}}
        for (int i=33; i<62; i+=2){
            aux = buscar(i, root);
            if (aux != NULL && aux->id != i){return i;}}}}


void encomendar(){
    int id = gerador_id();
    
    Abb_node *new = malloc(sizeof(Abb_node));
    Abb_node *aux = buscar(id, root);
    
    if (aux != NULL && aux->id == id){printf(BOLD BACKGROUND_WHITE FONT_RED "\n Insercao invalida! \n\n" RESET);}

    else {
        printf(BOLD BACKGROUND_BLUE FONT_WHITE "<<<Encomendar>>>\n" RESET);
        new->id = id;
            
        printf(BACKGROUND_WHITE FONT_BLACK " Digite o nome do aluno: ");
        char *nome_aluno = malloc(sizeof(char)); scanf(" %[^\n]s", nome_aluno);
        new->nome_aluno = nome_aluno;
            
        //... matricula e descricao.. Dados iniciais da encomenda de um livro
        printf(" Digite a matricula do aluno: ");
        int matricula; scanf("%d", &matricula);
        new->matricula = matricula;

        printf(" Escreva a descricao do livro: ");
        char *descricao = malloc(sizeof(char)); scanf(" %[^\n]s", descricao);
        new->descricao = descricao;

        new->left = NULL; new->right = NULL;
        add_abb(new, aux, id);
        
        printf(BOLD BACKGROUND_GREEN FONT_WHITE " Encomenda realizada! \n" RESET);}}


//remover uma encomenda de livro da ABB (id)
void remover_encomenda(){
    Fifopre_node *admin = verificar_senha(fifopre_start, 'S');

    if (admin != NULL){
        //visualizar as encomendas
        printf(RESET BOLD BACKGROUND_GREEN FONT_WHITE "\n<<<Exibindo pedidos>>>\n" RESET); in_ordem(root);

        //create variables
        int selecionar_id; Abb_node *backup = malloc(sizeof(Abb_node));
        printf(RESET BOLD BACKGROUND_BLUE FONT_WHITE "\n<<<Remover encomenda>>>\n" RESET);
        
        printf(BACKGROUND_WHITE FONT_BLUE " Digite o id da encomenda que deseja remover: "); scanf("%d", &selecionar_id);

        root = remover_abb(root, selecionar_id, backup);
        if (backup->id == selecionar_id){
            //setar novos dados (faltando)
            printf(BACKGROUND_WHITE FONT_BLACK " Digite o nome do campus do aluno: ");
            char *nome_campus_aluno = malloc(sizeof(char)); scanf(" %[^\n]s", nome_campus_aluno);
            
            printf(" Digite o nome do campus do livro: ");
            char *nome_campus_livro = malloc(sizeof(char)); scanf(" %[^\n]s", nome_campus_livro);

            printf(FONT_GREEN " Informe a prioridade do pedido (0 à 100): ");
            int prioriadade; scanf("%d", &prioriadade);
            
            add_fila(backup->id, prioriadade, backup->nome_aluno, backup->matricula, backup->descricao, admin->admin.nome, nome_campus_aluno, nome_campus_livro);
            
            printf(BOLD BACKGROUND_GREEN FONT_WHITE " Encomenda removida! " RESET);}
        else {printf(BOLD FONT_RED "\nNão foi possivel remover! Selecione uma opção valida.\n" RESET);}}}


void remover_pedido(){
    //verificar o usuario
    Fifopre_node *admin = verificar_senha(fifopre_start, 'T');

    if (admin != NULL){
        printf(RESET BOLD BACKGROUND_BLUE FONT_WHITE "\n<<<Remover encomenda>>>\n" RESET);
        //remover da fila de prioridade
        Pedido *backup = remover_fila();
        printf(BOLD BACKGROUND_WHITE FONT_GREEN "O pedido de ID: %d foi removido!", backup->id);}}