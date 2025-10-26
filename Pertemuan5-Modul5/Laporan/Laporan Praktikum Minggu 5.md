<h1 align = "center">Laporan Praktikum Modul 5<br>SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
**Singly Linked List** (daftar tertaut tunggal) adalah salah satu bentuk **struktur data dinamis** yang terdiri dari kumpulan simpul (_node_) yang saling terhubung secara berurutan. Setiap _node_ memiliki dua bagian utama, yaitu **field data** yang menyimpan nilai dan **field pointer** yang menunjuk ke _node_ berikutnya.  
Akhir dari _linked list_ ditandai dengan _node_ terakhir yang menunjuk ke nilai **`NULL`**, yang menjadi tanda berhentinya proses penelusuran [1].

Berbeda dengan array, _linked list_ tidak memiliki ukuran tetap sehingga memungkinkan **alokasi memori secara dinamis** saat elemen ditambahkan atau dihapus. Penggunaan pointer membuat elemen-elemen dalam _linked list_ dapat tersusun bersebelahan secara logis, meskipun tidak bersebelahan secara fisik di memori [2].

Struktur ini mendukung operasi seperti **penambahan**, **penghapusan**, dan **penelusuran data** dengan efisien, serta banyak digunakan dalam implementasi **stack**, **queue**, dan berbagai algoritma yang membutuhkan pengelolaan data secara dinamis[3].

da
___
## Guided
___
#### 1. binary.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;    
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr) return nullptr;
    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;

    do {
        Node* mid = getMiddle(start, end);
        if (mid == nullptr) return nullptr;

        if (mid->data == key)
            return mid;
        else if (mid->data < key)
            start = mid->next;
        else
            end = mid;
    } while (end == nullptr || end != start);

    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 90);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi struktur data Singly Linked List yang digunakan untuk menyimpan sekumpulan data bilangan bulat secara berurutan dan melakukan pencarian nilai menggunakan algoritma Binary Search. 

Pertama, node baru dibuat menggunakan fungsi append(), yang menambahkan elemen di akhir list hingga terbentuk rantai node yang saling terhubung melalui pointer next. Setiap node menyimpan satu nilai integer (data) dan alamat node berikutnya (next). 

Fungsi getMiddle() digunakan untuk mencari node yang berada di posisi tengah antara batas start dan end dengan bantuan dua pointer (slow dan fast). Fungsi ini mendukung proses pencarian pada binarySearch(), yang bekerja dengan cara membagi list menjadi dua bagian setiap kali dilakukan perbandingan nilai tengah dengan nilai yang dicari (key). 

Jika nilai ditemukan, fungsi akan mengembalikan node tempat nilai tersebut berada; jika tidak, fungsi mengembalikan nullptr. Program utama (main()) membuat list berisi nilai 10–50, lalu melakukan pencarian terhadap nilai 90, dan menampilkan hasil “Not Found”.

#### 2. linear.cpp
```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);

    Node* result = linearSearch(head, 20);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}

```

##### Penjelasan Singkat
Program di atas merupakan implementasi Singly Linked List sederhana yang digunakan untuk menyimpan dan mencari data secara linear (sekuensial). 

Fungsi append() menambahkan elemen baru di akhir list dengan membuat node baru secara dinamis dan menghubungkannya ke node terakhir. Setiap node menyimpan nilai (data) dan pointer (next) yang menunjuk ke node berikutnya. 

Fungsi linearSearch() melakukan pencarian dengan cara menelusuri node satu per satu mulai dari head hingga menemukan nilai yang dicari (key) atau mencapai akhir list (nullptr). 

Pada fungsi main(), program membuat linked list berisi nilai 10, 20, dan 30, kemudian mencari nilai 20 dan menampilkan hasil “Found” jika ditemukan, atau “Not Found” jika tidak ada.
 ___
## Unguided
___
#### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1) Membuat linked list dengan menambahkan node di akhir 
2) Mengimplementasikan binary search pada linked list 
3. Menampilkan detail proses pencarian dan hasil akhir 
Petunjuk Tugas 1: 
- Gunakan struktur Node dengan data integer dan pointer next 
- Implementasikan fungsi append() untuk menambah node 
- Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan 
- Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
- Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi 
- Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;      // angka yang dibawa orang itu
    Node* next;    // tangan kanan yang pegang orang di sebelahnya
};

void append(Node*& head, int value) {
    Node* nodeBaru = new Node{value, nullptr};
    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    Node* bantu = head;
    while (bantu->next != nullptr)
        bantu = bantu->next;
    bantu->next = nodeBaru;
}

