***TODOS AS FUNCIONALIDADES QUE FOREM NECESSARIAS UM PEDIDO DE SENHA, IRA PEDIR PARA QUE O CPF E A SENHA SEJA INFORMADA.***
***O SISTEMA DEVERAR POSSUIR PELO MENOS 3 SECRETARIOS (cargo: S) E 5 TRANSPORTADORES (cargo: T) FICTICIOS PRÉ-CADASTRADOS.***
***CADA PESSOA PRÉ-CADASTRADA DEVERAR POSSUIR: nome, cpf, senha e cargo.***

# 1 - Encomendar um livro.    //sem pedir senha
***DADOS:***
*id;*
*matricula do aluno;*
*nome do aluno;*
*descricao do livro.*

# 2 - Remover uma encomenda de livro.    //secretario - pedir senha
*visualizar todas as encomendas para saber qual remover.*
*deve remover pelo id.*
*o secretario ir ser o responsavel pela encomenda removida.*
*ele ira preencher informacoes adicionais sobre a encomenda.*
***DADOS:***
*nome do campus onde o livro se encontra;*
*nome do campus onde o alunos se encontra;*
*nome do responsavel pela encomenda;*
*prioriadade do pedido em uma escala de 0 à 100.*
*apos inserir os dados, o pedido deve ser inserido na fila de prioridade.*
*apos remover uma encomenda o secretario resposavel pela remoção ira ter o nome adicionado automaticamente pelo sistema no campo "nome do responsavel pela encomenda".*

# 3 - Remover um pedido de livro.    //transportadores - pedir senha
*qualquer um dos transportadores podera remover um documento da fila de pedidos de livros.*
*para remover um pedido de livro, é necessario que o transportador se identifique-se.*
*o pedido a ser removido sempre sera o de maior prioridade.*

# 0 - Sair do sistema! 


## RESUMÃO DO GIT

*branch - são as versões que você sobe do seu código*
*master  - é primeira versão (principal do código)*
*commit - envio de uma nova versão*

***como fazer um commit:***
*1- git add -A*
*2- git commit -m "texto com uma informação sobre a atualização realizada"*

*git status - mostrar quais arquivos foram adicionados ou alterados*
*git log - dados sobre commits realizados*
*git branch - apresenta qual a branch você se encontra*
*git checkout - utilizada para mudar de branch ou para voltar a um commit anterior*
*git diff - o que foi alterado depois do último commit*
