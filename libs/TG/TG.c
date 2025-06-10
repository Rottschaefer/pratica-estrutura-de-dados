
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

void insere_aresta(Node* grafo, int id_node_1, int id_node_2){
    insere_aresta_um_sentido(grafo, id_node_1, id_node_2);
    insere_aresta_um_sentido(grafo, id_node_2, id_node_1);
}

void retira_aresta_um_sentido(Node* grafo, int aresta_a_retirar, int node_da_aresta){
    Node* node = busca_node(grafo, node_da_aresta);

    Aresta* aresta = node->prim_viz;

    Aresta* ant = NULL;

    while(aresta && aresta->id_info != aresta_a_retirar){
        ant = aresta;
        aresta = aresta->prox_aresta;
    }

    if(!aresta){
        printf("**Essa aresta não existe**\n");
        return;
    }


    if(!ant) node->prim_viz = aresta->prox_aresta;
    else ant->prox_aresta = aresta->prox_aresta;

    free(aresta);

}

void retira_aresta(Node* grafo, int id_node_1, int id_node_2){
    retira_aresta_um_sentido(grafo, id_node_1, id_node_2);
    retira_aresta_um_sentido(grafo, id_node_2, id_node_1);
}

void libera_aresta(Aresta* aresta){
    if(!aresta) return;

    libera_aresta(aresta->prox_aresta);
    free(aresta);
}

Node* retira_node(Node* grafo, int id_node){
    Node* node = grafo, *ant;

    while(node->id_node != id_node) {
        ant = node;
        node = node->prox_no;
    }

    Aresta* aresta = node->prim_viz, *temp;

    while(aresta){
        temp = aresta->prox_aresta;

        retira_aresta(grafo, node->id_node, aresta->id_info);
        aresta = temp;
    }

    if(!ant){
        Node* new = node->prox_no;
        free(node);
        return new;
    } 

    ant->prox_no = node->prox_no;
    free(node);

    return grafo;
}

void libera_TG(Node* grafo){

    if(!grafo) return;

    libera_TG(grafo->prox_no);
    libera_aresta(grafo->prim_viz);


    free(grafo);

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

int conta_nodes(Node* grafo){
    if(!grafo) return 0;
    return 1 + conta_nodes(grafo->prox_no);
}