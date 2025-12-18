#include "graph.h"
#include <algorithm>

void CreateGraph(Graph &G){
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->firstEdge = NULL;
    P->next = NULL;

    if(G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if(P->info == X){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, adrNode N1, adrNode N2){
    adrEdge E = new ElmEdge;
    E->node = N2;
    E->next = N1->firstEdge;
    N1->firstEdge = E;
}

void PrintInfoGraph(Graph G){
    adrNode P = G.first;

    while(P != NULL){
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;

        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }

        cout << endl;
        P = P->next;
    }
}

void DFS(Graph G, adrNode P, bool visited[]){
    if(P == NULL) return;

    cout << P->info << " ";
    visited[P->info - 'A'] = true;

    vector<char> neighbours;
    adrEdge E = P->firstEdge;

    while(E != NULL){
        neighbours.push_back(E->node->info);
        E = E->next;
    }

    sort(neighbours.begin(), neighbours.end());

    for(char c : neighbours){
        adrNode next = FindNode(G, c);
        if(!visited[c - 'A']){
            DFS(G, next, visited);
        }
    }
}

void PrintDFS(Graph G, char start){
    adrNode P = FindNode(G, start);
    if(P == NULL){
        cout << "Node tidak ditemukan.\n";
        return;
    }

    bool visited[26] = {false};

    cout << "DFS mulai dari " << start << " : ";
    DFS(G, P, visited);
    cout << endl;
}