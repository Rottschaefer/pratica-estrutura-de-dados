#include "TARVB.h"
#include <stdio.h>

int main(){

    TARVB* arvb = inicializa();

    for (int i = 0; i < 102; i++)
    {
       arvb = TARVB_insere(arvb, i, 3);
    }
    

    // printf("\n\n\n%d", arvb->nchaves);

    // printf("\n%p\n", arvb->filho[0]);

    
    TARVB_Imprime(arvb);

    return 0;
}