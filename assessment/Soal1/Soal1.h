#ifndef SOAL1_H
#define SOAL1_H
using namespace std;
#include <string>

typedef Node* address;

struct Node {
    string nama;
    Node *next;
};


// operasi list
void insertLast(Node* &head, string nama);
void deleteName(Node* &head, string nama);
void view(Node* head);
int hitungGenap(Node* head);

#endif
