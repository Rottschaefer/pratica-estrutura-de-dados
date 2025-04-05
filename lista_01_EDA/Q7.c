#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ab{
    int cor;
    struct ab *esq, *dir;
}TAB;

TAB* inicializa_ab(){
    return NULL;
}

TAB* cria_node_sem_cor(int k, TAB *esq, TAB *dir){
    TAB* node = (TAB*)malloc(sizeof(TAB));
    node -> cor = k;
    node -> esq = esq;
    node -> dir = dir;

    return node;
}

TAB* inserir_sem_cor(TAB* ab, int k){

    if(!ab){
        return cria_node_sem_cor(k, NULL, NULL);
    }

    if(k > ab->cor) ab->dir = inserir_sem_cor(ab->dir, k);

    else ab->esq = inserir_sem_cor(ab->esq, k);

    return ab;
}


void print_ab(TAB* ab){
    if(ab){
        printf("%d\n\n", ab->cor);
        print_ab(ab->esq);
        print_ab(ab->dir);
    }
}

void free_arvore(TAB* ab){
    if(!ab){
        return;
    }

    free_arvore(ab->esq);
    free_arvore(ab->dir);

    free(ab);
}

void colore(TAB* ab){
    if(ab){

        if(ab->esq) ab->esq->cor = ((ab->cor) == 44) ? 45 : 44;
        if(ab->dir) ab->dir->cor = ((ab->cor) == 44) ? 45 : 44;

        colore(ab->esq);
        colore(ab->dir);
    }
}

int ni(TAB* ab){
    if(!ab) return 0;
    return 1 + ni(ab->esq) + ni(ab->dir);
}

int nf(TAB *ab){
    if(!ab) return 0;
    if(ab->esq == NULL && ab->dir == NULL) return 1;
    

    return nf(ab->esq) + nf(ab->dir);
}

int main(){

    TAB* ab = inicializa_ab();

    int vet[] = {50, 30, 40, 35, 45, 20, 100, 75, 120};

    for (int i = 0; i < sizeof(vet)/sizeof(int); i++)
    {
        ab = inserir_sem_cor(ab, vet[i]);
    }

    ab->cor = 44;
    print_ab(ab);

    printf("\n%d\n", nf(ab));

    free_arvore(ab);
    return 0;
}