#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
    char nome[41];
    char CPF[12];
    int conta_corrente;
    int agencia;
    float saldo;
}Cliente;

void criar_clientes(){
    FILE* nomes = fopen("nomes.bin", "rb");
    FILE* cpfs = fopen("cpfs.bin", "rb");
    FILE* clientes = fopen("clientes.bin", "ab");

    fseek(cpfs, 0, SEEK_END);
    int file_size = ftell(cpfs)/12;
    fseek(cpfs, 0, SEEK_SET);


    for (int i = 0; i < file_size; i++)
    {
        Cliente * new = (Cliente*)malloc(sizeof(Cliente));
        new->agencia = 300;
        new->saldo = 45.0;
        fscanf(cpfs, "%s", new->CPF);
        fseek(cpfs, 1, SEEK_CUR);
        fgets(new->nome, sizeof(new->nome), nomes);
        // fseek(nomes, 1, SEEK_CUR);

        fwrite(new, sizeof(Cliente), 1, clientes);

        free(new);

    }

    fclose(nomes);
    fclose(cpfs);
    fclose(clientes);
    
}

void find_cliente(FILE* clientes, char cpf[12]){
    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));
    
    while (fread(cliente, sizeof(Cliente), 1, clientes) == 1)
    {
        if(!strcmp(cpf, cliente->CPF)){
            printf("Nome: %s", cliente->nome);
            printf("CPF: %s\n", cliente->CPF);
            printf("Conta: %d\n", cliente->conta_corrente);
            printf("Agência: %d\n", cliente->agencia);
            printf("Saldo: %.2f\n", cliente->saldo);
            free(cliente);
            return;
        }
    }

    
    printf("Não existe cliente com esse cpf\n");
    free(cliente);
    return;
    
    
}

int main(int argc, char* argv[]){

    FILE* clientes = fopen("clientes.bin", "rb");

    find_cliente(clientes, argv[1]);

    // criar_clientes();

    return 0;
}