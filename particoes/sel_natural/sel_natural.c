#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indice_menor(int m, int vet[m]){

    int indice_menor = 0;
    for (int i = 0; i < m; i++)
    {
        if(vet[i] < vet[indice_menor]) indice_menor = i;
    }

    return indice_menor;
    
}

void sel_natural(FILE* file, int m){


    int* array = (int*)malloc(sizeof(int)*m);
    int* reservatorio = (int*)malloc(sizeof(int)*m);

    int pos_reservatorio = 0;

    int array_size = 0;


    int k = 0;
    int num_particao = 0;
    

    while (k != EOF)
    {   
        num_particao++;
        char nome_file[30];
        sprintf(nome_file ,"%d_particao", num_particao);

        for(array_size = 0; array_size < m; array_size++){

            k = fscanf(file, "%d", &array[array_size]);
            printf("Particao: %d, %d\n", num_particao, array[array_size]);
            if(k == EOF) break;
        }

        FILE* particao = fopen(nome_file, "w");

        int i_menor = indice_menor(m, array);

        printf("\n%d\n", i_menor);

        int menor = array[i_menor];

        fprintf(particao, "%d", menor);

        k = fscanf(file, "%d", &array[i_menor]);

       while (k != EOF && array[i_menor] < menor){
            reservatorio[pos_reservatorio] = array[i_menor];
            k = fscanf(file, "%d", &array[i_menor]);
       }
        
    }
    
    
}

int main(){

    FILE* file = fopen("../source.txt", "r");

    sel_natural(file, 10);
    return 0;
}