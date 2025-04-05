#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;

TAB* inicializa_ab(){
    return NULL;
}

TAB* cria_node(int raiz, TAB *esq, TAB *dir){
    TAB* node = (TAB*)malloc(sizeof(TAB));
    node -> info = raiz;
    node -> esq = esq;
    node -> dir = dir;

    return node;
}

TAB* inserir(TAB* ab, int k){

    if(!ab){
        return cria_node(k, NULL, NULL);
    }

    if(k > ab->info) ab->dir = inserir(ab->dir, k);

    else ab->esq = inserir(ab->esq, k);

    return ab;
}

TAB* copia_arvore(TAB *ab){

    if(!ab){
        return NULL;
    }
    
    TAB* new_node = cria_node(ab->info, NULL, NULL);

    new_node->esq = copia_arvore(ab->esq);
    new_node->dir = copia_arvore(ab->dir);

    return new_node;
}

void print_ab(TAB* ab){
    if(!ab){
        return;
    }

    printf("%d\n", ab->info);
    print_ab(ab->esq);
    print_ab(ab->dir);
}

void free_arvore(TAB* ab){
    if(!ab){
        return;
    }

    free_arvore(ab->esq);
    free_arvore(ab->dir);

    free(ab);
}

TAB* espelho(TAB* ab){
    if(ab){
        TAB* temp = ab->dir;
        ab->dir = ab->esq;
        ab->esq = temp;

        espelho(ab->dir);
        espelho(ab->esq);

        return ab;
    }

    return NULL;
}

int maior_aux(TAB*ab, int maior){

    if(!ab) return maior;

    if(ab->info > maior) maior = ab->info;

    int maior_esquerda = maior_aux(ab->esq, maior);
    int maior_direita = maior_aux(ab->dir, maior);

    if(maior_esquerda > maior_direita) return maior_esquerda;
    else return maior_direita;
}

int maior_elemento(TAB* ab){

    if(!ab) return INT_MIN;

    return maior_aux(ab, ab->info);

}

int menor_elemento(TAB* ab){

    if(!ab) return INT_MAX;

    int menor_esquerda = menor_elemento(ab->esq);
    int menor_direita = menor_elemento(ab->dir);

    int menor_total = (menor_esquerda < menor_direita)? menor_esquerda : menor_direita;

    return (ab->info < menor_total)? ab->info : menor_total;
}

int igual (TAB* a1, TAB* a2){
    if(a1 == NULL && a2 == NULL) return 1;
    else if((a1 && a2) && a1->info == a2->info) return (igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir));
    else return 0;  
}

// TAB* retira_pares (TAB* ab){
//     if(!ab) return ab;



// }

int main(){

    TAB* ab = inicializa_ab();
    
    int vet[] = {42, -54, 89, 23, 165, 11, 58, 36, -74, 90};

    for (int i = 0; i < sizeof(vet)/sizeof(int); i++)
    {
        ab = inserir(ab, vet[i]);
    }
    
    TAB* new_ab = copia_arvore(ab);
    // new_ab = inserir(new_ab, 197780);
    
    printf("\n\n%d\n\n", igual(ab, new_ab));

    free_arvore(ab);
    return 0;
}