typedef struct aresta{
    int id_info;
    struct aresta * prox_aresta;
}Aresta;

typedef struct tg_node{
    int id_node;
    struct tg_node * prox_no;
    Aresta* prim_viz;
}Node;

Node* inicializa();

Node* insere_node(Node* grafo, int id_node);

void insere_aresta_um_sentido(Node* grafo, int id_node_1, int id_node_2);

void insere_aresta(Node* grafo, int id_node_1, int id_node_2);

void retira_aresta(Node* grafo, int id_node_1, int id_node_2);

Node* retira_node(Node* grafo, int id_node);


void libera_TG(Node* grafo);

void imprime_grafo(Node* grafo);

Node* busca_node(Node* grafo, int id_node);
int conta_nodes(Node* grafo);
