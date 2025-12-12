<h1 align = "center">Laporan Praktikum Modul 13<br>MULTI LINKED LIST</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
Multi Linked List N–N merupakan struktur data yang digunakan untuk merepresentasikan hubungan **banyak ke banyak (many-to-many)** antara dua atau lebih himpunan data. Berbeda dengan single linked list biasa, multi linked list memiliki lebih dari satu jenis list yang saling terhubung melalui pointer. Setiap elemen pada satu list dapat berelasi dengan satu atau lebih elemen pada list lain, dan sebaliknya [1].

Secara umum, struktur Multi Linked List N–N terdiri dari **list utama (parent)**, **list sekunder (child)**, serta **list relasi** atau mekanisme penghubung antar list. List utama dan list sekunder berfungsi menyimpan data (info), sedangkan relasinya diwujudkan melalui pointer yang menghubungkan elemen-elemen tersebut. Setiap elemen list memiliki field `info` untuk menyimpan data dan field `next` (serta `prev` pada double linked list) untuk menunjuk ke elemen berikutnya [1].

Pada implementasinya, Multi Linked List dapat dibangun menggunakan berbagai jenis linked list, seperti **Single Linked List**, **Double Linked List**, maupun **Circular Linked List**, tergantung kebutuhan sistem. Dalam konsep N–N, satu elemen pada list pertama dapat memiliki banyak relasi dengan elemen pada list kedua, dan satu elemen pada list kedua juga dapat terhubung dengan banyak elemen pada list pertama [1].
___
## Guided
___
#### 1. Guided 1 
```C++
file multilist.h

#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
#include <string>
using namespace std;

typedef struct nodeParent *NodeParent; // alias pointer ke struct nodeParent
typedef struct nodeChild  *NodeChild;  // alias pointer ke struct nodeChild

struct nodeChild { // node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak { // list child
    NodeChild first;
    NodeChild last;
};

struct nodeParent { // node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk { // list parent
    NodeParent first;
    NodeParent last;
};

// create list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

// alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

// alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodebaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

void insertLastChild(listAnak &LAnak, NodeChild nodebaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);

void printStrukturMll(listInduk LInduk);

#endif
```

```C++
file multilist.cpp
#include "multilist.h"
#include <iostream>

using namespace std;

// create list
void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

// alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if (nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

// alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if (nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

// operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if (LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent " << nodeBaruParent->namaKategoriMakanan
         << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while (nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev) {
    if (LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL) {
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL) {
                nodeHapus->next->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if (nodeHapus->L_Anak.first != NULL) {
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan
                 << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

// operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if (LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child " << nodeBaruChild->namaMakanan
         << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev) {
    if (LAnak.first == NULL) {
        cout << "List anak kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL) {
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL) {
                nodeHapus->next->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan
                 << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari) {
    if (LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        bool ketemu = false;

        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;

            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent "
                         << nodeBantuParent->namaKategoriMakanan
                         << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): "
                         << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : "
                         << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                }
                nodeBantuChild = nodeBantuChild->next;
                indexChild++;
            }

            if (ketemu) break;

            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }

        if (!ketemu) {
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

// operasi print
void printStrukturMll(listInduk LInduk) {
    if (LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;

        while (nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : "
                 << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : "
                 << nodeBantuParent->namaKategoriMakanan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if (nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while (nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

```C++
file main.cpp
#include "multilist.h"
#include <iostream>

using namespace std;

