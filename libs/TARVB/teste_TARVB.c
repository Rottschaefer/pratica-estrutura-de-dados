#include "TARVB.h"
#include <stdio.h>

int main(){

    TARVB* arvb = inicializa();

    arvb = TARVB_insere(arvb, 25, 2);
    arvb = TARVB_insere(arvb, 10, 2);
    arvb = TARVB_insere(arvb, 12, 2);

    // printf("\n%p\n", arvb->filho[0]);

    TARVB_Imprime(arvb);
    return 0;
}