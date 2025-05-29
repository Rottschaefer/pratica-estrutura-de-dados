

typedef struct tlse{
    int lim_inf, lim_sup;
    struct tlse * prox;
}TLSE;

TLSE* TLSE_inicializa();
TLSE* TLSE_insere_sup(TLSE* lse, int n);
TLSE* TLSE_insere_inf(TLSE* lse, int n);
void TLSE_print(TLSE* lse);

