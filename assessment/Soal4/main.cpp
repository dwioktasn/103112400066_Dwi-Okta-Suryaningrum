#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int menu;
    paket newPaket;

    do {
        cout << "\n--- Komaniya Express ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket (Dequeue)\n";
        cout << "3. Tampilkan Data Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan Kode Resi: ";
            cin >> newPaket.KodeResi;

            cout << "Masukkan Nama Pengirim: ";
            cin >> newPaket.NamaPengirim;

            cout << "Masukkan Berat Barang (kg): ";
            cin >> newPaket.BeratBarang;

            cout << "Masukkan Tujuan: ";
            cin >> newPaket.Tujuan;

            enqueue(Q, newPaket);
        }

        else if (menu == 2) {
            dequeue(Q);
        }

        else if (menu == 3) {
            viewQueue(Q);
            totalBiayaPengiriman(Q);
        }

        else if (menu == 0) {
            cout << "Program selesai.\n";
        }

        else {
            cout << "Menu tidak valid!\n";
        }

    } while (menu != 0);

    return 0;
}