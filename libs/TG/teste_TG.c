#include "TG.h"
#include <stdlib.h>


int main(){

    Node* grafo = inicializa();

    for (int i = 0; i < 10; i++)
    {
        grafo = insere_node(grafo, i);
        insere_aresta(grafo, i-1, i);

    }

    insere_aresta(grafo, 2, 8);
    insere_aresta(grafo, 9, 3);
    insere_aresta(grafo, 1, 7);

    retira_aresta(grafo, 8, 9);
    retira_aresta(grafo, 7, 1);

    retira_node(grafo, 1);
    retira_node(grafo, 8);
    
    imprime_grafo(grafo);

    libera_TG(grafo);

    return 0;
}