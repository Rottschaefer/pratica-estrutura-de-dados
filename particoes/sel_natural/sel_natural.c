#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void copy_and_clean(int* vet1, int* vet2, int size){
    for (int i = 0; i < size; i++)
    {
        vet1[i] = vet2[i];
        vet2[i] = 0;
    }
    
}

void print_array(int * array, int size){
    for (int i = 0; i < size; i++)
        {
            printf("%d\n", array[i]);
        }

    printf("\n\n");
}

int indice_menor(int m, int vet[m]){

    int indice_menor = 0;
    for (int i = 0; i < m; i++)
    {
        if(vet[i] < vet[indice_menor]) indice_menor = i;
    }

    return indice_menor;
    
}

void particiona(FILE* file, int* array, int* reservatorio, int* size, int num_particao){


    int pos_reservatorio = 0;

    int k = 0;

    char nome[30];
    sprintf(nome, "%d_particao", num_particao);

    FILE* particao = fopen(nome, "w");

    int menor = array[0];

    while(menor != INT_MAX){
        // printf("%d %d", pos_reservatorio, size);

        printf("Array:\n");
        print_array(array, *size);

        printf("Reservatorio:\n");
        print_array(reservatorio, pos_reservatorio);


        int i_menor = indice_menor(*size, array);

        int menor = array[i_menor];

        if(menor == INT_MAX) break;

        fprintf(particao, "%d\n", menor);


        k = fscanf(file, "%d", &array[i_menor]);

        if(k == EOF) array[i_menor] = INT_MAX;

        

        while(pos_reservatorio<=*size && array[i_menor] < menor){
            printf("\n\nNumero %d foi pro reservatorio\n\n", array[i_menor]);
            reservatorio[pos_reservatorio] = array[i_menor];
            pos_reservatorio++;
            k = fscanf(file, "%d", &array[i_menor]);

            if(k == EOF) {
                array[i_menor] = INT_MAX;
                break;
            }
        }

    }

    *size = pos_reservatorio;

}

void sel_natural(FILE* file, int m){

    int * array = (int*)malloc(sizeof(int)*m);
    int * reservatorio = (int*)malloc(sizeof(int)*m);



    int k = 0;
    int num_particao=1;

    int size = 0;
    for (size = 0; (size < m && k != EOF); size++)
    {
        k = fscanf(file, "%d", &array[size]);
    }


    printf("Primeiro array passado:\n");
    
    print_array(array, size);

    while(size != 0){
        particiona(file, array, reservatorio, &size, num_particao);
        int* temp = array;
        array = reservatorio;
        reservatorio = temp;
        num_particao++;


    }
        

    free(array);
    free(reservatorio);
    
}

int main(){

    FILE* file = fopen("../source.txt", "r");

    // int vet[10];

    // fscanf(file, "%d", vet);

    // printf("%s", vet[0]);

    sel_natural(file, 10);
    return 0;
}