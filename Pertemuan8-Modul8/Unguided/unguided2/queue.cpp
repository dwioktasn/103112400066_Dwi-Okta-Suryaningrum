#include "queue.h"
#include <iostream>
using namespace std;

// QUEUE ALTERNATIF 2 (HEAD BERGERAK, TAIL BERGERAK)

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    // Karena tidak ada perputaran, queue penuh jika tail sudah di indeks terakhir
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        // Pertama kali isi queue
        Q.head = 0;
        Q.tail = 0;
    } else {
        // Tail selalu maju ke kanan
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;          // nilai penanda, bisa disesuaikan
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        // Hanya ada satu elemen, setelah dihapus queue jadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        // Head maju ke kanan, TIDAK menggeser elemen
        Q.head++;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    // Elemen aktif berada di antara head dan tail
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