Node* getMiddle(Node* start, Node* end) {
    if (!start) return nullptr;
    Node* slow = start;
    Node* fast = start;
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->data;
        if (p->next)
            cout << " -> ";
        else
            cout << " -> NULL\n";
        p = p->next;
    }
}

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int langkah = 1;

    cout << "\nProses pencarian:\n";
    while (start != end && start != nullptr) {
        Node* mid = getMiddle(start, end);
        if (!mid) break;

        cout << "Iterasi " << langkah++ << ": Mid = " << mid->data << " (indeks tengah)";

        if (mid->data == key) {
            cout << " -> DITEMUKAN!\n" << endl;
            cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << mid << endl;
            cout << "Node berikutnya: "
                 << (mid->next ? to_string(mid->next->data) : "NULL") << endl;
            cout << "Mencari nilai: 25\n";
            return mid;
        } else if (mid->data < key) {
            cout << " -> Cari di bagian kanan\n";
            start = mid->next;
        } else {
            cout << " -> Cari di bagian kiri\n";
            end = mid;
        }

        if (start == end || (start && start->next == end))
            break;
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key
         << " TIDAK DITEMUKAN dalam linked list\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    printList(head);

    cout << "Mencari nilai: 40\n";
    binarySearch(head, 40);
    cout << endl;

    binarySearch(head, 25);
    return 0;
}
```
##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan5/output/unguided1.png)

##### Penjelasan Unguided 1
Program ini merupakan implementasi Binary Search pada struktur data Singly Linked List. Setiap node menyimpan nilai (data) dan pointer ke node berikutnya (next). 

Fungsi append() digunakan untuk menambahkan node baru di akhir list, sedangkan getMiddle() mencari node tengah menggunakan dua pointer (slow dan fast).

Fungsi binarySearch() membagi area pencarian menjadi dua bagian (kiri dan kanan) berdasarkan nilai tengah sampai data yang dicari (key) ditemukan atau list habis diperiksa. 

Hasilnya menampilkan proses iterasi pencarian serta status apakah nilai berhasil ditemukan atau tidak di dalam linked list.

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1) Membuat linked list dengan menambahkan node di akhir 
2) Mengimplementasikan linear search pada linked list 
3) Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 2: 
- Gunakan struktur Node dengan data integer dan pointer next 
- Implementasikan fungsi append() untuk menambah node 
- Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan
- Data dalam linked list tidak perlu terurut untuk linear search 
- Tampilkan setiap langkah pencarian dan node yang sedang diperiksa 
- Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;      // angka yang dibawa orang itu
    Node* next;    // pointer ke node berikutnya
};

void printList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->next)
            cout << " -> ";
        t = t->next;
    }
    cout << " -> NULL\n";
}

Node* linearSearch(Node* head, int key) {
    Node* curr = head;
    int iter = 1;

    cout << "\nProses Pencarian:\n";
    while (curr) {
        cout << "Memeriksa node " << iter << ": " << curr->data;
        if (curr->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return curr;
        }
        cout << " (tidak sama)\n";
        curr = curr->next;
        iter++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

void append(Node*& head, int value) {
    Node* n = new Node{value, nullptr};
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);

    int key = 30;
    cout << "Mencari nilai: " << key << endl;
    Node* result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        cout << "Node berikutnya: "
             << (result->next ? to_string(result->next->data) : "NULL") << endl;
    } else {
        cout << "\nHasil: Nilai " << key
             << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    key = 25;
    cout << "Mencari nilai: " << key << endl;
    result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        cout << "Node berikutnya: "
             << (result->next ? to_string(result->next->data) : "NULL") << endl;
    } else {
        cout << "\nHasil: Nilai " << key
             << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
```
##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan5/output/unguided2.png)

##### Penjelasan Unguided 2
Program ini merupakan implementasi **pencarian linear (Linear Search)** pada struktur data **Singly Linked List**.  
Setiap node menyimpan dua bagian utama, yaitu nilai (`data`) dan pointer (`next`) yang menunjuk ke node berikutnya.

Fungsi `append()` digunakan untuk menambahkan elemen baru di akhir list, sedangkan `printList()` menampilkan seluruh isi linked list.  
Fungsi `linearSearch()` menelusuri list dari awal (`head`) hingga akhir (`NULL`) dan membandingkan setiap nilai node dengan nilai yang dicari (`key`).

Jika ditemukan, program menampilkan informasi node yang berisi nilai tersebut; jika tidak, akan menampilkan pesan bahwa nilai tidak ditemukan.  
Program ini menggambarkan konsep traversal dan pencarian sederhana dalam struktur data **linked list dinamis**.
___
## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa **Singly Linked List** merupakan salah satu struktur data dinamis yang memungkinkan pengelolaan data secara efisien melalui penggunaan pointer. Setiap node dalam linked list memiliki dua komponen utama, yaitu _data_ dan _pointer_ yang menunjuk ke node berikutnya, sehingga elemen-elemen di dalamnya dapat terhubung secara logis meskipun tidak bersebelahan secara fisik di memori.

Melalui implementasi algoritma **Linear Search** dan **Binary Search**, dapat dipahami bahwa proses pencarian pada linked list dilakukan dengan cara menelusuri node satu per satu (linear) atau dengan membagi ruang pencarian berdasarkan posisi tengah (binary). Kedua metode ini menunjukkan bagaimana konsep dasar linked list dapat diterapkan dalam berbagai operasi pencarian data yang efisien dan terstruktur.
___
## Referensi
[1] Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. _INFOKOM (Informatika & Komputer)_, _7_(2), 15-24.
[2] SUDARSO, S. T. I. K. Y. LAPORAN PRAKTIKUM PROGRAM POINTER & LINKED LIST PADA PHP.
[3] AKCoding.com. (2024). Singly Linked List: Explained, Examples, and Applications. Retrieved from https://akcoding.medium.com/singly-linked-list-explained-examples-and-applications-378209429a2a