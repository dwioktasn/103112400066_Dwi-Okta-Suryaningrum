#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

struct Node;

struct Edge {
    Node* destNode;
    Edge* nextEdge;
};

struct Node {
    char idKota;
    bool isLockdown; // Status untuk simulasi
    bool visited;    // Untuk keperluan traversal
    Edge* firstEdge;
    Node* nextNode;
};

struct Graph {
    Node* firstNode;
};

// Fungsi dasar Graph
void createGraph(Graph &G);
Node* alokasiNode(char id);
void insertNode(Graph &G, char id);
void addEdge(Graph &G, char src, char dest); 

// Fungsi Analisis
int countNodes(Graph G);
void resetStatus(Graph &G);
void traversalDFS(Node* v);
void analisisKotaKritis(Graph &G);
void printJaringan(Graph G);

#endif