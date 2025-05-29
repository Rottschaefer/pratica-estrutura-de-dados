#include "TAB.h"
#include <limits.h>

TAB *TAB_inicializa(void){
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir){
  TAB *novo = (TAB *) malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

TAB* cria_ab_from_vector(int* vetor, int inicio, int final){

    if(inicio > final){
      return NULL;
    }
    
        int meio = (inicio+final)/2;
        TAB* tab = TAB_cria(vetor[meio], NULL, NULL);

        tab->esq = cria_ab_from_vector(vetor, inicio, meio -1);
        tab->dir = cria_ab_from_vector(vetor, meio+1, final);

        return tab;
    }

int mNAux(TAB* tab, int N, int* vetor, int pos){
    if(tab == NULL) return pos;

      // printf("%d\n", tab->info);

    if(tab->info < N) {
      vetor[pos] = tab->info;
      pos++;
    }

    if(tab->esq) pos = mNAux(tab->esq, N, vetor, pos);
    if(tab->dir) pos = mNAux(tab->dir, N, vetor, pos);

    return pos;
  }

int* mN(TAB*tab, int N, int *tam){
    int* vetor = (int*)malloc(sizeof(int)*(*tam));

    *tam = mNAux(tab, N, vetor, 0);

    return vetor;
}



TAB *TAB_busca(TAB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if(resp) return resp;
  return TAB_busca(a->dir, elem);
}

void TAB_imp_pre(TAB *a){
  if(a){
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

void TAB_imp_pos(TAB *a){
  if(a){
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TAB_imp_sim(TAB *a){
  if(a){
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

void imp_aux(TAB *a, int andar){
  int j;
  if(a){
    imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_imp_ident(TAB *a){
  imp_aux(a, 0);
}

void TAB_libera(TAB *a){
  if(a){
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}

