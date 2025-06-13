

typedef struct tarvb{
    int nchaves;
    int folha;
    int* chave;
    struct tarvb** filho;
}TARVB;

TARVB* inicializa();
TARVB* cria_no(int t);
TARVB* TARVB_insere(TARVB* arvb, int num, int t);
void TARVB_Imprime(TARVB* arvb);