int main() {
    // 1. inisialisasi list
    listInduk LInduk;
    createListInduk(LInduk);

    // 2. membuat data parent (kategori makanan)
    NodeParent K01 = alokasiNodeParent("K001", "Makanan Berat");
    insertLastParent(LInduk, K01);

    NodeParent K02 = alokasiNodeParent("K002", "Minuman");
    insertLastParent(LInduk, K02);

    NodeParent K03 = alokasiNodeParent("K003", "Dessert");
    insertLastParent(LInduk, K03);

    cout << endl;

    // 3. memasukkan data child (menu makanan) ke kategori tertentu
    // --> isi kategori makanan berat (K01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);

    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);

    // --> isi kategori minuman (K02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);

    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);

    // --> isi kategori dessert (K03)
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);

    cout << endl;

    // 4. print mll setelah insert-insert
    printStrukturMll(LInduk);

    // 5. searching node child
    findChildByID(LInduk, "D01");
    cout << endl;

    // 6. delete node child
    deleteAfterChild(K01->L_Anak, M01); // hapus node ayam bakar
    cout << endl;

    // 7. delete node parent
    deleteAfterParent(LInduk, K02); // hapus node minuman
    cout << endl;

    // 8. print mll setelah delete
    printStrukturMll(LInduk);
    cout << endl;

    return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi **Multilevel Linked List (MLL)** dalam bahasa C++. Struktur data ini terdiri dari **list induk (parent)** untuk menyimpan kategori makanan dan **list anak (child)** untuk menyimpan menu makanan pada setiap kategori. Setiap node parent dapat memiliki lebih dari satu node child.

Pada fungsi `main()`, program dimulai dengan menginisialisasi list, kemudian menambahkan beberapa data kategori makanan sebagai parent dan data menu sebagai child menggunakan operasi insert. Program juga menyediakan fitur **pencarian data child berdasarkan ID** untuk menampilkan informasi child beserta parent-nya. Selain itu, program mendukung operasi **penghapusan data**, baik pada child maupun parent, di mana seluruh child dari parent yang dihapus akan ikut terhapus. Terakhir, struktur Multilevel Linked List ditampilkan ke layar untuk melihat hasil sebelum dan sesudah proses penghapusan.
 ___
## Unguided
___
### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”
```C++
file MultiLL.h
##ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;     // TRUE jika berekor, FALSE jika tidak berekor
    float bobot;   // dalam kg
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild  *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(
    string idHwn,
    string namaHwn,
    string habitat,
    bool tail,
    float weight
);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

#endif

```

```C++
file MultiLL.cpp
#include "MultiLL.h"

// =====================
// CEK KOSONG
// =====================
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

// =====================
// CREATE LIST
// =====================
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last  = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last  = NULL;
}

// =====================
// ALOKASI NODE
// =====================
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;

    P->isidata.idGolongan   = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    P->L_Child.first = NULL;
    P->L_Child.last  = NULL;

    return P;
}

NodeChild allocNodeChild(
    string idHwn,
    string namaHwn,
    string habitat,
    bool tail,
    float weight
) {
    NodeChild C = new nodeChild;

    C->isidata.idHewan   = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat   = habitat;
    C->isidata.ekor      = tail;
    C->isidata.bobot     = weight;
    C->next = NULL;
    C->prev = NULL;

    return C;
}

// =====================
// DEALOKASI NODE
// =====================
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

// =====================
// INSERT PARENT (DLL)
// =====================
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->next = LParent.first;
        newNParent->prev = NULL;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->prev = LParent.last;
        newNParent->next = NULL;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

// =====================
// DELETE PARENT (DLL)
// =====================
void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;

    NodeParent P = LParent.first;
    deleteListChild(P->L_Child);

    if (LParent.first == LParent.last) {
        LParent.first = NULL;
        LParent.last  = NULL;
    } else {
        LParent.first = P->next;
        LParent.first->prev = NULL;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeParent P = NPrev->next;
    deleteListChild(P->L_Child);

    if (P == LParent.last) {
        LParent.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = P->next;
        P->next->prev = NPrev;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

// =====================
// INSERT CHILD (DLL)
// =====================
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->next = LChild.first;
        newNChild->prev = NULL;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->prev = LChild.last;
        newNChild->next = NULL;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

// =====================
// DELETE CHILD (DLL)
// =====================
void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;

    NodeChild C = LChild.first;

    if (LChild.first == LChild.last) {
        LChild.first = NULL;
        LChild.last  = NULL;
    } else {
        LChild.first = C->next;
        LChild.first->prev = NULL;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeChild C = NPrev->next;

    if (C == LChild.last) {
        LChild.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = C->next;
        C->next->prev = NPrev;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

// =====================
// DELETE SEMUA CHILD
// =====================
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

// =====================
// PRINT MLL STRUCTURE
// =====================
void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int iParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << iParent << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << P->isidata.namaGolongan << "\n";

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int iChild = 1;

            while (C != NULL) {
                cout << " - Child " << iChild << " :\n";
                cout << "   ID Hewan : " << C->isidata.idHewan << "\n";
                cout << "   Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "   Habitat : " << C->isidata.habitat << "\n";
                cout << "   Ekor : " << (C->isidata.ekor ? "1" : "0") << "\n";
                cout << "   Bobot : " << C->isidata.bobot << "\n";
                C = C->next;
                iChild++;
            }
        }

        cout << "------------------------------\n";
        P = P->next;
        iParent++;
    }
}
```

