#include "Singlylist.h"
using namespace std;

void createList(list &L) { L.first = Nil; }
bool isEmpty(const list &L) { return L.first == Nil; }

address alokasi(int value) {
    address nodeBaru = new node;
    nodeBaru->isidata.info = value;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    if (P != Nil) { delete P; P = Nil; }
}

void insertFirst(list &L, address P) {
    if (P == Nil) return;
    P->next = L.first;
    L.first = P;
}

void printInfo(const list &L) {
    address q = L.first;
    while (q != Nil) { cout << q->isidata.info << " "; q = q->next; }
    cout << "\n";
}

address findByValue(const list &L, int value) {
    address q = L.first;
    while (q != Nil) {
        if (q->isidata.info == value) return q;
        q = q->next;
    }
    return Nil;
}

void deleteFirst(list &L, address &P) {
    P = Nil;
    if (isEmpty(L)) return;
    P = L.first;
    L.first = L.first->next;
    P->next = Nil;
}

void deleteLast(list &L, address &P) {
    P = Nil;
    if (isEmpty(L)) return;

    // satu elemen
    if (L.first->next == Nil) {
        P = L.first;
        L.first = Nil;
        P->next = Nil;
        return;
    }
    // cari last & prev
    address prev = L.first;
    address cur  = L.first->next;
    while (cur->next != Nil) { prev = cur; cur = cur->next; }
    prev->next = Nil;
    P = cur;
    P->next = Nil;
}

void deleteAfter(list &L, address Prec, address &P) {
    P = Nil;
    if (Prec == Nil || Prec->next == Nil) return; // ga ada yang dihapus
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

int nbList(const list &L) {
    int n = 0;
    for (address q = L.first; q != Nil; q = q->next) ++n;
    return n;
}

void deleteList(list &L) {
    address p;
    while (!isEmpty(L)) {
        deleteFirst(L, p);
        dealokasi(p);
    }
}