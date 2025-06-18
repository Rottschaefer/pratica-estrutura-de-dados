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
        no->chave[i] = INT_MAX;
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

TARVB* TARVB_retira(TARVB* arvb, int n, int t){
    if(!arvb) return NULL;

    int i = 0;
    while (n > arvb->chave[i]) i++;

    if(arvb->chave[i] != n) {
        
        if(arvb->filho[i]->nchaves >= t) return TARVB_retira(arvb->filho[i], n, t);

        //CASO 3A

        if(arvb->filho[i+1]->nchaves >=t){

            printf("\nCASO 3A\n");
            TARVB* filho_esq = arvb->filho[i];
            TARVB* filho_dir = arvb->filho[i+1];

            filho_esq->chave[filho_esq->nchaves] = arvb->chave[i];
            filho_esq->nchaves++;
            filho_esq->filho[filho_esq->nchaves] = filho_dir->filho[0];

            arvb->chave[i] = filho_dir->chave[0];

            int j = 0;

            for (j = 0; j < filho_dir->nchaves - 1; j++)
            {
                filho_dir->chave[j] = filho_dir->chave[j+1];
                filho_dir->filho[j] = filho_dir->filho[j+1];
            }
            
            filho_dir->chave[j] = INT_MAX;
            filho_dir->filho[j] = filho_dir->filho[j+1];
            filho_dir->filho[j+1] = NULL;
            filho_dir->nchaves--;

            arvb->filho[i] =  TARVB_retira(arvb->filho[i], n, t);

            return arvb;

        }
        //CASO 3B

        printf("\nCASO 3B\n");

        TARVB* filho_esq = arvb->filho[i];
        TARVB* filho_dir = arvb->filho[i+1];

        filho_esq->chave[filho_esq->nchaves] = arvb->chave[i];
        filho_esq->nchaves++;

        int j = 0;
        for (j = 0; j < filho_dir->nchaves; j++)
        {
            filho_esq->chave[filho_esq->nchaves] = filho_dir->chave[j];
            filho_esq->filho[filho_esq->nchaves] = filho_dir->filho[j];
            filho_dir->filho[j] = NULL;
            filho_esq->nchaves++;

        }
        
        filho_esq->filho[filho_esq->nchaves] = filho_dir->filho[j];
        filho_dir->filho[j] = NULL;

        TARVB_libera(filho_dir);

        for (j = i; j < arvb->nchaves - 1; j++)
        {
            arvb->chave[j] = arvb->chave[j+1];
            arvb->filho[j+1] = arvb->filho[j+2];
        }

        arvb->nchaves--;
        arvb->chave[arvb->nchaves] = INT_MAX;
        arvb->filho[j+1] = NULL;


        arvb->filho[i] = TARVB_retira(arvb->filho[i], n, t);

        if(arvb->nchaves == 0){
            //Arvb era raiz e perdeu o elemento que tinha

            TARVB* temp = arvb;
            arvb = arvb->filho[0];
            temp->filho[0] = NULL;

            TARVB_libera(temp);

            return arvb;
        }

        return arvb;
        

    }


    //CASO 1: n é folha e pode ser retirado sem problemas
    if(arvb->folha){
        printf("\nCaso 1\n");
        int k = arvb->nchaves - 1; //Penúltimo

        for (int j = i; j < k; j++)
        {
            arvb->chave[j] = arvb->chave[j+1];
        }

        arvb->chave[k] = INT_MAX;


        arvb->nchaves--;

        return arvb;
    }

    //CASO 2A: filho predecessor tem pelo menos t chaves
    if(arvb->filho[i]->nchaves >= t){
        printf("\nCaso 2A\n");

       TARVB* filho = arvb->filho[i];

       arvb->chave[i] = filho->chave[filho->nchaves-1];

       return TARVB_retira(filho, filho->chave[filho->nchaves-1], t);
    }

    //CASO 2B: filho sucessor tem pelo menos t chaves
    if(arvb->filho[i+1]->nchaves >= t){
        printf("\nCaso 2B\n");

        TARVB* filho = arvb->filho[i+1];

        arvb->chave[i] = filho->chave[0];

        return TARVB_retira(filho, filho->chave[0], t);
    }

    //CASO 2C: filhos predecessor e sucessor tem t-1 chaves

    printf("\nCaso 2C\n");


    //Coloco o n no meio do novo filho(junção do sucessor com predecessor)
    arvb->filho[i]->chave[arvb->filho[i]->nchaves] = n;
    arvb->filho[i]->nchaves++;

    int offset = arvb->filho[i]->nchaves;

    for (int j = 0; j < arvb->filho[i+1]->nchaves; j++)
    {
        arvb->filho[i]->chave[offset + j] = arvb->filho[i+1]->chave[j];
        arvb->filho[i]->filho[offset + j] = arvb->filho[i+1]->filho[j];
        arvb->filho[i+1]->filho[j] = NULL; //Para evitar de liberar os filhos na hora de dar free
        arvb->filho[i]->nchaves++;
    }

    arvb->filho[i]->filho[arvb->filho[i]->nchaves] = arvb->filho[i+1]->filho[arvb->filho[i+1]->nchaves];
    arvb->filho[i+1]->filho[arvb->filho[i+1]->nchaves] = NULL;


    TARVB_libera(arvb->filho[i+1]);

    // arvb->chave[i] = n;

    //Retira chave do nó pai
    for (int j = i; j < arvb->nchaves-1; j++)
    {
        arvb->chave[j] = arvb->chave[j+1];
        arvb->chave[j+1] = INT_MAX;
        arvb->filho[j+1] = arvb->filho[j+2];
        arvb->filho[j+2] = NULL;
    }

    arvb->nchaves--;


    arvb->filho[i] = TARVB_retira(arvb->filho[i], n, t);
    
    return arvb;
    
}

void TARVB_libera(TARVB* arvb){
    if(!arvb) return;

    for (int i = 0; i < arvb->nchaves+1; i++)
    {
        TARVB_libera(arvb->filho[i]);
    }

    free(arvb->chave);
    free(arvb->filho);
    free(arvb);
    
}