typedef struct pedido { //struct do pedido
    int id; //identificador
    int prioridade; //de 0 à 100

    //informações para encomendar
    char *nome_aluno;
    int matricula;
    char *descricao;
    //informações para adiciona aos pedidos
    char *nome_responsavel;
    char *nome_campus_aluno;
    char *nome_campus_livro;
} Pedido;


typedef struct admin { //3 secretarios (cargo: S) e 5 transportadores (cargo: T)
    char *nome;
    char *senha;
    int cpf;
    char cargo;
} Admin;


typedef struct abb_node {
    //Dados iniciais da encomenda de um livro
    int id; //identificador

    char *nome_aluno;
    int matricula;
    char *descricao;
    
    //mecanismo p/ unir nos!
    struct abb_node *left; struct abb_node *right;
} Abb_node;


typedef struct fifop_node { //struct para os pedidos
    Pedido *pedido;

    //mecanismo p/ unir nos!
    struct fifop_node *next;
} Fifop_node;


typedef struct fifopre_node { //struct para os usuarios pre-cadastrados
    Admin *admin;

    //mecanismo p/ unir nos!
    struct fifopre_node *next;
} Fifopre_node;