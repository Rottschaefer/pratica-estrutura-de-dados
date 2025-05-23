#include <stdio.h>
#include "../libs/TG/TG.h"

int main(){

    Node* grafo = inicializa();

     for (int i = 0; i < 10; i++)
    {
        grafo = insere_node(grafo, i);
        insere_aresta(grafo, i-1, i);

    }

    printf("%p\n", grafo);

    return 0;
}