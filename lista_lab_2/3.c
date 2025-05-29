#include <stdio.h>
#include <limits.h>
#include "../libs/TG/TG.h"

int qtd_nos(Node* g){
    if(!g) return 0;

    return 1 + qtd_nos(g->prox_no);
}

int mesma_qtd_nos(Node* g1, Node* g2){
    return (qtd_nos(g1) == qtd_nos(g2)) ? 1 : 0;
}

int qtd_arestas(Node* grafo){

    Aresta* aresta = grafo->prim_viz;
    int qtd_arestas = 0;
    
    while(aresta){
        qtd_arestas++;
        aresta = aresta->prox_aresta;
    }

    return qtd_arestas;
}

void copia_grafo(Node* g1, Node* g2){

    while(g1){

        Aresta* aresta = g1->prim_viz;

        

    }
}

int testa_candidato(Node* grafo_completo, Node* node_candidato){

}

void acha_candidato(Node* g1, Node* g2){

    Node* p = g2;
    while(p){
        if(qtd_arestas(g1) == qtd_arestas(p)) printf("\n%d é candidato\n", p->id_node);
        p = p->prox_no;
    }
}

int main(){


    Node* grafo = inicializa();

    for (int i = 0; i < 10; i++)
    {
        grafo = insere_node(grafo, i);
        insere_aresta(grafo, i-1, i);

    }
    
    imprime_grafo(grafo);

    int qtd = qtd_arestas(grafo->prox_no);

    printf("\n\n%d\n\n", qtd);

    acha_candidato(grafo, grafo);

    libera_TG(grafo);
    return 0;
}
