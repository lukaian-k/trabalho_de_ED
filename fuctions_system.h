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

int verificar_senha(){
    //verificar o usuario
    char cpf[100]; char senha[100];

    printf(" Digite seu cpf:\n"); scanf("%s", &cpf);
    printf(" Digite sua senha:\n"); scanf("%s", &senha);
    
    //se o usuario e senha estiverem certos
    return 1;
    //se nao
    return 0;}


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


void remover_encomenda(){
    //remover uma encomenda de livro da ABB (id)
    //visualizar as encomendas
    in_ordem(root);
    
    int retorno = verificar_senha();
    if (retorno == 1){
        int selecionar_id;
        printf(" Digite o id da encomenda que deseja remover:\n"); scanf("%s", &selecionar_id);
        root = remover_abb(root, selecionar_id);

        //setar novos dados (faltando)
        char *nome_responsavel; char *nome_campus_aluno; char *nome_campus_livro;
        printf(" Digite o nome do responsavel:\n"); scanf(" %[^\n]s", nome_responsavel);
        printf(" Digite o nome do campus do aluno:\n"); scanf(" %[^\n]s", nome_campus_aluno);
        printf(" Digite o nome do campus do livro:\n"); scanf(" %[^\n]s", nome_campus_livro);
        //5 - add_fila(....);
    }}


void remover_pedido(){
    
}