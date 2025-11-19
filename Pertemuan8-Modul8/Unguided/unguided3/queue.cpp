#include "queue.h"
#include <iostream>
using namespace std;

// QUEUE ALTERNATIF 3 (CIRCULAR QUEUE: HEAD & TAIL BERPUTAR)

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    // Penuh kalau posisi tail berikutnya sama dengan head
    if (isEmptyQueue(Q)) return false;
    return ((Q.tail + 1) % MAX_QUEUE == Q.head);
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
        // tail berputar (circular)
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1; // nilai penanda, sesuaikan dengan kebutuhan
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        // Hanya satu elemen, setelah dihapus jadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        // head berputar (circular)
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE; // maju melingkar
    }
    cout << endl;
}