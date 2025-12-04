<h1 align = "center">Laporan Praktikum Modul 10<br>TREE (BAGIAN PERTAMA)</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
****Tree** adalah struktur data hirarkis yang terdiri dari sekumpulan node yang saling berhubungan melalui relasi parent–child dan digunakan untuk merepresentasikan data bertingkat seperti struktur folder, organisasi, dan ekspresi matematika [1]. Node paling atas disebut **root**, sedangkan node yang tidak memiliki anak disebut **leaf**. Node yang memiliki anak termasuk **internal node**, dan hubungan antar node direpresentasikan melalui **edge** [1]. Setiap node berada pada **level** tertentu — root berada pada level 1, anaknya di level 2, dan seterusnya.

**Height** adalah level tertinggi dalam tree (kedalaman maksimum), sedangkan **depth** adalah jumlah sisi dari root menuju node tertentu. Sebagian tree yang dimulai dari suatu node dan mencakup semua turunannya disebut **subtree**, sementara node yang memiliki parent yang sama disebut **siblings** [1].

**Binary Tree** merupakan tree khusus yang setiap node-nya hanya boleh memiliki maksimal dua child, yaitu **left child** dan **right child** [1]. Binary tree memiliki beberapa jenis, di antaranya:

- **Complete Binary Tree**, yaitu tree yang seluruh levelnya penuh kecuali level terakhir, dan node pada level terakhir berada di posisi kiri.
- **Skewed Binary Tree**, yaitu tree miring yang seluruh node-nya hanya memiliki satu child.
- **Full Binary Tree**, yaitu tree yang semua node kecuali leaf memiliki tepat dua child [1].

Tree juga dapat dibentuk kembali dari dua traversal berbeda (preorder, inorder, postorder), dengan syarat salah satunya adalah **inorder** untuk memastikan struktur tree dapat direkonstruksi dengan benar [1].
___
## Guided
___
#### 1. Guided 1 - Rekursif
```C++
#include <iostream>

using namespace std;

int pangkat_2(int x) {  // x adalah pangkatnya
    if (x == 0) {       // basis
        return 1;
    } else if (x > 0) { // rekurens
        return 2 * pangkat_2(x - 1);
    }
    // optional: untuk nilai negatif (jika mau)
    return -1; 
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << endl;

    cout << "2 pangkat " << x << " adalah : " << pangkat_2(x) << endl;

    return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi perhitungan **2 pangkat x** menggunakan konsep **rekursi** dalam bahasa C++. Fungsi utama yang digunakan adalah `pangkat_2(x)`, yang bekerja dengan dua kondisi. Pertama, **kondisi basis** ketika `x == 0`, di mana fungsi langsung mengembalikan nilai `1` karena secara matematis 2⁰ = 1. Kedua, **kondisi rekurens** ketika `x > 0`, di mana fungsi akan memanggil dirinya sendiri dengan nilai `x - 1` dan mengalikan hasilnya dengan 2. Dengan kata lain, untuk menghitung 2^x, program menerapkan rumus rekursif: 2^x = 2 × 2^(x−1). Pemanggilan ulang ini akan terus terjadi hingga mencapai kondisi basis.

Pada fungsi `main()`, pengguna diminta memasukkan nilai `x`. Setelah itu, program memanggil fungsi `pangkat_2(x)` untuk menghitung hasilnya, lalu menampilkan nilai **2 pangkat x** ke layar. Secara keseluruhan, program ini menunjukkan bagaimana rekursi dapat digunakan untuk menyelesaikan perhitungan matematis dengan cara memecah masalah besar menjadi submasalah yang lebih kecil sampai mencapai titik berhenti yang telah ditentukan.

#### 2. Guided 2
```C++
file BST1.cpp
#include "BST1.h"

// isEmpty & createTree
bool isEmpty(address root) {  // mengecek apakah BST kosong atau tidak
    return (root == nullptr);
}

void createTree(address &root) {  // menginisialisasi BST (root = nullptr)
    root = nullptr;
}