```C++
file main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    NodeChild C11 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f);
    NodeChild C12 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0f);
    insertLastChild(P1->L_Child, C11);
    insertLastChild(P1->L_Child, C12);

    NodeChild C21 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f);
    NodeChild C22 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f);
    NodeChild C23 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0f);
    insertLastChild(P2->L_Child, C21);
    insertLastChild(P2->L_Child, C22);
    insertLastChild(P2->L_Child, C23);

    NodeChild C41 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f);
    insertLastChild(P4->L_Child, C41);

    printMLLStructure(LP);

    return 0;
}
```

##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan11/output/output1.png)
##### Penjelasan Unguided 1
Kode program tersebut digunakan untuk mengimplementasikan **Multi Level Linked List (MLL)** yang merepresentasikan hubungan antara **golongan hewan** sebagai data induk dan **data hewan** sebagai data anak. Struktur `golonganHewan` berfungsi untuk menyimpan informasi setiap golongan hewan, yaitu ID dan nama golongan, sedangkan struktur `dataHewan` digunakan untuk menyimpan detail hewan seperti ID hewan, nama, habitat, status ekor (berekor atau tidak), dan bobot. Setiap golongan hewan disimpan dalam `nodeParent`, yang saling terhubung menggunakan **double linked list** dan memiliki satu list anak (`L_Child`) untuk menampung hewan-hewan yang termasuk ke dalam golongan tersebut. Data hewan disimpan dalam `nodeChild`, yang juga disusun menggunakan double linked list pada masing-masing parent.

Cara kerja program dimulai dengan menginisialisasi list parent, kemudian membuat beberapa node parent menggunakan fungsi alokasi dan memasukkannya ke dalam list parent. Setelah itu, node child dibuat dan dimasukkan ke list child milik parent tertentu sesuai golongannya. Program juga menyediakan operasi penghapusan node parent maupun child, di mana saat parent dihapus seluruh child yang dimilikinya ikut dihapus untuk menghindari kebocoran memori. Terakhir, seluruh struktur Multi Level Linked List ditampilkan menggunakan fungsi cetak yang menelusuri list parent dan setiap list child di dalamnya, sehingga hubungan antara golongan hewan dan data hewan dapat terlihat dengan jelas.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.
```C++
file MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;      // TRUE jika berekor, FALSE jika tidak berekor
    float bobot;    // dalam kg
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild  *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn, string habitat,
                          bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif
```

