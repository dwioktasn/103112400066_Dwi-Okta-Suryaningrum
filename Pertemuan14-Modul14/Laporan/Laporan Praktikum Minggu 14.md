<h1 align = "center">Laporan Praktikum Modul 14<br>GRAPH</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
Graf (_graph_) merupakan salah satu konsep fundamental dalam Matematika Diskrit yang digunakan untuk merepresentasikan hubungan antar objek. Secara matematis, suatu graf didefinisikan sebagai pasangan himpunan G=(V,E)G = (V, E)G=(V,E), di mana VVV adalah himpunan tidak kosong dari _vertex_ (simpul atau node), sedangkan EEE adalah himpunan sisi (_edges_ atau _arcs_) yang menghubungkan sepasang vertex [1]. Dengan demikian, graf dapat dipandang sebagai kumpulan simpul yang saling terhubung melalui sisi atau busur.

Berdasarkan sifat arahnya, graf dibedakan menjadi graf berarah dan graf tak berarah. Graf tak berarah didefinisikan sebagai pasangan G=(V,E)G = (V, E)G=(V,E), dengan VVV merupakan himpunan terbatas dan tidak kosong dari vertex, serta EEE merupakan himpunan terbatas yang setiap elemennya terdiri dari tepat dua vertex yang berbeda [1]. Sementara itu, graf dikatakan berbobot (_weighted graph_) apabila terdapat bilangan riil yang diasosiasikan pada setiap sisi graf. Bobot tersebut umumnya digunakan untuk merepresentasikan jarak, waktu, atau biaya dalam suatu lintasan antar vertex [1].

Penerapan graf sangat luas dalam kehidupan nyata, seperti pada bidang transportasi, jaringan komputer, telekomunikasi, jaringan listrik, dan saluran air [1]. Dalam bidang-bidang tersebut, graf digunakan untuk memodelkan konektivitas antar titik serta menganalisis jalur yang paling efisien. Salah satu permasalahan penting dalam graf adalah penentuan jalur terpendek (_shortest path_) antara dua simpul, yang bertujuan untuk meminimalkan jarak, waktu, atau biaya perjalanan [1].

Teknik pencarian pada graf secara umum dibagi menjadi dua pendekatan, yaitu pencarian buta (_blind search_) dan pencarian heuristik (_heuristic search_). Pencarian buta lebih mudah dipahami karena tidak menggunakan informasi tambahan, namun cenderung kurang efisien. Sebaliknya, pencarian heuristik memanfaatkan fungsi evaluasi sehingga hasil pencarian lebih variatif dan waktu pencarian solusi menjadi lebih cepat [1]. Beberapa algoritma yang sering digunakan dalam pencarian jalur terpendek antara lain algoritma Dijkstra, Floyd–Warshall, Bellman–Ford, Ford–Fulkerson, Distance Vector, Ant Colony Optimization, serta algoritma A-Star (A*), yang dirancang untuk memperoleh solusi paling efektif dan efisien dalam analisis lintasan pada graf [1].
___
## Guided
___
#### 1. Guided 1 
```C++
file graph_edge.cpp

#include "graph.h"

adrNode findNode(Graph &G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd   = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; // insert first pada list edge
        pStart->firstEdge = newEdge;
    }
}
```

```C++
file graph_init.cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

```C++
file graph_print.cpp
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node: " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

