#include "Soal2.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil && List.last == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last  = Nil;
}

void insertLast(linkedlist &List, int nilai) {

    address P = new Node;
    P->isiNilai.nilai = nilai;
    P->next = Nil;
    P->prev = Nil;

    // kalau list masih kosong
    if (isEmpty(List)) {
        List.first = P;
        List.last  = P;
    } else {
        // sambungkan di belakang
        P->prev = List.last;
        List.last->next = P;
        List.last = P;
    }
}

void deleteNilai(linkedlist &List, int nilai) {
    if (isEmpty(List)) return;

    address P = List.first;

    // cari nilai
    while (P != Nil && P->isiNilai.nilai != nilai) {
        P = P->next;
    }

    // kalau ketemu
    if (P != Nil) {
        // kasus 1: node di depan
        if (P == List.last) {
            List.last = P->prev;
            List.last->next = Nil;
        }
        // kasus 3: node di tengah
        else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }

        delete P;
    }
}

void view(linkedlist List) {
    address P = List.first;
    while (P != Nil) {
        cout << P->isiNilai.nilai;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void reserveList(linkedlist &List) {
    if (isEmpty(List)) return;

    address current = List.first;
    address temp = Nil;

    // tukar next dan prev di setiap node
    while (current != Nil) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // karena sudah ditukar
    }

    // setelah loop, temp ada di node lama terakhir
    if (temp != Nil) {
        List.last = List.first;
        List.first = temp->prev;  // head baru
    }
}