// alokasi & insert
address newNode(infotype x) {  // membuat node baru
    address temp = new Node;
    temp->info = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

address insertNode(address root, infotype x) {  // memasukkan node ke BST
    if (root == nullptr) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }
    // jika x == root->info, tidak dimasukkan (duplikat diabaikan)

    return root;
}

// traversal
void preOrder(address root) {  // root - left - right
    if (root != nullptr) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) {   // left - root - right
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { // left - right - root
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

// utilities
int countNodes(address root) {  // menghitung jumlah node
    if (isEmpty(root)) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) {   // menghitung kedalaman / height tree
    if (isEmpty(root)) {
        return -1;  // tree kosong → depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

```C++
file BST1.h
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype;          // alias infotype untuk data integer
struct Node;                   // forward declaration
typedef Node* address;         // alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info;   // info data yang disimpan (integer)
    address left;    // pointer ke anak kiri
    address right;   // pointer ke anak kanan
};

// ISEMPTY & CREATE
bool isEmpty(address root);           // mengecek apakah BST kosong atau tidak
void createTree(address &root);       // membuat BST (root di-set sebagai nullptr)

// ALOKASI & INSERT
address newNode(infotype x);          // membuat node baru dengan nilai x
address insertNode(address root, infotype x); // memasukkan node ke dalam BST

// TRAVERSAL
void preOrder(address root);          // traversal pre-order (root - left - right)
void inOrder(address root);           // traversal in-order (left - root - right)
void postOrder(address root);         // traversal post-order (left - right - root)

// UTILITIES
int countNodes(address root);         // menghitung jumlah node dalam tree
int treeDepth(address root);          // menghitung kedalaman / height tree

#endif
```

```C++
file main.cpp
#include <iostream>
#include "BST1.h"

using namespace std;

int main() {
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl << endl;

    root = insertNode(root, 20); // root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal   : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal  : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl << endl;

    cout << "Jumlah Node      : " << countNodes(root) << endl;
    cout << "Kedalaman Tree   : " << treeDepth(root) << endl;

    return 0;
}
```

##### Penjelasan Singkat
Program di atas merupakan implementasi **Binary Search Tree (BST)**, yaitu struktur data hierarkis yang menyimpan data secara terurut berdasarkan aturan: nilai yang lebih kecil diletakkan di **subtree kiri**, sementara nilai yang lebih besar diletakkan di **subtree kanan**. BST memungkinkan proses pencarian, penyisipan, dan traversal dilakukan secara efisien. Penyimpanan setiap elemen dilakukan dalam bentuk **node** yang terdiri dari data (`info`) serta dua pointer (`left` dan `right`) yang menunjuk ke anak kiri dan kanan dalam tree.

Inisialisasi tree dilakukan melalui fungsi `createTree()`, yang mengatur `root` menjadi `nullptr` sebagai penanda bahwa tree masih kosong. Pembuatan node baru dilakukan oleh fungsi `newNode()`, sedangkan proses penyisipan data ke dalam tree dikerjakan oleh `insertNode()`, yang menempatkan nilai baru di posisi yang sesuai berdasarkan aturan BST—ke kiri jika lebih kecil, ke kanan jika lebih besar. Program ini juga menyediakan tiga jenis traversal: `preOrder()` (root–left–right), `inOrder()` (left–root–right), dan `postOrder()` (left–right–root), yang masing-masing menghasilkan urutan penelusuran berbeda.

Selain itu, fungsi `countNodes()` digunakan untuk menghitung jumlah seluruh node dalam tree, sementara `treeDepth()` menentukan **kedalaman tree**, yaitu level terbawah yang dapat dicapai dari root. Pada fungsi `main()`, beberapa nilai dimasukkan untuk membangun BST, kemudian ketiga traversal ditampilkan bersama informasi jumlah node dan kedalaman tree. Program ini secara keseluruhan memperlihatkan operasi dasar BST serta bagaimana tree dapat dibangun dan ditelusuri secara terstruktur.

#### 3. Guided 3
```C++
file BST2.cpp
#include "BST2.h"

// FUNCTION & PROSEDUR SEBELUMNYA

// isEmpty & createTree
bool isEmpty(address root) {
    return (root == nullptr);
}

void createTree(address &root) {
    root = nullptr;
}

// alokasi & insert
address newNode(infotype x) {
    address temp = new Node;
    temp->info = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

address insertNode(address root, infotype x) {
    if (root == nullptr) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }
    // jika x == root->info → diabaikan (tidak simpan duplikat)

    return root;
}

// Traversal
void preOrder(address root) {
    if (root != nullptr) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

// Utilities
int countNodes(address root) {
    if (isEmpty(root)) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) {
    if (isEmpty(root)) {
        return -1;  // tree kosong → depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

// FUNCTION & PROSEDUR BARU

// searching
void searchByData(address root, infotype x) {
    if (isEmpty(root)) {
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = nullptr;
        bool ketemu = false;

        while (nodeBantu != nullptr) {
            if (x < nodeBantu->info) {
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (x > nodeBantu->info) {
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else { // x == nodeBantu->info
                ketemu = true;
                break;
            }
        }

        if (!ketemu) {
            cout << "Data tidak ditemukan" << endl;
        } else {
            cout << "Data ditemukan di dalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            // parent & sibling
            address sibling = nullptr;
            if (parent != nullptr) {
                cout << "Parent : " << parent->info << endl;
                if (parent->left == nodeBantu) {
                    sibling = parent->right;
                } else if (parent->right == nodeBantu) {
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)" << endl;
            }

            // menampilkan sibling
            if (sibling != nullptr) {
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : -" << endl;
            }

            // menampilkan child kiri
            if (nodeBantu->left != nullptr) {
                cout << "Child kiri  : " << nodeBantu->left->info << endl;
            } else {
                cout << "Child kiri  : -" << endl;
            }

            // menampilkan child kanan
            if (nodeBantu->right != nullptr) {
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else {
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

// mostLeft & mostRight
address mostLeft(address root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

address mostRight(address root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// delete
bool deleteNode(address &root, infotype x) {
    if (root == nullptr) {
        return false; // data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            // node yang mau dihapus ditemukan
            // Case 1 : leaf node
            if (root->left == nullptr && root->right == nullptr) {
                address temp = root;
                root = nullptr;
                delete temp;
            }
            // Case 2 : hanya punya right child
            else if (root->left == nullptr) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            // Case 3 : hanya punya left child
            else if (root->right == nullptr) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : punya dua child
            else {
                // mostLeft dari subtree kanan = successor
                address successor = mostLeft(root->right);
                // salin data successor
                root->info = successor->info;
                // hapus successor di subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; // berhasil dihapus
        }
    }
}

void deleteTree(address &root) {
    if (root == nullptr) {
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}
```

```C++
file BST2.h
#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype;          // alias infotype untuk data integer
struct Node;                   // forward declaration
typedef Node* address;         // alias address sebagai pointer ke struct Node

struct Node {
    infotype info;   // data yang disimpan
    address left;    // pointer ke anak kiri
    address right;   // pointer ke anak kanan
};

// ISEMPTY & CREATE
bool isEmpty(address root);              // mengecek apakah BST kosong atau tidak
void createTree(address &root);          // menginisialisasi BST (root = nullptr)

// ALOKASI & INSERT
address newNode(infotype x);             // membuat node baru dengan nilai x
address insertNode(address root, infotype x); // menyisipkan node ke dalam BST

// TRAVERSAL
void preOrder(address root);             // traversal pre-order (root - left - right)
void inOrder(address root);              // traversal in-order (left - root - right)
void postOrder(address root);            // traversal post-order (left - right - root)

// UTILITIES
int countNodes(address root);            // menghitung jumlah node dalam tree
int treeDepth(address root);             // menghitung kedalaman / height tree

// FUNCTION & PROSEDUR BARU

// SEARCHING
void searchByData(address root, infotype x); // mencari data tertentu dan menampilkan info parent/sibling/child

// MOST LEFT & MOST RIGHT
address mostLeft(address root);          // mengembalikan node dengan nilai terkecil
address mostRight(address root);         // mengembalikan node dengan nilai terbesar

// DELETE
bool deleteNode(address &root, infotype x);  // menghapus node dengan info x, return true jika berhasil
void deleteTree(address &root);             // menghapus seluruh node dalam BST

#endif
```

```C++
file main.cpp
#include <iostream>
#include "BST2.h"

using namespace std;

int main() {
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ===" << endl << endl;

    root = insertNode(root, 30); // root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl << endl;

    cout << "Jumlah Node    : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    cout << "=== Searching Data 17 ===" << endl;
    searchByData(root, 17);

    cout << endl;
    cout << "Node mostLeft  : " << mostLeft(root)->info << endl;
    cout << "Node mostRight : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;

    if (deleteNode(root, angkaHapus)) {
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    cout << "=== Searching Setelah Delete ===" << endl;
    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl << endl;

    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl << endl;

    if (isEmpty(root)) {
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
        cout << endl;
    }

    return 0;
}
```

##### Penjelasan Singkat
Program di atas merupakan implementasi lengkap dari **Binary Search Tree (BST)** yang mencakup operasi dasar seperti penyisipan data, traversal, pencarian node, serta penghapusan node. Struktur BST mengatur setiap elemen dalam bentuk node yang memiliki nilai (`info`) serta pointer ke anak kiri dan kanan. Nilai yang lebih kecil ditempatkan di subtree kiri, sedangkan nilai yang lebih besar diarahkan ke subtree kanan. Proses penyisipan dilakukan oleh `insertNode()`, yang menempatkan data baru pada posisi yang sesuai berdasarkan aturan BST.

Untuk menampilkan isi tree, program menyediakan tiga jenis traversal: `inOrder()` untuk menampilkan data secara terurut dari kecil ke besar, `preOrder()` untuk menelusuri node mulai dari root, dan `postOrder()` untuk menampilkan hasil setelah subtree kiri dan kanan ditelusuri. Fungsi `countNodes()` digunakan untuk menghitung jumlah node, sedangkan `treeDepth()` menentukan kedalaman tree, yaitu level terdalam dari root.

Program ini juga menambahkan operasi lanjutan seperti `searchByData()`, yang mencari suatu nilai sekaligus menampilkan informasi lengkap tentang **parent**, **sibling**, dan **child** dari node yang ditemukan. Fungsi `mostLeft()` dan `mostRight()` digunakan untuk menemukan node dengan nilai terkecil dan terbesar di dalam tree. Selain itu, operasi `deleteNode()` memungkinkan penghapusan node dengan berbagai kemungkinan kasus—baik node leaf, node dengan satu child, maupun node dengan dua child menggunakan mekanisme successor. Pada akhirnya, `deleteTree()` digunakan untuk menghapus seluruh tree dari memori. Program utama (`main`) menjalankan semua operasi tersebut secara berurutan, sehingga memperlihatkan bagaimana BST dapat dibangun, ditelusuri, dicari, diubah, dan dihapus secara terstruktur.
 ___
## Unguided
___
#### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”
```C++
file bstree.cpp
#include "bstree.h"

address alokasi(infotype x) {
    address temp = new Node;
    temp->info = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void insertNode(address &root, infotype x) {
    if (root == nullptr) {
        root = alokasi(x);
        return;
    }

    if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // Jika x == root->info → duplikat, diabaikan
}

address findNode(address root, infotype x) {
    if (root == nullptr || root->info == x) {
        return root;
    }

    if (x < root->info) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

void printInorder(address root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungKedalaman(address root, int start) {
    if (root == nullptr) {
        return start;
    } else {
        int leftDepth  = hitungKedalaman(root->left,  start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
}

int hitungTotalInfo(address root) {
    if (root == nullptr) {
        return 0;
    } else {
        return root->info
             + hitungTotalInfo(root->left)
             + hitungTotalInfo(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1
             + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
    }
}
```

```C++
file bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

// deklarasi fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root);
int hitungKedalaman(address root, int start);
int hitungTotalInfo(address root);
int hitungJumlahNode(address root);

#endif
```

```C++
file main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);   // duplikat → diabaikan
    insertNode(root, 7);

    printInorder(root);
    cout << "\n";

    cout << "kedalaman   : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total       : " << hitungTotalInfo(root) << endl;

    return 0;
}
```

##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan9/output/output1.png)
##### Penjelasan Unguided 1
Program di atas merupakan implementasi dasar dari **Binary Search Tree (BST)** yang digunakan untuk menyimpan data secara terurut. Setiap data ditempatkan ke dalam sebuah node yang memiliki tiga bagian, yaitu nilai (`info`), pointer anak kiri (`left`), dan pointer anak kanan (`right`). Penyisipan data dilakukan melalui fungsi `insertNode()`, yang menempatkan nilai baru di subtree kiri jika lebih kecil atau di subtree kanan jika lebih besar dari nilai pada node saat ini, sehingga struktur BST tetap terjaga. Program ini juga menyediakan fungsi `findNode()` untuk mencari nilai tertentu, serta `printInorder()` yang menampilkan seluruh isi tree dalam urutan terkecil ke terbesar melalui teknik **in-order traversal**.

Selain itu, terdapat beberapa fungsi utilitas seperti `hitungJumlahNode()` untuk menghitung total node dalam tree, `hitungTotalInfo()` untuk menjumlahkan semua nilai yang tersimpan, dan `hitungKedalaman()` untuk mengetahui kedalaman atau height tree dengan menggunakan pendekatan rekursif. Pada fungsi `main()`, beberapa nilai dimasukkan ke dalam BST dan hasil traversal serta perhitungannya ditampilkan. Secara keseluruhan, program ini menunjukkan bagaimana BST dapat dibangun, ditelusuri, dan dianalisis menggunakan berbagai operasi rekursif.
___
## Kesimpulan
Pada praktikum Modul 10 ini, penulis mempelajari konsep dasar **tree** dan penerapannya dalam bentuk **binary tree** serta **binary search tree (BST)**. Melalui guided pertama, penulis memahami kembali konsep **rekursi** melalui contoh perhitungan 2 pangkat x, di mana masalah besar dipecah menjadi submasalah yang lebih kecil hingga mencapai kondisi basis. Guided berikutnya memperkenalkan implementasi BST berbasis linked list, mulai dari inisialisasi tree, pembuatan node, proses penyisipan data secara terurut, hingga penelusuran tree menggunakan tiga jenis traversal, yaitu _pre-order_, _in-order_, dan _post-order_.

Pada bagian lanjutan, penulis mengimplementasikan berbagai operasi penting pada BST, seperti menghitung jumlah node, kedalaman tree, melakukan pencarian data, menampilkan informasi parent–sibling–child, mencari nilai minimum dan maksimum (most left dan most right), hingga menghapus node dan menghapus seluruh tree dari memori. Pada tugas unguided, penulis memperkuat pemahaman dengan merancang sendiri ADT BST lengkap dengan fungsi-fungsi utilitas tambahan seperti `hitungJumlahNode()`, `hitungTotalInfo()`, dan `hitungKedalaman()`. Secara keseluruhan, praktikum ini membantu penulis memahami bagaimana tree dan BST tidak hanya sekadar konsep teoritis, tetapi juga dapat diimplementasikan secara langsung dalam kode C++ untuk mengelola data secara efisien dan terstruktur.
___
## Referensi
[1] Anita Sindar, R. M. S. (2019). _Struktur Data Dan Algoritma Dengan C++_ (Vol. 1). CV. AA. RIZKY.