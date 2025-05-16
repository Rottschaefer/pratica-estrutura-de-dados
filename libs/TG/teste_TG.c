#include "TG.h"

int main(){

    Node* grafo = inicializa();

    for (int i = 0; i < 10; i++)
    {
        grafo = insere_node(grafo, i);
        insere_aresta_um_sentido(grafo, i-1, i);


    }
    
    
    imprime_grafo(grafo);


    return 0;
}