```C++
file MultiLL.cpp
#include "MultiLL.h"

// =====================
// CEK KOSONG
// =====================
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

// =====================
// CREATE LIST
// =====================
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last  = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last  = NULL;
}

// =====================
// ALOKASI NODE
// =====================
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;

    P->isidata.idGolongan   = idGol;
    P->isidata.namaGolongan = namaGol;

    P->next = NULL;
    P->prev = NULL;

    P->L_Child.first = NULL;
    P->L_Child.last  = NULL;

    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;

    C->isidata.idHewan   = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat   = habitat;
    C->isidata.ekor      = tail;
    C->isidata.bobot     = weight;

    C->next = NULL;
    C->prev = NULL;

    return C;
}

// =====================
// DEALOKASI NODE
// =====================
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

// =====================
// INSERT PARENT (DLL)
// =====================
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->next = LParent.first;
        newNParent->prev = NULL;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->prev = LParent.last;
        newNParent->next = NULL;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

// =====================
// DELETE PARENT (DLL)
// =====================
void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;

    NodeParent P = LParent.first;

    deleteListChild(P->L_Child);

    if (LParent.first == LParent.last) {
        LParent.first = NULL;
        LParent.last  = NULL;
    } else {
        LParent.first = P->next;
        LParent.first->prev = NULL;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeParent P = NPrev->next;

    deleteListChild(P->L_Child);

    if (P == LParent.last) {
        LParent.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = P->next;
        P->next->prev = NPrev;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

// =====================
// INSERT CHILD (DLL)
// =====================
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->next = LChild.first;
        newNChild->prev = NULL;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->prev = LChild.last;
        newNChild->next = NULL;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

// =====================
// DELETE CHILD (DLL)
// =====================
void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;

    NodeChild C = LChild.first;

    if (LChild.first == LChild.last) {
        LChild.first = NULL;
        LChild.last  = NULL;
    } else {
        LChild.first = C->next;
        LChild.first->prev = NULL;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeChild C = NPrev->next;

    if (C == LChild.last) {
        LChild.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = C->next;
        C->next->prev = NPrev;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

// =====================
// DELETE SEMUA CHILD
// =====================
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

// =====================
// PRINT MLL STRUCTURE
// =====================
void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int iParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << iParent << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << P->isidata.namaGolongan << "\n";

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int iChild = 1;

            while (C != NULL) {
                cout << " - Child " << iChild << " :\n";
                cout << "   ID Hewan : " << C->isidata.idHewan << "\n";
                cout << "   Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "   Habitat : " << C->isidata.habitat << "\n";
                cout << "   Ekor : " << (C->isidata.ekor ? "1" : "0") << "\n";
                cout << "   Bobot : " << C->isidata.bobot << "\n";
                C = C->next;
                iChild++;
            }
        }

        cout << "------------------------------\n";
        P = P->next;
        iParent++;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int indexParent = 1;
    bool foundAny = false;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int indexChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << indexChild << "!\n";

                cout << "--- Data Child ---\n";
                cout << "ID Child : " << C->isidata.idHewan << "\n";
                cout << "Posisi dalam list anak : posisi ke-" << indexChild << "\n";
                cout << "Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "Habitat : " << C->isidata.habitat << "\n";
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << "\n";
                cout << "Bobot : " << C->isidata.bobot << "\n";

                cout << "------------------------------\n";

                cout << "--- Data Parent ---\n";
                cout << "ID Parent : " << P->isidata.idGolongan << "\n";
                cout << "Posisi dalam list induk : posisi ke-" << indexParent << "\n";
                cout << "Nama golongan : " << P->isidata.namaGolongan << "\n";

                cout << "------------------------------\n";

                foundAny = true;
            }

            C = C->next;
            indexChild++;
        }

        P = P->next;
        indexParent++;
    }

    if (!foundAny) {
        cout << "Tidak ada hewan dengan kriteria ekor yang dicari.\n";
    }
}
```

```C++
file main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    // =========================
    // INSERT PARENT
    // =========================
    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    // =========================
    // INSERT CHILD untuk G001 (Aves)
    // =========================
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0f));

    // =========================
    // INSERT CHILD untuk G002 (Mamalia)
    // urutan ini bikin M003 posisinya ke-2 (sesuai ekspektasi output)
    // =========================
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));

    // =========================
    // INSERT CHILD untuk G004 (Amfibi)
    // =========================
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));

    // =========================
    // PRINT (sesuai instruksi modul setelah INSERT)
    // =========================
    printMLLStructure(LP);

    // =========================
    // SEARCHING: cari hewan dengan EKOR = FALSE
    // (sesuai instruksi tugas & ekspektasi output)
    // =========================
    searchHewanByEkor(LP, false);

    return 0;
}
```

##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan11/output/output2.png)
##### Penjelasan Unguided 1
Kode ini adalah implementasi **Multi Level Linked List (MLL)** untuk menyimpan data hewan berdasarkan golongannya. Struktur `golonganHewan` dipakai untuk menyimpan informasi **parent** (ID dan nama golongan), sedangkan `dataHewan` dipakai untuk menyimpan informasi **child** (ID hewan, nama, habitat, status ekor true/false, dan bobot). Setiap golongan disimpan dalam `nodeParent` yang tersusun sebagai **double linked list** (punya `next` dan `prev`), dan di dalam setiap `nodeParent` ada `L_Child` yang merupakan **list child** berisi hewan-hewan pada golongan tersebut. Hewan-hewan disimpan dalam `nodeChild` yang juga double linked list, sehingga satu golongan bisa punya banyak hewan.

