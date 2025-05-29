#include "TLSE.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

TLSE* TLSE_inicializa(){
    return NULL;
}

TLSE* TLSE_cria(){
    TLSE* new = (TLSE*)malloc(sizeof(TLSE));

    new->lim_inf = INT_MIN;
    new->lim_sup = INT_MAX;
    new->prox = NULL;

    return new;
}


TLSE* TLSE_insere_sup(TLSE* lse, int n){

    TLSE* new = TLSE_cria();
    new->lim_sup = n;
    new->prox = lse;
    return new;
}

TLSE* TLSE_insere_inf(TLSE* lse, int n){

    TLSE* new = TLSE_cria();
    new->lim_inf = n;
    new->prox = lse;
    return new;
}

void TLSE_print(TLSE* lse){
    if(lse){
        printf("lim_sup: %d - lim_inf: %d\n", lse->lim_sup, lse->lim_inf);
        TLSE_print(lse->prox);
    }
}
