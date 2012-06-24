typedef struct client
{
    int codigo;
    char nome[31];
    char endereco[31];
    struct client *next;
    struct acoes *Acoes;
}a;

typedef struct acoes
{
    int codigo;
    char nome[31];
    int qtdeacoes;
    struct acoes *next;
}b;

