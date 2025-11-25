#include "Soal1.h"
#include <iostream>
using namespace std;

void insertLast(Node* &head, string nama) {
    Node* p = new Node;
    p->nama = nama;
    p->next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        Node* q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void deleteName(Node* &head, string nama) {
    if (head == NULL) return;

    if (head->nama == nama) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL && curr->nama != nama) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        prev->next = curr->next;
        delete curr;
    }
}

void view(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->nama;
        if (p->next != NULL) cout << " ";
        p = p->next;
    }
    cout << endl;
}

int hitungGenap(Node* head) {
    int jumlah = 0;
    Node* p = head;

    while (p != NULL) {
        if (p->nama.length() % 2 == 0) {
            jumlah++;
        }
        p = p->next;
    }

    return jumlah;
}