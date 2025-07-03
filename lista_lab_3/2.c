#include "../libs/TARVB/TARVB.h"
#include "../libs/TLSEINT/TLSEINT.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void misc_aux(TLSEINT** lista, TARVB* a, int elem){
    if(!a) return;

    int pos_descida = 0;

    for (int i = 0; i < a->nchaves; i++)
    {
        if(a->chave[i] < elem){
            pos_descida = i +1;
        }

        else if(a->chave[i] == elem) return;
    }

    printf("pos_descida = %d\n", pos_descida);

    if(pos_descida == 0) *lista = TLSEINT_insere(*lista, INT_MIN, a->chave[pos_descida]);

    else if(pos_descida == a->nchaves) *lista = TLSEINT_insere(*lista, a->chave[pos_descida-1], INT_MAX);

    else *lista = TLSEINT_insere(*lista, a->chave[pos_descida-1], a->chave[pos_descida]);

    misc_aux(lista, a->filho[pos_descida], elem);

}

TLSEINT* misc(TARVB *a, int elem){
    TLSEINT* lista = NULL;

    misc_aux(&lista, a, elem);

    return lista;
    
    
}


int main(){

    TARVB* arvb = NULL;

    for (int i = 0; i < 30; i++)
    {
        arvb = TARVB_insere(arvb, i, 2);
    }

    TARVB_Imprime(arvb);

    TLSEINT* lista = misc(arvb, 8);

    TLSEINT_imprime(lista);
    printf("\n");
    
    return 0;
}