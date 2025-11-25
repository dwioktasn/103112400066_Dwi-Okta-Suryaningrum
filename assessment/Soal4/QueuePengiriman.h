#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

#define MAX_QUEUE 5

struct paket {
    string KodeResi;
    string NamaPengirim;
    int    BeratBarang;
    string Tujuan;   
};

struct QueueEkspedisi {
    paket dataPaket[MAX_QUEUE];
    int head;
    int tail;
};

// PROTOTYPE FUNGSI
bool isEmpty(QueueEkspedisi &Q);
bool isFull(QueueEkspedisi &Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q, paket newPaket);
void dequeue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi &Q);
void totalBiayaPengiriman(QueueEkspedisi &Q);

#endif