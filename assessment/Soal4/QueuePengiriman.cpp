#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}  

bool isEmpty(QueueEkspedisi &Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(QueueEkspedisi &Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

// sekarang enqueue punya parameter paket newPaket
void enqueue(QueueEkspedisi &Q, paket newPaket) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.dataPaket[Q.tail] = newPaket;
}

void dequeue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    cout << "Isi Queue Ekspedisi:\n";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << "Kode Resi: " << Q.dataPaket[i].KodeResi
             << ", Nama Pengirim: " << Q.dataPaket[i].NamaPengirim
             << ", Berat Barang: " << Q.dataPaket[i].BeratBarang
             << ", Tujuan: " << Q.dataPaket[i].Tujuan << endl;
    }
}

void totalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    int totalBiaya = 0;
    for (int i = Q.head; i <= Q.tail; i++) {
        totalBiaya += Q.dataPaket[i].BeratBarang * 8250; 
    }

    cout << "Total Biaya Pengiriman: Rp " << totalBiaya << endl;
}