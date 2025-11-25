#ifndef SOAL2_H
#define SOAL2_H

#define Nil NULL


struct Node;

// bikin alias pointer ke Node
typedef Node* address;

struct dataNilai {
    int nilai;
};

struct Node {
    dataNilai isiNilai;
    address next;
    address prev;
};

struct linkedlist {
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
void insertLast(linkedlist &List, int nilai);
void deleteNilai(linkedlist &List, int nilai);
void view(linkedlist List);
void reserveList(linkedlist &List);   // fungsi reverse

#endif
