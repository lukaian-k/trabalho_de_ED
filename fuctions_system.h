//imports
#include <stdio.h>
#include <stdlib.h>
//files
#include "abb.h"
#include "fila_prioridade.h"
//#include "fila_pre_cadastrados.h"


void encomendar(){
    printf(" Digite o nome do aluno:\n");
    char *nome = malloc(sizeof(char)); scanf(" %[^\n]s", nome);

    //... matricula e descricao.. Dados iniciais da encomenda de um livro
    printf(" Digite a matricula do aluno:\n");
    int matricula = malloc(sizeof(int)); scanf("%d", &matricula);
    printf(" Escreva a descricao do livro:\n");
    char *descricao = malloc(sizeof(char)); scanf(" %[^\n]s", descricao);
    
    //criar um funcao para gerar id unico (:D)
    int id = 0;

    add_abb(id, nome, matricula, descricao);}