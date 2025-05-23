#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* file_a = fopen("a.bin", "rb");
    FILE* file_b = fopen("b.bin", "rb");
    FILE* file_c = fopen("c.bin", "wb");

    char * word_a = (char*)malloc(10*sizeof(char));
    char * word_b = (char*)malloc(10*sizeof(char));
    char * word_c = (char*)malloc(10*sizeof(char));

    fseek(file_a, 0, SEEK_END);
    int size_a = ftell(file_a)/11;
    fseek(file_a, 0, SEEK_SET);

    fseek(file_b, 0, SEEK_END);
    int size_b = ftell(file_b)/11;
    fseek(file_b, 0, SEEK_SET);


    for (int i = 0; i < size_a; i++)
    {   
        fread(word_a, 1, 10, file_a);
        fseek(file_a, 1, SEEK_CUR);

        for (int j = 0; j < size_b; j++)
        {
            
            fread(word_b, 1, 10, file_b);
            fseek(file_b, 1, SEEK_CUR);

            fwrite(word_a, 1, 10, file_c);
            fwrite(" ", 1, 1, file_c);
            fwrite(word_b, 1, 10, file_c);
            fwrite("\n", 1, 1, file_c);
        }
        
        fseek(file_b, 0, SEEK_SET);

    }

    free(word_a);
    free(word_b);
    free(word_c);
    
    return 0;
}