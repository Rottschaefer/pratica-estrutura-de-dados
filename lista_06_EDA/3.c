#include <stdio.h>
#include <stdlib.h>

typedef struct cliente{
    char nome[41];
    char CPF[12];
    int conta_corrente;
    int agencia;
    float saldo;
}Cliente;

int compare(const void* a,const void* b){
    Cliente* cliente_a = (Cliente*)malloc(sizeof(Cliente));
    Cliente* cliente_b = (Cliente*)malloc(sizeof(Cliente));

    FILE* clientes = fopen("clientes.bin", "rb");
    fseek(clientes, *(int*)a, SEEK_SET);
    fread(cliente_a, sizeof(Cliente), 1, clientes);

    fseek(clientes, *(int*)b, SEEK_SET);
    fread(cliente_b, sizeof(Cliente), 1, clientes);

    float output = (cliente_a->saldo) - (cliente_b->saldo);

    free(cliente_a);
    free(cliente_b);

    if (output < 0.0) return -1;
    if (output > 0.0) return 1;
    return 0;

}


int main(){

    long int array[100];

    for (int i = 0; i <100; i++)
    {
        array[i] = i*sizeof(Cliente);
    }

    qsort(array, 100, sizeof(array[0]), compare);

    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));

    FILE* clientes = fopen("clientes.bin", "rb");
    FILE* indices = fopen("indices.bin", "w");

    for (int i = 0; i < 100; i++)
    {   
        // fprintf(indices, "%ld\n", array[i]/sizeof(Cliente)+1);

        long int k = array[i] / sizeof(Cliente);
        fwrite(&(k), sizeof(array[i]), 1, indices);
        fseek(clientes, array[i], SEEK_SET);
        fread(cliente, sizeof(Cliente), 1, clientes);
        printf("%.2f\n", cliente->saldo);
    }


    
    
    return 0;
}