Cara kerjanya: program menginisialisasi list parent dengan `createListParent`, lalu membuat node parent menggunakan `allocNodeParent` dan memasukkannya ke list parent memakai `insertLastParent`. Setelah itu, node child dibuat menggunakan `allocNodeChild` dan dimasukkan ke list child milik parent tertentu dengan `insertLastChild`. Fungsi `printMLLStructure` kemudian menampilkan seluruh isi MLL dengan cara menelusuri parent satu per satu, lalu menelusuri child pada tiap parent dan mencetak datanya (nilai `ekor` dicetak menjadi **1** untuk true dan **0** untuk false). Selain itu ada fungsi `searchHewanByEkor` yang mencari semua hewan dengan kriteria ekor tertentu (misalnya `false`), lalu menampilkan data hewan yang cocok beserta informasi parent tempat hewan itu berada.
### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure().
```C++
file MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;      // TRUE jika berekor, FALSE jika tidak berekor
    float bobot;    // dalam kg
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild  *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn,
                          string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);
void printMLLStructure(listParent &LParent);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif
```

```C++
file MultiLL.cpp
#include "MultiLL.h"

// =====================
// CEK KOSONG
// =====================
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

// =====================
// CREATE LIST
// =====================
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last  = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last  = NULL;
}

// =====================
// ALOKASI NODE
// =====================
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;

    P->isidata.idGolongan   = idGol;
    P->isidata.namaGolongan = namaGol;

    P->next = NULL;
    P->prev = NULL;

    P->L_Child.first = NULL;
    P->L_Child.last  = NULL;

    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;

    C->isidata.idHewan   = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat   = habitat;
    C->isidata.ekor      = tail;
    C->isidata.bobot     = weight;

    C->next = NULL;
    C->prev = NULL;

    return C;
}

// =====================
// DEALOKASI NODE
// =====================
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

// =====================
// INSERT PARENT (DLL)
// =====================
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->next = LParent.first;
        newNParent->prev = NULL;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->prev = LParent.last;
        newNParent->next = NULL;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

// =====================
// DELETE PARENT (DLL)
// =====================
void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;

    NodeParent P = LParent.first;

    deleteListChild(P->L_Child);

    if (LParent.first == LParent.last) {
        LParent.first = NULL;
        LParent.last  = NULL;
    } else {
        LParent.first = P->next;
        LParent.first->prev = NULL;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeParent P = NPrev->next;

    deleteListChild(P->L_Child);

    if (P == LParent.last) {
        LParent.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = P->next;
        P->next->prev = NPrev;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

// =====================
// INSERT CHILD (DLL)
// =====================
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->next = LChild.first;
        newNChild->prev = NULL;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->prev = LChild.last;
        newNChild->next = NULL;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

// =====================
// DELETE CHILD (DLL)
// =====================
void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;

    NodeChild C = LChild.first;

    if (LChild.first == LChild.last) {
        LChild.first = NULL;
        LChild.last  = NULL;
    } else {
        LChild.first = C->next;
        LChild.first->prev = NULL;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeChild C = NPrev->next;

    if (C == LChild.last) {
        LChild.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = C->next;
        C->next->prev = NPrev;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

// =====================
// DELETE SEMUA CHILD
// =====================
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

// =====================
// PRINT MLL STRUCTURE
// =====================
void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int iParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << iParent << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << P->isidata.namaGolongan << "\n";

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int iChild = 1;

            while (C != NULL) {
                cout << " - Child " << iChild << " :\n";
                cout << "   ID Hewan : " << C->isidata.idHewan << "\n";
                cout << "   Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "   Habitat : " << C->isidata.habitat << "\n";
                cout << "   Ekor : " << (C->isidata.ekor ? "1" : "0") << "\n";
                cout << "   Bobot : " << C->isidata.bobot << "\n";
                C = C->next;
                iChild++;
            }
        }

        cout << "------------------------------\n";
        P = P->next;
        iParent++;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int indexParent = 1;
    bool foundAny = false;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int indexChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << indexChild << "!\n";

                cout << "--- Data Child ---\n";
                cout << "ID Child : " << C->isidata.idHewan << "\n";
                cout << "Posisi dalam list anak : posisi ke-" << indexChild << "\n";
                cout << "Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "Habitat : " << C->isidata.habitat << "\n";
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << "\n";
                cout << "Bobot : " << C->isidata.bobot << "\n";

                cout << "------------------------------\n";

                cout << "--- Data Parent ---\n";
                cout << "ID Parent : " << P->isidata.idGolongan << "\n";
                cout << "Posisi dalam list induk : posisi ke-" << indexParent << "\n";
                cout << "Nama golongan : " << P->isidata.namaGolongan << "\n";

                cout << "------------------------------\n";

                foundAny = true;
            }

            C = C->next;
            indexChild++;
        }

        P = P->next;
        indexParent++;
    }

    if (!foundAny) {
        cout << "Tidak ada hewan dengan kriteria ekor yang dicari.\n";
    }
}
```

