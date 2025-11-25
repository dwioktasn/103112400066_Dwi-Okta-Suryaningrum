#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa StackMHS;
    createStack(StackMHS);

    Mahasiswa m1 = {"venti",    "11111", 75.7f, 82.1f, 65.5f};
    Mahasiswa m2 = {"Xiao",     "22222", 87.4f, 88.9f, 81.9f};
    Mahasiswa m3 = {"Kazuha",   "33333", 92.3f, 88.8f, 82.4f};
    Mahasiswa m4 = {"Wanderer", "44444", 95.5f, 85.5f, 90.5f};
    Mahasiswa m5 = {"Lynette",  "55555", 77.7f, 65.4f, 79.9f};
    Mahasiswa m6 = {"Chasca",   "66666", 99.9f, 93.6f, 87.3f};

    push(StackMHS, m1);
    push(StackMHS, m2);
    push(StackMHS, m3);
    push(StackMHS, m4);
    push(StackMHS, m5);
    push(StackMHS, m6);

    // contoh operasi
    view(StackMHS);                 // tampilkan isi stack
    pop(StackMHS);                  // hapus 1 data paling atas
    view(StackMHS);       
    cout << endl;          // tampilkan isi stack lagi
    update(StackMHS, 3);  
    cout << endl;          // update elemen ke-3 (indeks 3)
    view(StackMHS);                 // tampilkan isi stack lagi
    searchNilaiAkhir(StackMHS, 85.5, 95.5);  // cari nilai akhir di range ini

    return 0;
}