```C++
file graph.h
##ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// ALIAS
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

// STRUCT NODE
struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

// STRUCT EDGE
struct ElmEdge {
    adrNode node;
    adrEdge next;
};

// STRUCT GRAPH
struct Graph {
    adrNode first;
};

// PROTOTYPE
void createGraph(Graph &G);
adrNode allocNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

```C++
file main.cpp
#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // menambah node
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // menghubungkan node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi graph:" << endl;
    printGraph(G);

    return 0;
}
```
##### Penjelasan Singkat
Program ini mengimplementasikan struktur data **graph berarah** menggunakan **adjacency list** berbasis linked list. Graph terdiri dari list node utama (`ElmNode`) yang saling terhubung melalui pointer `next`, di mana setiap node menyimpan informasi `info`, status `visited`, serta pointer `firstEdge` yang menunjuk ke list edge miliknya. Edge direpresentasikan oleh struktur `ElmEdge` yang menyimpan alamat node tujuan (`node`) dan pointer `next` untuk menghubungkan edge-edge lain. Dengan struktur ini, setiap node dapat memiliki lebih dari satu relasi ke node lain secara efisien.

Proses pembuatan graph dimulai dari inisialisasi graph kosong, penambahan node ke akhir list utama, lalu penghubungan antar node menggunakan fungsi `connectNode`. Fungsi ini terlebih dahulu mencari node asal dan tujuan, kemudian menambahkan edge baru ke awal list edge node asal (insert first). Penampilan isi graph dilakukan dengan menelusuri setiap node dan mencetak seluruh node tujuan yang terhubung dengannya. Pada `main`, graph diisi dengan beberapa node dan relasi, kemudian dicetak untuk menunjukkan hubungan antar node sesuai adjacency list yang terbentuk.
___
## Unguided
___
### 1. Buatlah ADT Graph tidak berarah file “graph.h”, Buatlah prosedur untuk menampilkanhasil penelusuran DFS, prosedur PrintDFS (Graph G, adrNode N), Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintBFS (Graph G, adrNode N);
```C++
file graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void DFS(Graph G, adrNode P, bool visited[]);
void PrintDFS(Graph G, char start);

void PrintBFS(Graph G, char start);

#endif
```

```C++
file graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, adrNode N1, adrNode N2) {
    adrEdge E = new ElmEdge;
    E->node = N2;
    E->next = N1->firstEdge;   // insert first
    N1->firstEdge = E;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;

    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;

        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }

        cout << endl;
        P = P->next;
    }
}

void DFS(Graph G, adrNode P, bool visited[]) {
    if (P == NULL) return;

    cout << P->info << " ";
    visited[P->info - 'A'] = true;

    vector<char> neighbours;
    adrEdge E = P->firstEdge;

    while (E != NULL) {
        neighbours.push_back(E->node->info);
        E = E->next;
    }

    sort(neighbours.begin(), neighbours.end());

    for (char c : neighbours) {
        adrNode nextNode = FindNode(G, c);
        if (!visited[c - 'A']) {
            DFS(G, nextNode, visited);
        }
    }
}

void PrintDFS(Graph G, char start) {
    adrNode P = FindNode(G, start);
    if (P == NULL) {
        cout << "Node tidak ditemukan.\n";
        return;
    }

    bool visited[26] = {false};

    cout << "DFS mulai dari " << start << " : ";
    DFS(G, P, visited);
    cout << endl;
}

