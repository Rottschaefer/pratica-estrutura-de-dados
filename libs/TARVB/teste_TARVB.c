#include "TARVB.h"
#include <stdio.h>

int main(){

    TARVB* arvb = inicializa();

    arvb = TARVB_insere(arvb, 2, 2);
    arvb = TARVB_insere(arvb, 4, 2);
    arvb = TARVB_insere(arvb, 6, 2);
    arvb = TARVB_insere(arvb, 3, 2);
    arvb = TARVB_insere(arvb, 9, 2);
    arvb = TARVB_insere(arvb, 7, 2);
    arvb = TARVB_insere(arvb, 8, 2);
    arvb = TARVB_insere(arvb, 1, 2);
    arvb = TARVB_insere(arvb, 0, 2);
    arvb = TARVB_insere(arvb, 10, 2);

    printf("\n\n\n%d", arvb->nchaves);

    // printf("\n%p\n", arvb->filho[0]);

    TARVB_Imprime(arvb);
    return 0;
}