#include <stdio.h>
#include <limits.h>
#include "../libs/TAB/TAB.h"
#include "../libs/TLSE/TLSE.h"

void misc_aux(TAB* ab, TLSE** lse, int n){
    if(!ab) return;

    if(ab->info == n) return;

    if(ab->info < n) *lse = TLSE_insere_inf(*lse, ab->info);
    else *lse = TLSE_insere_inf(*lse, ab->info);

    if(TAB_busca(ab->esq, n)) misc_aux(ab->esq, lse, n);
    else misc_aux(ab->dir, lse, n);

}

TLSE* misc(TAB* ab, int n){
    if(!ab) return NULL;

    if(!TAB_busca(ab, n)) return NULL; //Nó não existe

    TLSE* lse = TLSE_inicializa();


    misc_aux(ab, &lse, n);

    return lse;

}




int main(){

    int vet[] = {-2, 4, 1, 2, -14, 3, 8, 7, 5, -1, 9};

    TAB* ab = cria_ab_from_vector(vet, 0 , sizeof(vet)/sizeof(vet[0])-1);

    TAB_imp_ident(ab);

    TLSE* lse = misc(ab, 0);

    TLSE_print(lse);

    

    //LIBERA TUDO
    return 0;
}