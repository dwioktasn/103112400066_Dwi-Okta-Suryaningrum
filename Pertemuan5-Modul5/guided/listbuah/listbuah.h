// header ugard digunakan untuk mencegah file header yang sama
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    string jumlah;
    float harga;
};

typedef buah dataBuah; // memberikan nama alias databuah untuk struct buah

typedef  struct node *address; // mendefinisikan alias address sebagai pointer ke struct

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data dan pointer
    dataBuah isidata;
    address next;
};

struct linkedlist{ // ini linked listnya.
    address first;      
};

// semua function dan prosrfur yang akan dipakai
// materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev); 
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// materi modul 5 (part 1-update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address Prev);

#endif