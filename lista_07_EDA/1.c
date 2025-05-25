#include <stdio.h>

void cria_binario(){

    FILE* file = fopen("1.bin", "wb+");

    int vet[100];   

    for (int i = 99; i >= 0; i--)
    {
        vet[i] = i;
    }

    fwrite(vet, 4, 100, file);

    fseek(file, 180, SEEK_SET);

    int k = 0;

    fread(&k, 4, 1, file);

    printf("%d\n", k);

    fclose(file);
    
}

void BolhaBin(char* nomeArq){

    FILE* file = fopen(nomeArq, "rb+");

    fseek(file, 0, SEEK_END);
    int size = ftell(file)/sizeof(int);
    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            fseek(file, (j)*sizeof(int), SEEK_SET);

            int a = 0;
            int b = 0;

            fread(&a, sizeof(int), 1, file);
            fread(&b, sizeof(int), 1, file);

            if(a < b){
                fseek(file, -2*sizeof(int), SEEK_CUR);
                fwrite(&b, sizeof(int), 1, file);
                fwrite(&a, sizeof(int), 1, file);
            }

        }
        
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < size; i++)
    {
        int k = 0;

        fread(&k, sizeof(int), 1, file);

        printf("%d\n", k);
    }
    
    
    
}


int main(){

    // cria_binario();

    BolhaBin("1.bin");
    

    return 0;
}