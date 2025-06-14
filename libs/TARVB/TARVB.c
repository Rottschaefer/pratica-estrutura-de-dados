#include "TARVB.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

TARVB* inicializa(){
    return NULL;
}

TARVB* cria_no(int t){
    TARVB* no = (TARVB*)malloc(sizeof(TARVB));
    no->folha = 1;
    no->chave = (int*)malloc(sizeof(int)*(2*t-1));
    no->filho = (TARVB**)malloc(sizeof(TARVB*)*(2*t));
    no->nchaves = 0;

    for (int i = 0; i < (2*t - 1); i++)
    {
        no->filho[i] = NULL;
        no->chave[i] = INT_MIN;
    }

    no->filho[(2*t - 1)] = NULL;


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


TARVB* Divide(TARVB* pai, TARVB* filho, int t){


    //Sobe a chave do meio para o pai
    int pos = pai->nchaves -1;


    while(pos >= 0 && pai->chave[pos] > filho->chave[t-1]){
    pai->chave[pos+1] = pai->chave[pos];
    pai->filho[pos+2] = pai->filho[pos+1];
    pos--;
        }

    pos++;
    pai->chave[pos] = filho->chave[t-1];
    pai->nchaves++;


    //Cria novo nó e transfere a metade superior das chaves e ponteiros do filho para ele
    TARVB* novo_filho = cria_no(t);
    novo_filho->nchaves= t-1;
    novo_filho->folha = filho->folha;

    int i = t;
    for (i = t; i < (2*t-1); i++)
    {
        novo_filho->chave[i-t] = filho->chave[i];
        novo_filho->filho[i-t] = filho->filho[i];
        filho->filho[i] = NULL;
    }

    novo_filho->filho[i-t] = filho->filho[2*t-1];
    filho->filho[2*t-1] = NULL;


    filho->nchaves = t-1;

    //Ponteiros ao redor do valor que subiu recebem os filhos
    pai->filho[pos] = filho;
    pai->filho[pos+1] = novo_filho;


    return pai;


}

TARVB* TARVB_insere(TARVB* arvb, int num, int t){


    //Caso 1: Árvore Vazia
    if(!arvb){
        arvb = cria_no(t);
        arvb->chave[0] = num;
        arvb->nchaves = 1;
        return arvb;
    }

    //Caso 2: Raíz cheia
    if(arvb->nchaves == (2*t - 1)){

        TARVB* novo_pai = cria_no(t);
        novo_pai->folha = 0;


        arvb = Divide(novo_pai, arvb, t);


        if(num > arvb->chave[0]) arvb->filho[1] = TARVB_insere(arvb->filho[1], num, t);
        else arvb->filho[0] = TARVB_insere(arvb->filho[0], num, t);

        return arvb;

    }

    //Checa os filhos do nó para saber se algum está cheio
    if(!arvb->folha){
        for (int i = 0; i < (arvb->nchaves + 1); i++)
        {
            if(arvb->filho[i]->nchaves == (2*t - 1)){
                arvb = Divide(arvb, arvb->filho[i], t);
            }
        }}


    //Caso Trivial: Nó é folha e tem menos que 2t-1 chaves
    if(arvb->folha && arvb->nchaves < (2*t-1)){
        int i = arvb->nchaves - 1;

        while (i>=0 && arvb->chave[i] > num)
        {
            arvb->chave[i+1] = arvb->chave[i]; //Deslocando o array para a direita e inserindo ínidice na posição correta
            i--;
        }

        arvb->chave[i+1] = num;
        arvb->nchaves++;

        return arvb;
    }

    //Caso 3: Nó é interno e nada precisa ser dividido aqui

    int i = 0;
    while (i < (arvb->nchaves) && arvb->chave[i] < num ) i++;

    arvb->filho[i] = TARVB_insere(arvb->filho[i], num, t);


    return arvb;
}
