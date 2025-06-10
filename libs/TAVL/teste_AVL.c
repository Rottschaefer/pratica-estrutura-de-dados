#include "TAVL.h"

int main(int argc, char *argv[]){
  TAVL *arvore = NULL;
  int num = 0, from, to;

  int vet[] = {12, 18, 8, 17, 11, 5, 4};

  for (int i = 0; i < sizeof(vet)/sizeof(vet[0]); i++)
  {
    arvore = TAVL_insere(vet[i], arvore);
  }
  
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%i", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TAVL_retira(from, arvore);
      TAVL_imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TAVL_imprime(arvore);
      TAVL_libera(arvore);
      return 0;
    }
    else if(!num){
      printf("\n");
      TAVL_imprime(arvore);
    }
    else arvore = TAVL_insere(num, arvore);
    printf("\n\n");
  }
}
