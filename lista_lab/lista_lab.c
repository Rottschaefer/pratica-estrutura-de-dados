#include <stdio.h>
#include "../TAB/TAB.h"



int main(){

    int vetor[] = {42, 17, 93, 5, 61, 28, 74, 36, 9, 50, 83, 21, 47, 69, 12, 38, 95, 63, 7, 81};

    TAB* tab = cria_ab_from_vector(vetor, 0, (sizeof(vetor)/sizeof(vetor[0]))-1);

    // TAB_imp_ident(tab);


    int tam = sizeof(vetor)/sizeof(vetor[0]);

    int* res = mN(tab, 47, &tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", res[i]);
    }
    
    


    return 0;
}