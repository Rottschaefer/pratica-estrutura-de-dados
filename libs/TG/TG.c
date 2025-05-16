
#include <stdlib.h>
#include <stdio.h>
#include "TG.h"

Node* inicializa(){
    return NULL;
}

Node* cria_node(Node* grafo, int id_node){
    Node* node = (Node*)malloc(sizeof(Node));
    node->id_node = id_node;
    node->prim_viz = NULL;
    node->prox_no = grafo;

    return node;
}

Aresta* cria_aresta(int id_info){
    Aresta* aresta = (Aresta*)malloc(sizeof(Aresta));
    aresta->id_info = id_info;
    aresta->prox_aresta = NULL;

    return aresta;
}

Node* busca_node(Node* grafo, int id_node){
    while (grafo)
    {
        if(grafo->id_node == id_node) return grafo;

        grafo = grafo->prox_no;
    }

    return NULL;
}

Node* insere_node(Node* grafo, int id_node){

    Node* node = busca_node(grafo, id_node);
    if(!node) return cria_node(grafo, id_node);

    else{
        printf("Node já existe\n");
        return NULL;
    }

}

void insere_aresta_um_sentido(Node* grafo, int id_node_1, int id_node_2){

    Node* node_1 = busca_node(grafo, id_node_1);
    Node* node_2 = busca_node(grafo, id_node_2);

    if(!node_1 || !node_2) {
        printf("***É preciso que os dois nodes existam para criar uma aresta***\n");
        return;
    }

    Aresta* old_aresta = node_1->prim_viz;

    Aresta* new_aresta = cria_aresta(id_node_2);
    node_1->prim_viz = new_aresta;
    new_aresta->prox_aresta = old_aresta;
}

void imprime_grafo(Node* grafo){
    while(grafo){
        printf("%d :", grafo->id_node);

        Aresta* aresta = grafo->prim_viz;

      
        while (aresta){
            printf("/ %d /", aresta->id_info);
            aresta = aresta->prox_aresta;
        }

        printf("\n");
        grafo = grafo->prox_no;
        
    }
}