<h1 align = "center">Laporan Praktikum Modul 6<br>DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
### **Doubly Linked List**

Doubly Linked List merupakan salah satu struktur data dinamis yang menggunakan konsep pointer untuk menghubungkan antar node. Setiap node pada Doubly Linked List memiliki tiga buah field utama, yaitu:

1. **Field data**, yang menyimpan informasi atau nilai dari node tersebut.
2. **Pointer next**, yang menunjuk ke node berikutnya dalam urutan.
3. **Pointer prev**, yang menunjuk ke node sebelumnya.

Berbeda dengan singly linked list yang hanya memiliki satu arah hubungan, doubly linked list memungkinkan proses traversal dilakukan dua arah, baik maju maupun mundur. Pada kondisi awal, pointer **next** dari node terakhir dan pointer **prev** dari node pertama bernilai **NULL** sebagai penanda bahwa tidak ada node di arah tersebut. Struktur ini mempermudah operasi seperti penyisipan (insertion) dan penghapusan (deletion) data karena tidak perlu melintasi seluruh list dari awal [1].

___
## Guided
___
#### 1. Guided 1
```C++
file listMakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama
         << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama
         << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev) {
    if (isEmpty(List) == true) {
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil) {
            if (nodePrev == List.last) {
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama
                     << " berhasil ditambahkan setelah node "
                     << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext) {
    if (isEmpty(List) == true) {
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil) {
            if (nodeNext == List.first) {
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama
                     << " berhasil ditambahkan sebelum node "
                     << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); // menghapus newline dari buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); // menghapus newline dari buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "
                 << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus newline dari buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil) {
            address nodeBantu = nodeNext->prev;
            cout << "Masukkan update data node sebelum node "
                 << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus newline dari buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}

```

```C++
file listMakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan {
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;
typedef struct node *address;

struct node {
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist {
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

```C++
file listMakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi **struktur data Doubly Linked List** yang digunakan untuk menyimpan dan mengelola data makanan secara dinamis. Setiap node pada list menyimpan informasi makanan berupa _nama_, _jenis_, _harga_, dan _rating_, serta memiliki dua pointer: `next` untuk menunjuk ke node berikutnya dan `prev` untuk menunjuk ke node sebelumnya.

Fungsi `createList()` digunakan untuk menginisialisasi list agar kosong di awal (pointer `first` dan `last` bernilai `Nil`). Pembuatan node baru dilakukan melalui fungsi `alokasi()`, sedangkan `dealokasi()` digunakan untuk menghapus node dari memori.

Operasi penambahan data dilakukan menggunakan fungsi `insertFirst()`, `insertLast()`, `insertAfter()`, dan `insertBefore()` sesuai posisi yang diinginkan. Setiap fungsi mengatur pointer `next` dan `prev` agar node baru terhubung dua arah. Sedangkan fungsi `printList()` menampilkan seluruh isi list secara berurutan mulai dari node pertama.

Selain itu, program juga menyediakan fitur pembaruan data melalui fungsi `updateFirst()`, `updateLast()`, `updateAfter()`, dan `updateBefore()` untuk memodifikasi isi node tertentu.  
Pada fungsi `main()`, beberapa data makanan seperti _Nasi Rames_, _Ayam Geprek_, dan _Mie Ayam_ dimasukkan ke dalam list menggunakan berbagai metode penyisipan, lalu dilakukan proses _update_ untuk mengubah nilai yang telah tersimpan.

#### 2. Guided 2
```C++
file Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { // blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { // alokasi elemen baru
    address P = new ElmList;   // alokasi memori untuk elemen baru
    P->info = x;               // isi bagian info
    P->next = Nil;             // belum terhubung ke list
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; // menghapus elemen dan kembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {        // list kosong
        L.first = P;
        L.last  = P;
    } else {                    // list ada isinya
        P->prev = L.last;       // prev P menunjuk ke elemen terakhir
        (L.last)->next = P;     // next elemen terakhir menunjuk ke P
        L.last = P;             // perbarui last
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first;        // mulai dari elemen pertama
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;           // ketemu
        }
        P = P->next;            // lanjut ke elemen berikutnya
    }
    return Nil;                 // tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            // Kasus 1: hanya 1 elemen
            L.first = Nil;
            L.last  = Nil;
        } else if (P == L.first) {
            // Kasus 2: hapus elemen pertama
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            // Kasus 3: hapus elemen terakhir
            L.last = P->prev;
            (L.last)->next = Nil;
            P->prev = Nil;
        } else {
            // Kasus 4: hapus di tengah
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ;
            Succ->prev = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

```C++
file Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan {
    string nopol;
    string warna;
    int    thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address  next;
    address  prev;
};

