#include "TLSE.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

TLSE* TLSE_inicializa(){
    return NULL;
}




TLSE* TLSE_insere_inicio(TLSE* lse, int n) {
    TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
    if (!novo) return lse;
    novo->info = n;
    novo->prox = lse;
    return novo;
}

TLSE* TLSE_busca(TLSE* lse, int n) {
    while (lse) {
        if (lse->info == n) return lse;
        lse = lse->prox;
    }
    return NULL;
}

void TLSE_print(TLSE* lse) {
    while (lse) {
        printf("%d\n", lse->info);
        lse = lse->prox;
    }
}

int TLSE_conta(TLSE* l){
    if(!l) return 0;
    return 1 + TLSE_conta(l->prox);
}