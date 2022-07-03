//imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//file
#include "abb.h"

//create variables
int add_esq_ou_dir = 0;


//fuctions

void quit(){
    while (getchar() != 'q'){printf("\n\nPressione: q, para sair: ");};}


Fifopre_node *verificar_senha(Fifopre_node *aux, char cargo){
    int cpf; char senha[100];

    printf("\nDigite seu cpf: "); scanf("%d", &cpf);

    for (int i=0; i<fifopre_tam; i++){
        if (cargo == aux->admin.cargo && cpf == aux->admin.cpf){
            printf("\nDigite sua senha: "); scanf(" %[^\n]s", &senha);

            if (strcasecmp(senha, aux->admin.senha) == 0){
                printf("\nSenha correta!\n\n"); return aux;}

            else {printf("\nSenha incorreta!\n\n"); return NULL;}}
        aux = aux->next;}

    printf("\nNão há nenhum usuario cadastrado com esse CPF que possa usar essa função."); return 0;}


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


//remover uma encomenda de livro da ABB (id)
void remover_encomenda(){
    //visualizar as encomendas
    in_ordem(root);
    Fifopre_node *admin = verificar_senha(fifopre_start, 'S');

    if (admin != NULL){
        //create variables
        int selecionar_id; Abb_node *backup = malloc(sizeof(Abb_node));
        
        printf(" Digite o id da encomenda que deseja remover:\n"); scanf("%d", &selecionar_id);

        root = remover_abb(root, selecionar_id, backup);
        if (backup != NULL){
            //setar novos dados (faltando)
            printf("Digite o nome do campus do aluno:\n");
            char *nome_campus_aluno = malloc(sizeof(char)); scanf(" %[^\n]s", nome_campus_aluno);
            
            printf("Digite o nome do campus do livro:\n");
            char *nome_campus_livro = malloc(sizeof(char)); scanf(" %[^\n]s", nome_campus_livro);

            printf("Informe a prioridade do pedido (0 à 100):\n");
            int prioriadade; scanf("%d", &prioriadade);
            
            add_fila(backup->id, prioriadade, backup->nome_aluno, backup->matricula, backup->descricao, admin->admin.nome, nome_campus_aluno, nome_campus_livro);}}
    
    else {
        printf("\nSenha incorreta!\n\n");}}


void remover_pedido(){
    //verificar o usuario
    if (verificar_senha(fifopre_start, 'T') != NULL){
        //remover da fila de prioridade
        remover_fila();}}