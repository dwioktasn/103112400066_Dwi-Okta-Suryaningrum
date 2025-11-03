#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    // isi data awal: D001, D003, D004 (persis contoh)
    infotype data;

    data = {"D001", "hitam", 90};
    insertLast(L, alokasi(data));

    data = {"D003", "putih", 70};
    insertLast(L, alokasi(data));

    data = {"D004", "kuning", 90};
    insertLast(L, alokasi(data));

    // minta nopol yang akan dihapus
    infotype key;
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> key.nopol;

    // cari dulu
    address target = findElm(L, key);

    if (target != Nil) {
        address P; // untuk menampung node yang dihapus

        if (target == L.first) {
            deleteFirst(L, P);
        } else if (target == L.last) {
            deleteLast(L, P);
        } else {
            // deleteAfter butuh pointer ke sebelum target
            address prec = target->prev;
            deleteAfter(prec, P);
        }

        // setelah dihapus boleh dealokasi
        dealokasi(P);

        cout << "Data dengan nomor polisi " << key.nopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << key.nopol << " tidak ditemukan." << endl << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}
