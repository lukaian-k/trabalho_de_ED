//definindo cores (ANSI)
#define RESET "\033[0;0m"
#define BOLD "\033[;1m"
//fonts
#define FONT_WHITE "\033[1;97m"
#define FONT_GRAY "\033[1;37m"
#define FONT_BLACK "\033[1;30m"
#define FONT_RED "\033[1;31m"
#define FONT_BLUE "\033[1;34m"
#define FONT_GREEN "\033[1;32m"
//backgrounds
#define BACKGROUND_WHITE "\033[1;107m"
#define BACKGROUND_GRAY "\033[1;47m"
#define BACKGROUND_BLACK "\033[1;40m"
#define BACKGROUND_RED "\033[1;41m"
#define BACKGROUND_BLUE "\033[1;44m"
#define BACKGROUND_GREEN "\033[1;42m"


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
    Admin admin;

    //mecanismo p/ unir nos!
    struct fifopre_node *next;
} Fifopre_node;