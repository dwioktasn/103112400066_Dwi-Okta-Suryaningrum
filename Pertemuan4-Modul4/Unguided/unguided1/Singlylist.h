#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#define Nil nullptr

// data yang disimpan per node (satu bilangan)
struct dataList {
    int info;
};

// deklarasi maju
struct node;
using address = node*;

struct node {
    dataList isidata;
    address next;
};

struct list {
    address first;
};

// API
void createList(list &L);
bool isEmpty(const list &L);
address alokasi(int value);
void dealokasi(address &P);
void printInfo(const list &L);
void insertFirst(list &L, address P);

#endif