// Tipe list
struct List {
    address first; // pointer ke elemen pertama
    address last;  // pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);
#endif
```

```C++
file main.cpp
#include "Doublylist.h"
using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L;
    CreateList(L);

    address P;
    infotype data;

    data = {"D001", "hitam", 90};  P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70};  P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);

    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Ditemukan: " << found->info.nopol
             << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol);
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol);
    cout << endl;

    printInfo(L);

    return 0;
}```

##### Penjelasan Singkat
Program ini merupakan implementasi **Doubly Linked List** untuk menyimpan data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan.  
Setiap node memiliki dua pointer: `next` (ke elemen berikutnya) dan `prev` (ke elemen sebelumnya), sehingga data dapat ditelusuri dua arah.

Fungsi `CreateList()` membuat list kosong, `alokasi()` membuat node baru, dan `dealokasi()` menghapus node dari memori.  
Penambahan data dilakukan dengan `insertLast()`, pencarian dengan `findElm()`, dan penghapusan berdasarkan nomor polisi menggunakan `deleteByNopol()`.  
Fungsi `printInfo()` menampilkan seluruh isi list.

Dalam `main()`, beberapa data kendaraan dimasukkan, lalu dilakukan pencarian dan penghapusan elemen tertentu.  
Program ini menunjukkan cara kerja operasi dasar **insert, search, dan delete** pada struktur **Doubly Linked List**.
 ___
## Unguided
___
#### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”

```C++
file Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// tipe data info kendaraan
struct kendaraan {
    string nopol;
    string warna;
    int    thnBuat;
};
typedef kendaraan infotype;

// node & address
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address  next;
    address  prev;
};

// list
struct List {
    address first;
    address last;
};

// proto
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteByNopol(List &L, string nopol);
void printInfo(List L);

#endif

```

```C++
file Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last  = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last  = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) return;

    if (P == L.first && P == L.last) {
        L.first = Nil;
        L.last  = Nil;
    } else if (P == L.first) {
        L.first = P->next;
        L.first->prev = Nil;
    } else if (P == L.last) {
        L.last = P->prev;
        L.last->next = Nil;
    } else {
        address prec = P->prev;
        address succ = P->next;
        prec->next = succ;
        succ->prev = prec;
    }
    dealokasi(P);
}

void printInfo(List L) {
    address P = L.last;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi :  " << P->info.nopol << endl;
            cout << "warna     :  " << P->info.warna << endl;
            cout << "tahun     :  " << P->info.thnBuat << endl << endl;
            P = P->prev;
        }
    }
}

```

```C++
file main.cpp
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    // input 4 data seperti contoh
    for (int i = 0; i < 4; i++) {
        infotype data;

        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;

        // cek duplikat
        if (findElm(L, data.nopol) != Nil) {
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            cout << "nomor polisi sudah terdaftar" << endl << endl;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;
        cout << endl;

        address P = alokasi(data);
        insertLast(L, P);
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}```

##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan6/output/unguided1.png)
##### Penjelasan Unguided 1
Program ini merupakan implementasi **struktur data Doubly Linked List** untuk menyimpan data kendaraan yang terdiri dari _nomor polisi_, _warna kendaraan_, dan _tahun pembuatan_.  
Setiap node memiliki dua pointer: `next` untuk menunjuk ke node berikutnya dan `prev` untuk menunjuk ke node sebelumnya, sehingga data dapat diakses dua arah.

Fungsi `CreateList()` digunakan untuk membuat list kosong, sedangkan `alokasi()` membuat node baru dan `dealokasi()` menghapus node dari memori.  
Proses penambahan elemen dilakukan menggunakan `insertLast()` agar data baru selalu ditambahkan di akhir list. Sebelum menambah data, fungsi `findElm()` digunakan untuk memastikan nomor polisi belum terdaftar agar tidak terjadi duplikasi.

Fungsi `printInfo()` menampilkan seluruh isi list dari elemen terakhir ke elemen pertama, sesuai urutan pada contoh output.  
Program utama menerima input dari pengguna, menolak data duplikat dengan menampilkan pesan _“nomor polisi sudah terdaftar”_, lalu menampilkan hasil akhir dalam format rapi seperti pada tampilan keluaran.

#### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

```C++
file Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// tipe data kendaraan
struct kendaraan {
    string nopol;
    string warna;
    int    thnBuat;
};
typedef kendaraan infotype;

// node
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address  next;
    address  prev;
};

