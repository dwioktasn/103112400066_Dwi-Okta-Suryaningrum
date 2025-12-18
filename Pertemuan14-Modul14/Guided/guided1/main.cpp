#include <iostream>
#include "graph.h"
using namespace std;

int main(){
    Graph G;
    createGraph(G);

    //menambah node a, b, c, d
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //menghubungkan node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi graph:" << endl;
    printGraph(G);

    return 0;
}