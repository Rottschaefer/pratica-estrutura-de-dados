#include "../libs/TARVB/TARVB.h"
#include "../libs/TLSE/TLSE.h"
#include <stdlib.h>
#include <stdio.h>

void mN_aux(TLSE** lista, TARVB* arvb, int N){
    if(!arvb) return;

    // printf("Analisando elemento: %d\n", arvb->chave[0]);
    // printf("Imprimindo estado atual lista: \n");
    // TLSE_print(*lista);
    // printf("\n");


    int i = 0;
    int pos_descida = -1;
    for (i = 0; i < arvb->nchaves; i++)
    {
        if(arvb->chave[i] > N) {
            
            *lista = TLSE_insere_inicio(*lista, arvb->chave[i]);
            if(pos_descida == -1) pos_descida = i;
        }
    }

    if(pos_descida == -1) return mN_aux(lista, arvb->filho[arvb->nchaves], N);

    for (int i = pos_descida; i <= arvb->nchaves; i++)
    {
        mN_aux(lista, arvb->filho[i], N);
    }
    
    

}

TLSE* mN(TARVB*a, int N){
    TLSE* lista = NULL;

    mN_aux(&lista, a, N);

    return lista;
}


int main(){

    TARVB* arvb = NULL;

    for (int i = 0; i < 10; i++)
    {
        arvb = TARVB_insere(arvb, i, 2);
    }

    // TARVB_Imprime(arvb);

    TLSE* lista = mN(arvb, 5);

    TLSE_print(lista);
    
    return 0;
}