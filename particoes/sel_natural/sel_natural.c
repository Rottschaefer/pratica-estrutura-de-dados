#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void inicializa_vetor(int* vet, int m){
     for (int i = 0; i < m; i++)
    {
        vet[i] = INT_MAX;
    }

}
void print_vetor(int * array, int size){
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

int calc_nova_particao(FILE* file, int size_vet_atual, int vet_atual[size_vet_atual], int* reservatorio, int num_particao){

    char nome[20];

    sprintf(nome, "%d_particao.txt", num_particao);

    FILE* particao = fopen(nome, "w");

    int s = 0;
    int reserv_pos = 0;


    while(1){

        int i_menor = indice_menor(size_vet_atual, vet_atual);

        int menor = vet_atual[i_menor];


        if(menor == INT_MAX) break;
        


        fprintf(particao, "%d\n", menor);

        if(reserv_pos < size_vet_atual) {
            s = fscanf(file, "%d", &vet_atual[i_menor]);
            if(s == EOF) vet_atual[i_menor] = INT_MAX;

        }
        else vet_atual[i_menor] = INT_MAX; //Tirar valor que já gravei do array caso nao leia mais nada do arquivo

       
        while(vet_atual[i_menor] < menor){

            reservatorio[reserv_pos++] = vet_atual[i_menor];

            if(reserv_pos < size_vet_atual) {
                s = fscanf(file, "%d", &vet_atual[i_menor]);
                if(s == EOF) vet_atual[i_menor] = INT_MAX;
            }
            else vet_atual[i_menor] = INT_MAX; //Tirar valor que já gravei do array caso nao leia mais nada do arquivo

        }
        
        
    }

    fclose(particao);

    return reserv_pos; //Vai ser o tamanho do proximo vetor analisado


}

void sel_natural(FILE* file, int m){


    int* vet_atual = (int*)malloc(sizeof(int)*m);
    int* reservatorio = (int*)malloc(sizeof(int)*m);

    inicializa_vetor(vet_atual, m);
    inicializa_vetor(reservatorio, m);

    int s = 0;
    for (int i = 0; (s != EOF && i < m) ; i++)
    {
        s = fscanf(file, "%d", &vet_atual[i]);
    }
    
    int size = m;
    int i = 1;

    while (size != 0)
    {
        size = calc_nova_particao(file, m, vet_atual, reservatorio, i);
        i++;

        int* temp = vet_atual;
        vet_atual = reservatorio;
        reservatorio = temp;
    }
    
    printf("\nPartições prontas!\n");

    free(vet_atual);
    free(reservatorio);

   
    
}

int main(){

    FILE* file = fopen("../source.txt", "r");

    sel_natural(file, 10);

    fclose(file);
    return 0;
}