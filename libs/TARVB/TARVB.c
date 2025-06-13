#include "TARVB.h"
#include <stdlib.h>
#include <stdio.h>

TARVB* inicializa(){
    return NULL;
}

TARVB* cria_no(int t){
    TARVB* no = (TARVB*)malloc(sizeof(TARVB));
    no->folha = 1;
    no->chave = (int*)malloc(sizeof(int)*(2*t-1));
    no->filho = (TARVB**)malloc(sizeof(TARVB*)*(2*t));

    for (int i = 0; i < (2*t); i++)
    {
        no->filho[i] = NULL;
    }

    return no;
}

void imp_rec(TARVB *a, int andar){
  if(a){
    int i,j;
    for(i=0; i<=a->nchaves-1; i++){
      imp_rec(a->filho[i],andar+1);
      for(j=0; j<=andar; j++) printf("\t");
      printf("%d\n", a->chave[i]);
    }
    imp_rec(a->filho[i],andar+1);
  }
}


void TARVB_Imprime(TARVB *a){
  imp_rec(a, 0);
}

void insere_chave_array(TARVB* arvb, int n){

    int i = 0;

    while(i<= 0 && arvb->chave[i] > n){
        arvb->chave[i+1] = arvb->chave[i];
    }
}

TARVB* TARVB_insere(TARVB* arvb, int num, int t){
    if(!arvb){
        arvb = cria_no(t);
        arvb->chave[0] = num;
        arvb->nchaves = 1;
        return arvb;
    }

    if(arvb->nchaves == (2*t -1)){
        TARVB * subido
    }

    if(arvb->nchaves < (2*t-1)){
        int i = arvb->nchaves - 1;

        while (i>=0 && arvb->chave[i] > num)
        {
            arvb->chave[i+1] = arvb->chave[i]; //Deslocando o array para a direita e inserindo ínidice na posição correta
            i--;
        }

        arvb->chave[i+1] = num;
        arvb->nchaves++;

        
    }

    return arvb;
}
