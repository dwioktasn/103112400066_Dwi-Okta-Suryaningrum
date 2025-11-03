#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// tipe data kendaraan
struct kendaraan {
    string nopol;
    string warna;
    int    thnBuat;
};
typedef kendaraan infotype;

// node & list
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address  next;
    address  prev;
};

struct List {
    address first;
    address last;
};

// fungsi dasar
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

// pencarian (pakai infotype -> cek x.nopol)
address findElm(List L, infotype x);

// prosedur delete sesuai slide
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
