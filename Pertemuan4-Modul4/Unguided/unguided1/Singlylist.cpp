#include "Singlylist.h"
using namespace std;

void createList(list &L) {
    L.first = Nil;
}

bool isEmpty(const list &L) {
    return L.first == Nil;
}

address alokasi(int value) {
    address nodeBaru = new node;
    nodeBaru->isidata.info = value;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void insertFirst(list &L, address P) {
    if (P == Nil) return;
    P->next = L.first;
    L.first = P;
}

void printInfo(const list &L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }
    address bantu = L.first;
    while (bantu != Nil) {
        cout << bantu->isidata.info << " ";
        bantu = bantu->next;
    }
    cout << "\n";
}
