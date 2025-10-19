#include "Singlylist.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    list L; createList(L);

    // buat list: 9 -> 12 -> 8 -> 0 -> 2
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // hapus node 9 dengan deleteFirst()
    address p;
    deleteFirst(L, p); dealokasi(p);

    // hapus node 2 dengan deleteLast()
    deleteLast(L, p); dealokasi(p);

    // hapus node 8 dengan deleteAfter() (precursor = node 12)
    address prec = findByValue(L, 12);
    deleteAfter(L, prec, p); dealokasi(p);

    // sekarang list berisi: 12 0
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << "\n\n";

    // hapus seluruh list
    deleteList(L);
    cout << "- List Berhasil Terhapus -\n";
    cout << "Jumlah node : " << nbList(L) << "\n";

    system("read -p 'Press any key to continue...' var");
    return 0;
}