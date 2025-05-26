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

void gerar_particoes(FILE* file, int n){
    char vet[n][20];

    int j = 0;
    while(1){

        int count = 0;
        while(count<n && fscanf(file, "%s", vet[count])!=EOF) count++;

        if(count == 0) break;

        qsort(vet, count, 20, compara);

        char output_name[20];

        sprintf(output_name, "%d", j);
        
        strcat(output_name, "_particao");

        FILE* output = fopen(output_name, "w");
        printf("Outra particao:\n");

        for (int i = 0; i < n; i++)
        {   
            printf("%s\n", vet[i]);
            fprintf(output, "%s\n", vet[i]);
            strcpy(vet[i], "");
        }

        j++;
    }

}

int main(){

    FILE* file = fopen("source.txt", "r");


   gerar_particoes(file, 5);
   
    
   
    

    return 0;
}