// list
struct List {
    address first;
    address last;
};

// fungsi dasar
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

// operasi list
void insertLast(List &L, address P);
address findElm(List L, infotype x);
void deleteByNopol(List &L, string nopol);
void printInfo(List L);

#endif
```

```C++
file Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last  = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last  = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    // bungkus string jadi infotype karena findElm pakai infotype
    infotype key;
    key.nopol = nopol;

    address P = findElm(L, key);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            // hanya 1 elemen
            L.first = Nil;
            L.last  = Nil;
        } else if (P == L.first) {
            // hapus di depan
            L.first = P->next;
            L.first->prev = Nil;
        } else if (P == L.last) {
            // hapus di belakang
            L.last = P->prev;
            L.last->next = Nil;
        } else {
            // hapus di tengah
            address prec = P->prev;
            address succ = P->next;
            prec->next = succ;
            succ->prev = prec;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.last;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi :  " << P->info.nopol  << endl;
            cout << "warna     :  " << P->info.warna  << endl;
            cout << "tahun     :  " << P->info.thnBuat << endl << endl;
            P = P->prev;
        }
    }
}
```

```C++
file main.cpp
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    // input 4x sesuai contoh
    for (int i = 0; i < 4; i++) {
        infotype data;

        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;

        // karena findElm() parameternya infotype, kita bungkus dulu
        infotype key;
        key.nopol = data.nopol;

        // cek duplikat
        if (findElm(L, key) != Nil) {
            // tetap minta warna & tahun (biar mirip contoh soal)
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            cout << "nomor polisi sudah terdaftar" << endl << endl;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;
        cout << endl;

        address P = alokasi(data);
        insertLast(L, P);
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    // cari elemen
    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cari.nopol;
    cout << endl;

    address hasil = findElm(L, cari);
    if (hasil != Nil) {
        cout << "Nomor Polisi : " << hasil->info.nopol  << endl;
        cout << "Warna        : " << hasil->info.warna  << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}
}```

##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan6/output/unguided2.png)
##### Penjelasan Unguided 2
Program ini merupakan implementasi **struktur data Doubly Linked List** yang digunakan untuk menyimpan, mencari, dan menghapus data kendaraan berdasarkan nomor polisi.  
Setiap node pada list menyimpan data berupa _nomor polisi (nopol)_, _warna kendaraan_, dan _tahun pembuatan_, serta memiliki dua pointer:

- `next` untuk menunjuk ke node berikutnya,
- `prev` untuk menunjuk ke node sebelumnya.

Fungsi `CreateList()` digunakan untuk menginisialisasi list agar kosong.  
Fungsi `alokasi()` membuat node baru, sedangkan `dealokasi()` menghapus node dari memori.  
Data baru dimasukkan ke akhir list menggunakan `insertLast()`.

Untuk pencarian data, digunakan fungsi `findElm()` yang menelusuri list berdasarkan `nopol`.  
Sebelum data dimasukkan, program akan mengecek apakah `nopol` sudah ada, dan menampilkan pesan _"nomor polisi sudah terdaftar"_ jika ditemukan duplikat.

Fungsi `printInfo()` menampilkan seluruh isi list dari elemen terakhir ke elemen pertama agar urutan output sesuai dengan contoh.  
Selain itu, tersedia fungsi `deleteByNopol()` yang dapat menghapus node berdasarkan nomor polisi dengan memperhatikan posisi node (awal, tengah, atau akhir list).

Di fungsi `main()`, program meminta input dari pengguna sebanyak empat kali untuk mengisi data kendaraan, melakukan pengecekan duplikat, menampilkan isi list, dan melakukan pencarian data berdasarkan nomor polisi yang dimasukkan.

Program ini menunjukkan implementasi dasar operasi **insert, search, delete, dan traversal** pada struktur **Doubly Linked List** secara lengkap dan interaktif.

#### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.

```C++
file Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// ===== tipe data =====
struct kendaraan {
    string nopol;
    string warna;
    int    thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address  next;
    address  prev;
};

struct List {
    address first;
    address last;
};

// ===== fungsi/prosedur dasar =====
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

// pencarian berdasarkan nopol (pakai infotype)
address findElm(List L, infotype x);

// prosedur delete sesuai soal
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

```C++
file Doublylist.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last  = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last  = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// cetak dari belakang ke depan biar mirip contoh
void printInfo(List L) {
    address P = L.last;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "Nomor Polisi  : " << P->info.nopol  << endl;
            cout << "Warna         : " << P->info.warna  << endl;
            cout << "Tahun         : " << P->info.thnBuat << endl << endl;
            P = P->prev;
        }
    }
}

// cari node berdasarkan nopol
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// =================== DELETE ===================

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (P != Nil) {
        if (L.first == L.last) {         // hanya 1 elemen
            L.first = Nil;
            L.last  = Nil;
        } else {
            L.first = P->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (P != Nil) {
        if (L.first == L.last) {         // hanya 1 elemen
            L.first = Nil;
            L.last  = Nil;
        } else {
            L.last = P->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}
```

```C++
file main.cpp
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    // isi data awal seperti di contoh
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

    // cari node-nya
    address target = findElm(L, key);

    if (target != Nil) {
        address P; // penampung node yang dihapus

        if (target == L.first) {
            deleteFirst(L, P);
        } else if (target == L.last) {
            deleteLast(L, P);
        } else {
            // node di tengah → deleteAfter(node sebelum target)
            address prec = target->prev;
            deleteAfter(prec, P);
        }

        // buang dari memori
        dealokasi(P);

        cout << "Data dengan nomor polisi " << key.nopol
             << " berhasil dihapus." << endl << endl;
    } else {
        cout << "Data dengan nomor polisi " << key.nopol
             << " tidak ditemukan." << endl << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}```

##### Output 3
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan6/output/unguided3.png)
##### Penjelasan Unguided 3
Program ini merupakan implementasi **Doubly Linked List** yang menambahkan fitur **penghapusan elemen (delete)** berdasarkan _nomor polisi kendaraan_.  
Setiap node pada list menyimpan data kendaraan berupa _nopol_, _warna_, dan _tahun pembuatan_, serta memiliki dua pointer (`next` dan `prev`) yang memungkinkan penelusuran maju maupun mundur.