void PrintBFS(Graph G, char start) {
    bool visited[26] = {false};

    adrNode P = FindNode(G, start);
    if (P == NULL) {
        cout << "Node tidak ditemukan.\n";
        return;
    }

    queue<adrNode> Q;
    Q.push(P);
    visited[P->info - 'A'] = true;

    cout << "Hasil BFS mulai dari " << start << " : ";

    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();

        cout << curr->info << " ";

        vector<char> tetangga;
        adrEdge E = curr->firstEdge;

        while (E != NULL) {
            tetangga.push_back(E->node->info);
            E = E->next;
        }

        sort(tetangga.begin(), tetangga.end());

        for (char c : tetangga) {
            adrNode nextNode = FindNode(G, c);
            if (!visited[c - 'A']) {
                visited[c - 'A'] = true;
                Q.push(nextNode);
            }
        }
    }

    cout << endl;
}
```

```C++
file main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode NodeG = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(G, A, B);
    ConnectNode(G, A, C);
    ConnectNode(G, B, D);
    ConnectNode(G, B, E);
    ConnectNode(G, C, F);
    ConnectNode(G, C, NodeG);
    ConnectNode(G, D, H);
    ConnectNode(G, E, H);
    ConnectNode(G, F, H);
    ConnectNode(G, NodeG, H);

    PrintInfoGraph(G);
    PrintDFS(G, 'A');
    PrintBFS(G, 'A');

    return 0;
}
```

##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan14/output/output1.png)
##### Penjelasan Output 1
Output tersebut menampilkan **representasi graph dalam bentuk adjacency list**. Setiap baris menunjukkan **satu node** dan **node-node tujuan** yang terhubung langsung darinya (graph berarah).  
Contohnya, `Node A terhubung ke: C B` berarti terdapat edge dari **A → C** dan **A → B**. Urutan C lalu B terjadi karena **edge dimasukkan dengan metode insert first**, sehingga koneksi yang terakhir ditambahkan akan tampil lebih dulu.

Node B terhubung ke E dan D, node C ke G dan F, sedangkan node D, E, F, dan G masing-masing terhubung ke H. Node H tidak memiliki edge keluar, sehingga ditampilkan tanpa tujuan. Output ini memastikan bahwa seluruh relasi antar node berhasil disimpan dan ditampilkan sesuai struktur adjacency list yang dibuat di program.

##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan14/output/output2.png)
##### Penjelasan Unguided 1
Bagian awal output menampilkan **struktur graph dalam bentuk adjacency list** dengan format ringkas (misalnya `A : C B`), yang menunjukkan node A memiliki koneksi berarah ke C dan B. Urutan tetangga tetap mengikuti mekanisme **insert first** pada edge, sehingga node yang terakhir dihubungkan akan tampil lebih dulu.

Baris **`DFS mulai dari A : A B D H E C F G`** menunjukkan hasil **penelusuran Depth First Search (DFS)** dengan titik awal node A. DFS menelusuri graph dengan masuk sedalam mungkin ke satu cabang sebelum kembali (backtracking) ke cabang lain. Urutan tersebut mencerminkan traversal DFS yang dilakukan berdasarkan **urutan tetangga yang sudah diurutkan alfabetis** sebelum proses rekursif, sehingga hasil traversal konsisten dan terkontrol.

##### Output 3
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan14/output/output3.png)
##### Penjelasan Unguided 1
Output ini menampilkan tiga bagian utama. Pertama, ditunjukkan **struktur graph dalam bentuk adjacency list**, di mana setiap baris memperlihatkan node beserta node tujuan yang terhubung langsung dengannya. Urutan tetangga (misalnya `A : C B`) dipengaruhi oleh metode **insert first** saat penambahan edge.

Kedua, hasil **DFS mulai dari node A** yaitu `A B D H E C F G`. DFS bekerja dengan menelusuri graph sedalam mungkin pada satu cabang sebelum berpindah ke cabang lain (backtracking), sehingga node H dikunjungi lebih awal karena berada di jalur terdalam dari A → B → D → H.

Ketiga, hasil **BFS mulai dari node A** yaitu `A B C D E F G H`. BFS menelusuri graph **per level** menggunakan antrian (queue), sehingga semua tetangga langsung A dikunjungi lebih dulu sebelum melanjutkan ke level berikutnya. Perbedaan urutan DFS dan BFS ini menunjukkan perbedaan strategi penelusuran graph.
___
## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data **graph** dapat direpresentasikan secara efektif menggunakan **adjacency list** berbasis linked list untuk menyimpan hubungan antar simpul. Implementasi graph memungkinkan pemodelan relasi antar node secara terstruktur, baik dalam penambahan node, penghubungan antar node, maupun penampilan data graph.

Selain itu, proses penelusuran graph menggunakan algoritma **Depth First Search (DFS)** dan **Breadth First Search (BFS)** berhasil diimplementasikan dengan baik. DFS menelusuri graph dengan pendekatan mendalam pada satu cabang terlebih dahulu, sedangkan BFS menelusuri graph secara bertahap per level. Perbedaan hasil traversal DFS dan BFS menunjukkan bahwa setiap algoritma memiliki karakteristik dan kegunaan masing-masing sesuai kebutuhan penelusuran graph.
___
## Referensi
[1] Dalem, I. B. G. W. A. (2018). Penerapan algoritma A*(Star) menggunakan graph untuk menghitung jarak terpendek. _Jurnal RESISTOR (Rekayasa Sistem Komputer)_, _1_(1), 41-47.