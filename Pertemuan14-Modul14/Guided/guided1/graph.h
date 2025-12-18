#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

//ALIAS BBRP HAL
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

//STRUCT 
struct ElmNode {                 
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge{
    adrNode node;
    adrEdge next;
};

struct Graph{
    adrNode first;
};

//PROTOTYPES
void createGraph(Graph &G);
adrNode allocNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
