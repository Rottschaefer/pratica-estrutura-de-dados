#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara (const void* a, const void* b){
    char* c = (char*)a;
    char* d = (char*)b;

    int cmp = strcmp(c, d);

    if(cmp < 0) return -1;
    if(cmp == 0) return 0;
    if(cmp > 0) return 1;


}

int main(){

    FILE* file = fopen("source.txt", "r");

    char vet[10][20];

   for (int i = 0; i < 10; i++)
   {   
       fscanf(file, "%s", vet[i]);
   }

   qsort(vet, 10, 20, compara);

   for (int i = 0; i < 10; i++)
   {
       printf("%s\n", vet[i]);
   }
    
    
    

    return 0;
}