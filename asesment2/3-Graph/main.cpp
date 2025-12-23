#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    // Memasukkan Node sesuai Gambar Ekspektasi (A, B, C, D, E)
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');

    // Membangun Edge sesuai relasi di Gambar Ekspektasi
    addEdge(G, 'A', 'B');
    addEdge(G, 'B', 'C');
    addEdge(G, 'B', 'E');
    addEdge(G, 'C', 'D');

    printJaringan(G);
    analisisKotaKritis(G);

    return 0;
}