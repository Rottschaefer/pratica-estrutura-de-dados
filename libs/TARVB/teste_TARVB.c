#include "TARVB.h"
#include <stdio.h>

int main(){

    TARVB* arvb = inicializa();

    for (int i = 0; i < 13; i ++)
    {
       arvb = TARVB_insere(arvb, i, 3);
    }

    // arvb = TARVB_insere(arvb, 99, 3);
    
    TARVB_retira(arvb, 6, 3);
    // TARVB_retira(arvb, 174, 3);
    // printf("\n\n\n%d", arvb->nchaves);

    // printf("\n%p\n", arvb->filho[0]);

    
    TARVB_Imprime(arvb);

    TARVB_libera(arvb);

    return 0;
}