Tiga prosedur penghapusan disediakan sesuai teori:

- `deleteFirst()` → menghapus elemen pertama,
- `deleteLast()` → menghapus elemen terakhir,
- `deleteAfter()` → menghapus elemen di tengah setelah node tertentu (_prec_).

Pada program utama (`main()`), list diisi dengan beberapa data kendaraan (`D001`, `D003`, `D004`).  
Kemudian pengguna memasukkan nomor polisi yang ingin dihapus, misalnya `D003`.  
Program mencari node dengan fungsi `findElm()`, lalu menentukan posisi node tersebut:

- jika berada di awal → `deleteFirst()` dipanggil,
- jika di akhir → `deleteLast()` dipanggil,
- jika di tengah → `deleteAfter()` dijalankan dengan argumen node sebelumnya (`prev`).

Setelah node dihapus dan didealokasikan dari memori, program menampilkan pesan _“Data dengan nomor polisi D003 berhasil dihapus”_, lalu mencetak sisa isi list menggunakan `printInfo()`.
___
## Kesimpulan
Dari praktikum **Modul 6: Doubly Linked List (Bagian Pertama)** dapat disimpulkan bahwa **Doubly Linked List** adalah struktur data dinamis yang memungkinkan traversal dua arah melalui pointer `next` dan `prev`.  
Struktur ini mempermudah proses **penambahan**, **pencarian**, dan **penghapusan** data dibanding _singly linked list_.

Melalui percobaan, mahasiswa mempelajari cara membuat list, menambah node di berbagai posisi, mencari elemen dengan `findElm()`, serta menghapus data menggunakan prosedur `deleteFirst()`, `deleteLast()`, dan `deleteAfter()`.  
Praktikum ini memperkuat pemahaman tentang pengelolaan pointer dan memori dalam struktur data dinamis.
___
## Referensi
[1] Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. _INFOKOM (Informatika & Komputer)_, _7_(2), 15-24.