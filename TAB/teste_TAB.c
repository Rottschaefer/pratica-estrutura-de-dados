#include <string.h>
#include "TAB.h"

TAB *suc_aux (TAB *a, int x, TAB *resp){
  if(!a) return resp;
  TAB *e = suc_aux(a->esq, x, resp);
  if(e){
    if((!resp) && (e->info > x)) resp = e;
    else if ((resp) && (e->info < resp->info)) resp = e;
  }
  TAB *d = suc_aux(a->dir, x, resp);
  if(d){
    if((!resp) && (d->info > x)) resp = d;
    else if ((resp) && (d->info < resp->info)) resp = d;
  }
  if(a->info > x)
    if((!resp) || (a->info < resp->info)) return a;
  return resp;
}

TAB *suc (TAB *a, int x){
  if(!a) return a;
  if(a->info <= x) return suc_aux(a, x, NULL);
  return suc_aux(a, x, a);
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  printf("\n");
  
  int n;
  scanf("%d", &n);
  resp = suc(a, n);
  if(resp) printf("suc(a, %d) = %d\n", n, resp->info);
  else printf("Nao existe sucessor...\n");  
  
  TAB_libera(a);
  return 0;
}
