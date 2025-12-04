#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

// deklarasi fungsi/prosedur
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root);
int hitungKedalaman(address root, int start);
int hitungTotalInfo(address root);
int hitungJumlahNode(address root);

#endif
