#include <stdio.h>
#include <stdlib.h>

typedef struct tlse{
    int info;
    void* prox;
}TLSE;

void* cria_tlse(){
    return NULL;
}

void* push_lista(void* l, int k){

    TLSE* novo_item = malloc(sizeof(TLSE));

    novo_item->info = k;
    novo_item->prox= NULL;

    if(!l) return novo_item;

    TLSE* p = l;
    while(p->prox!=NULL){
        p=p->prox;
    }

    

    p->prox = novo_item;

    return l;
}

int pop_lista(TLSE* l){
    TLSE* ant = l;
    
    while(l->prox!=NULL){
        ant = l;
        l=l->prox;
    }

    ant->prox = NULL;

    int k = l->info;

    free(l);

    return k;
}

void print_lista(TLSE* l){
    while (l)
    {
        printf("%d\n", l->info);
        l=l->prox;
    }
    
}

int main(){

    void* lse = cria_tlse();

    for (int i = 0; i < 10; i++)
    {
        lse = push_lista(lse, i);
    }

    printf("\nNumero tirado: %d\n\n", pop_lista(lse));
    printf("\nNumero tirado: %d\n\n", pop_lista(lse));
    printf("\nNumero tirado: %d\n\n", pop_lista(lse));
    printf("\nNumero tirado: %d\n\n", pop_lista(lse));
    
    print_lista(lse);
    return 0;
}