```C++
file main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0f));

    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));

    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));

    printMLLStructure(LP);
    searchHewanByEkor(LP, false);

    NodeParent prev = NULL;
    NodeParent curr = LP.first;

    while (curr != NULL && curr->isidata.idGolongan != "G004") {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL)
            deleteFirstParent(LP);
        else
            deleteAfterParent(LP, prev);
    }

    printMLLStructure(LP);

    return 0;
}
```

##### Output 3
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan11/output/output3.png)
##### Penjelasan Unguided 1
Program ini merupakan implementasi **Multi Level Linked List (MLL)** untuk menyimpan data hewan berdasarkan **golongannya**. Struktur `golonganHewan` digunakan untuk menyimpan informasi golongan sebagai **parent**, sedangkan `dataHewan` digunakan untuk menyimpan detail hewan sebagai **child**. Setiap golongan hewan disimpan dalam `nodeParent` yang saling terhubung menggunakan **double linked list**, dan setiap `nodeParent` memiliki satu list anak (`L_Child`) yang berisi hewan-hewan dalam golongan tersebut. Data hewan sendiri disimpan dalam `nodeChild` yang juga berbentuk double linked list.

Cara kerja program dimulai dengan menginisialisasi list parent, lalu membuat beberapa node parent dan memasukkannya ke dalam list. Setelah itu, node child dibuat dan dimasukkan ke list child milik parent tertentu. Program dapat menampilkan seluruh struktur MLL menggunakan `printMLLStructure`, mencari hewan berdasarkan kondisi ekor menggunakan `searchHewanByEkor`, serta menghapus parent beserta seluruh child-nya untuk mencegah kebocoran memori. Dengan struktur ini, hubungan hierarkis antara golongan hewan dan data hewan dapat dikelola dengan rapi dan terstruktur.
___
## Kesimpulan
Pada praktikum Modul 11 ini, Multi Linked List (MLL) berhasil diimplementasikan untuk merepresentasikan hubungan **golongan hewan (parent)** dengan **data hewan (child)**. Struktur ini membuat data lebih terorganisir karena setiap node parent memiliki list child sendiri, sehingga penyimpanan dan penelusuran data dapat dilakukan secara bertingkat (parent lalu child) menggunakan konsep linked list.

Selain membangun struktur dasarnya, program juga berhasil menjalankan operasi penting seperti **insert**, **print**, **search berdasarkan status ekor (true/false)**, serta **delete parent beserta seluruh child-nya** untuk mencegah kebocoran memori. Dengan demikian, MLL terbukti efektif untuk menangani data yang bersifat berkelompok dan memiliki hubungan hierarkis, sesuai tujuan praktikum.
___
## Referensi
[1] Wisesty, U. N., Nurrahmi, H., Yunanto, P. E., Rismala, R., & Sthevanie, F. (2025). _STRUKTUR DATA MENGGUNAKAN C++_. PENERBIT KBM INDONESIA.