#include <stdio.h>
#include <stdlib.h>

typedef struct tavl{
    int info;
    int alt;
    struct tavl *esq, *dir;
}TAVL;

TAVL* criar_avl(){
    return NULL;
}

TAVL* criar_no(int x){
    TAVL* novo = (TAVL*)malloc(sizeof(TAVL));
    novo->info = x;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->alt = 0;

    return novo;
}

int altura(TAVL* avl){
    if(!avl) return -1;

    int alt_dir = altura(avl->dir);
    int alt_esq = altura(avl->esq);

    int alt = (alt_dir > alt_esq ? alt_dir : alt_esq);
    return 1 + alt;
}
static int calc_alt(TAVL *t){
    if(!t) return -1;
    return t->alt;
  }

int fb(TAVL* avl){
    int alt_dir, alt_esq;

    if(avl->esq) alt_esq = avl->esq->alt;
    else alt_esq = -1;
    if(avl->dir) alt_dir = avl->dir->alt;
    else alt_dir = -1;
    return alt_esq - alt_dir;
}

int max(int a, int b){
    return a>b? a:b;
}

TAVL* RSD(TAVL* avl){
    printf("\nRSD\n");
    TAVL* novo_root = avl->esq;
    avl->esq = novo_root->dir;
    novo_root->dir = avl;
    

    novo_root->alt = 1 + max(calc_alt(novo_root->dir), calc_alt(novo_root->esq));
    avl->alt = 1 + max(calc_alt(avl->dir), calc_alt(avl->esq));

    return novo_root;
}

TAVL* RSE(TAVL* avl){
    printf("\nRSE\n");

    TAVL* novo_root = avl->dir;
    avl->dir = novo_root->esq;
    novo_root->esq = avl;

    novo_root->alt = 1 + max(calc_alt(novo_root->esq), calc_alt(novo_root->dir));
    avl->alt = 1 + max(calc_alt(avl->esq), calc_alt(avl->dir));
    return novo_root;
}

TAVL* RED(TAVL* avl){
    printf("\nRED\n");

    avl->esq = RSE(avl->esq);

    avl = RSD(avl);

    return avl;

}

TAVL* RDE(TAVL* avl){
    printf("\nRDE\n");

    avl->dir = RSD(avl->dir);
    avl = RSE(avl);

    return avl;
}
TAVL* inserir(TAVL* avl, int x){
    if(!avl) return criar_no(x);

    if(x > avl->info) avl->dir = inserir(avl->dir, x);
        
    if(x < avl->info) avl->esq = inserir(avl->esq, x);

    // printf("\n\n%d\n\n", fb(avl));
    if(fb(avl)==2 && fb(avl->esq) >= 0) avl = RSD(avl);

    if(fb(avl)==-2 && fb(avl->dir) <= 0) avl = RSE(avl);

    if(fb(avl) == 2 && fb(avl->esq) < 0) avl = RED(avl);

    if(fb(avl) == -2 && fb(avl->dir) > 0) avl = RDE(avl);

    avl->alt = altura(avl);

    return avl;
}


TAVL* retira(TAVL* avl, int info){
    if(!avl) return NULL;

    if(avl->info != info){
        if(info > avl->info){
            avl->dir = retira(avl->dir, info);
        }
    
        if(info < avl->info){
            avl->esq = retira(avl->esq, info);
        }

        if(fb(avl)==2 && fb(avl->esq) >= 0) avl = RSD(avl);

        if(fb(avl)==-2 && fb(avl->dir) <= 0) avl = RSE(avl);

        if(fb(avl) == 2 && fb(avl->esq) < 0) avl = RED(avl);

        if(fb(avl) == -2 && fb(avl->dir) > 0) avl = RDE(avl);

        avl->alt = altura(avl);

        return avl;
    }
    



    if(!avl->esq && !avl->dir){
        printf("\nCASO 1\n");
        free(avl);
        return NULL;
    }

    if(!avl->esq || !avl->dir){
        printf("\nCASO 2\n");
        TAVL* temp[] = {avl->esq, avl->dir};
        free(avl);

        return temp[0]? temp[0] : temp[1];
    }

    if(avl->esq && avl->dir){
        printf("\nCASO 3\n");
        TAVL* filho = avl->esq;
        while(filho->dir) filho = filho->dir;

        avl->info = filho->info;
        filho->info = info;

        avl = retira(avl->esq, info);
        return avl;
    }
}



void print_aux(TAVL* avl, int altura){

    if(!avl) {
        for (int i = 0; i < altura; i++) printf("\t");
        printf("N\n");
        return;
    }

    print_aux(avl->dir, altura+1);
    for (int i = 0; i < altura; i++) printf("\t");
    printf("%d:alt %d\n\n", avl->info, avl->alt);
    print_aux(avl->esq, altura+1);
}

void print_avl(TAVL* avl){
    print_aux(avl, 0);
}


void free_avl(TAVL* avl){
    if(!avl) return;

    free_avl(avl->esq);
    free_avl(avl->dir);

    free(avl);
}
int main(){

    TAVL* avl = criar_avl();

    int vet[] = {1, 64, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 7, 60, 43, 16, 67, 34, 35};


    avl = inserir(avl, 50);

    for(int i=0; i<sizeof(vet)/sizeof(vet[0]);i++){
        avl = inserir(avl, vet[i]);
    }



    print_avl(avl);

    int vet_retira[] = {50, 95, 70, 60, 35, 39,34};

    for(int i = 0; i < sizeof(vet_retira)/sizeof(vet_retira[0]); i++){
        avl = retira(avl, vet_retira[i]);
    }

    print_avl(avl);

    free_avl(avl);

    return 0;
}