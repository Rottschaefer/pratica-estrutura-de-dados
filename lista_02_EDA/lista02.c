#include <stdlib.h>
#include <stdio.h>

typedef struct abb{
    int info;
    struct abb *esq, *dir;
}TABB;

typedef struct lse{
    int info;
    struct lse* prox;
}LSE;

LSE* cria_lista(){
    return NULL;
}

LSE* push_lista(LSE* lse, int n){

    LSE* l = lse;
    LSE* novo = (LSE*)malloc(sizeof(LSE));
    novo->info = n;
    novo->prox = NULL;

    if(!lse) return novo;

    while(l->prox) l = l->prox;

    l->prox = novo;

    return lse;
}

void print_lista(LSE* lse){
    while (lse) {
        printf(" %d ", lse->info);
        lse = lse->prox;
    }
    printf("\n");
    
}

int size_lista(LSE* lse){

    int size = 0;
    while (lse)
    {
        size++;
        lse = lse->prox;
    }
    
    return size;
}

TABB* cria_abb(){
    return NULL;
}

TABB* criar_node(int x){
    TABB* new_node = (TABB*)malloc(sizeof(TABB));
    new_node->info = x;
    new_node->esq = NULL;
    new_node->dir = NULL;

    return new_node;
}

TABB* inserir(TABB* abb, int x){

    if(!abb) return criar_node(x);

    if(x > abb->info) abb->dir = inserir(abb->dir, x);

    if(x < abb->info) abb->esq = inserir(abb->esq, x);
    
    return abb;
}

void print_aux(TABB* abb, int altura){

        if(!abb) {
            for (int i = 0; i < altura; i++) printf("\t");
            printf("N\n");
            return;
        }

        print_aux(abb->dir, altura+1);
        for (int i = 0; i < altura; i++) printf("\t");
        printf("%d\n\n", abb->info);
        print_aux(abb->esq, altura+1);
}

void print_abb(TABB* abb){
        print_aux(abb, 0);
}

int maior_elemento(TABB* abb){
    if(!abb->dir) return abb->info;

    return maior_elemento(abb->dir);
}

int menor_elemento(TABB* abb){
    if(!abb->esq) return abb->info;

    return menor_elemento(abb->esq);
}

TABB* retira(TABB* abb, int info){
    if(!abb) return abb;

    if(info < abb->info) {
        abb->esq = retira(abb->esq, info);
        return abb;
    }

    if(info > abb->info) {
        abb->dir = retira(abb->dir, info);
        return abb;
    }

    if(!abb->esq && !abb->dir){
        printf("\nCASO 1\n");
        free(abb);
        return NULL;
    }

    if(!abb->esq || !abb->dir){
        printf("\nCASO 2\n");
        TABB* temp[] = {abb->esq, abb->dir};
        free(abb);
        return temp[0] ? temp[0] : temp[1] ;
    }

    if(abb->esq && abb->dir){
        printf("\nCASO 3\n");

        TABB* filho = abb->esq;
        while (filho->dir) filho = filho->dir;
        abb->info = filho->info;
        filho->info = info;
        abb->esq = retira(abb->esq, info);
        return abb;
    }
}

TABB* retira_impares(TABB* abb){
    if(!abb) return NULL;


    abb->dir = retira_impares(abb->dir);
    abb->esq = retira_impares(abb->esq);

    if(abb->info % 2 != 0) return retira(abb, abb->info);


    return abb;
}

LSE* mN_aux(TABB* abb, int N, LSE* lse){

    if(!abb) return lse;

    if(abb->info < N) lse = push_lista(lse, abb->info);

    lse = mN_aux(abb->esq, N, lse);
    lse = mN_aux(abb->dir, N, lse);

    return lse;

}

int* mN(TABB*abb, int N){
    LSE* lse = NULL;
    lse = mN_aux(abb, N, lse);

    int lista_size = size_lista(lse);
    int* vet = (int*)malloc(sizeof(int)*lista_size);

    for (int i = 0; i < lista_size; i++)
    {   
        vet[i] = lse->info;
        lse = lse->prox;
    }
    
    return vet;
    
}


int main(){

    TABB* abb = cria_abb();
    LSE* lse = cria_lista();


    int vet[] = {10, 18, 15, 19, 5, 7, 3, 12,1};

    for (int i = 0; i < sizeof(vet)/sizeof(int); i++)
    {
        abb = inserir(abb, vet[i]);

    }


    int* menores = mN(abb, 18);



    for (int i = 0; menores[i]; i++)
    {
       printf(" %d ", menores[i]);
    }
    

    return 0;
}