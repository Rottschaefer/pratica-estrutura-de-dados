#include <stdio.h>
#include <stdlib.h>
#include "libs/TG/TG.h"
#include "libs/TLSE/TLSE.h"

//Erros
//Passei como parametro l, mas era pra passar &l, se nao a lista nao é atualizada
//Inseri na lista art, mas nao recebi o retorno corretamente
//Esqueci do -1 na hr de comparar as quantidades



void aux(Node* grafo, Node* atual, int n_candidato, TLSE** l) {

    if(!atual || (atual->id_node == n_candidato) || TLSE_busca(*l, atual->id_node)) return;
 
    *l = TLSE_insere_inicio(*l, atual->id_node);

    Aresta* aresta = atual->prim_viz;
    while (aresta != NULL) {

        if (aresta->id_info == n_candidato){
            aresta = aresta->prox_aresta;
            continue;
        }

        Node* no = busca_node(grafo, aresta->id_info);
        
        aux(grafo, no, n_candidato, l);



        aresta = aresta->prox_aresta;
    }
}

TLSE* PontoArticulacao(Node* grafo){
    TLSE *art = NULL;

    Node* copia_grafo = grafo;

    while (copia_grafo)
    {

        Node* inicio = grafo;
        while (inicio && inicio->id_node == copia_grafo->id_node) {
            inicio = inicio->prox_no;
        }//Tem que colocar aqui pq se nao pode entrar no aux no nó de mesmo id que tem que desconsiderar

        TLSE* l = NULL;
        aux(grafo, inicio, copia_grafo->id_node, &l);

        if(conta_nodes(grafo)-1 != TLSE_conta(l)) art = TLSE_insere_inicio(art, copia_grafo->id_node);

        copia_grafo = copia_grafo->prox_no;
    }
    
    return art;
}


int main(){

    Node* grafo = inicializa();

     // Insere os nós 0,1,2,3,4,5
    grafo = insere_node(grafo, 0);
    grafo = insere_node(grafo, 1);
    grafo = insere_node(grafo, 2);
    grafo = insere_node(grafo, 3);
    grafo = insere_node(grafo, 4);
    grafo = insere_node(grafo, 5);

    // Arestas do primeiro triângulo: 0–1–2–0
    insere_aresta(grafo, 0, 1);
    insere_aresta(grafo, 1, 2);
    insere_aresta(grafo, 2, 0);

    // Arestas do segundo triângulo: 2–3–4–2
    insere_aresta(grafo, 2, 3);
    insere_aresta(grafo, 3, 4);
    insere_aresta(grafo, 4, 2);

    // Conecta o nó 5 como folha de 4
    insere_aresta(grafo, 4, 5);


    TLSE* l = PontoArticulacao(grafo);

    TLSE_print(l);

    return 0;
}
