#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#define Nil nullptr

struct dataList { int info; };

// deklarasi maju
struct node;
using address = node*;

struct node {
    dataList isidata;
    address next;
};

struct list { address first; };

void createList(list &L);
bool isEmpty(const list &L);
address alokasi(int value);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void printInfo(const list &L);

void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address Prec, address &P);
int  nbList(const list &L);
void deleteList(list &L);

address findByValue(const list &L, int value);

#endif