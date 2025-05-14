#include <stdio.h>
#include "../libs/TABB/TABB.h"



int main(){

    int vetor[] = {42, 17, 93, 5, 61, 28, 74, 36, 9, 50, 83, 21, 47, 69, 12, 38, 95, 63, 7, 81};

    TABB* tabb = TABB_inicializa();

    int tam = sizeof(vetor)/sizeof(vetor[0]);

    for (int i = 0; i < tam; i++)
    {
        tabb = TABB_insere(tabb, vetor[i]);
    }
    
    int* res = mN(tabb, 10, &tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", res[i]);
    }
    
    // TABB_imp_ident(tabb);

    return 0;
}