#include "graph.h"

void createGraph(Graph &G) {
    G.firstNode = nullptr;
}

Node* alokasiNode(char id) {
    Node* P = new Node;
    P->idKota = id;
    P->isLockdown = false;
    P->visited = false;
    P->firstEdge = nullptr;
    P->nextNode = nullptr;
    return P;
}

void insertNode(Graph &G, char id) {
    Node* P = alokasiNode(id);
    if (G.firstNode == nullptr) {
        G.firstNode = P;
    } else {
        Node* last = G.firstNode;
        while (last->nextNode != nullptr) last = last->nextNode;
        last->nextNode = P;
    }
}

// Menambahkan jalur dua arah (Undirected)
void addEdge(Graph &G, char src, char dest) {
    Node* pSrc = G.firstNode;
    while (pSrc != nullptr && pSrc->idKota != src) pSrc = pSrc->nextNode;
    
    Node* pDest = G.firstNode;
    while (pDest != nullptr && pDest->idKota != dest) pDest = pDest->nextNode;

    if (pSrc != nullptr && pDest != nullptr) {
        // Edge dari Src ke Dest
        Edge* E1 = new Edge;
        E1->destNode = pDest;
        E1->nextEdge = pSrc->firstEdge;
        pSrc->firstEdge = E1;

        // Edge dari Dest ke Src
        Edge* E2 = new Edge;
        E2->destNode = pSrc;
        E2->nextEdge = pDest->firstEdge;
        pDest->firstEdge = E2;
    }
}

void resetStatus(Graph &G) {
    Node* P = G.firstNode;
    while (P != nullptr) {
        P->visited = false;
        P = P->nextNode;
    }
}

void traversalDFS(Node* v) {
    if (v == nullptr || v->isLockdown) return;
    v->visited = true;
    Edge* E = v->firstEdge;
    while (E != nullptr) {
        if (!E->destNode->visited && !E->destNode->isLockdown) {
            traversalDFS(E->destNode);
        }
        E = E->nextEdge;
    }
}

int countNodes(Graph G) {
    int count = 0;
    Node* P = G.firstNode;
    while (P != nullptr) {
        count++;
        P = P->nextNode;
    }
    return count;
}

void printJaringan(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* P = G.firstNode;
    while (P != nullptr) {
        cout << "Node " << P->idKota << " terhubung ke:";
        Edge* E = P->firstEdge;
        while (E != nullptr) {
            cout << " " << E->destNode->idKota;
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}

void analisisKotaKritis(Graph &G) {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    int totalKota = countNodes(G);
    Node* pLock = G.firstNode;

    while (pLock != nullptr) {
        pLock->isLockdown = true; // simlasi Lockdown
        resetStatus(G);

        // mencari node awal untuk traversal yang bukan node sedang lockdown
        Node* start = G.firstNode;
        if (start == pLock) start = start->nextNode;

        if (start != nullptr) {
            traversalDFS(start);
        }

        // menghitung berapa yang terjangkau
        int terjangkau = 0;
        Node* pCek = G.firstNode;
        while (pCek != nullptr) {
            if (pCek->visited) terjangkau++;
            pCek = pCek->nextNode;
        }

        // Jika jumlah terjangkau < totalKota - 1, maka graph terputus
        if (terjangkau < (totalKota - 1)) {
            cout << "[PERINGATAN] Kota " << pLock->idKota << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << pLock->idKota << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << pLock->idKota << " aman (redundansi oke)." << endl;
        }

        pLock->isLockdown = false; // mengembalikan status
        pLock = pLock->nextNode;
    }
}