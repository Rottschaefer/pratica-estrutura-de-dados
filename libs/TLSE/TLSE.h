

typedef struct tlse{
    int info;
    struct tlse * prox;
}TLSE;

TLSE* TLSE_inicializa();
TLSE* TLSE_insere_inicio(TLSE* lse, int n);
TLSE* TLSE_busca(TLSE* lse, int n);
void TLSE_print(TLSE* lse);
int TLSE_conta(TLSE* l);

