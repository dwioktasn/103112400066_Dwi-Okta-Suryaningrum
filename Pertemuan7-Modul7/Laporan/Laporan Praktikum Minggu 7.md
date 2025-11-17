<h1 align = "center">Laporan Praktikum Modul 7<br>STACK</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
Stack merupakan salah satu struktur data yang bekerja dengan prinsip **LIFO (Last In, First Out)**, di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Struktur ini digunakan pada berbagai kasus yang membutuhkan pemrosesan data dari elemen terakhir terlebih dahulu, seperti pada fitur **undo/redo** dalam perangkat lunak pengolah teks atau gambar [1].

Stack terdiri dari kumpulan elemen yang hanya dapat ditambahkan atau diambil melalui satu sisi, yaitu bagian atas yang disebut **top**. Dua operasi dasar yang dapat dilakukan pada stack adalah **push** dan **pop**. Operasi **push** berfungsi untuk menambahkan elemen baru ke posisi teratas, sedangkan operasi **pop** digunakan untuk mengambil sekaligus menghapus elemen teratas dari stack [2].
___
## Guided
___
#### 1. Guided 1
```C++
file stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

/* ====== Fungsi Mengecek Kondisi Stack ====== */

bool isEmpty(stack listStack) {
    return listStack.top == Nil;
}

/* ====== Prosedur Membuat Stack Baru ====== */

void createStack(stack &listStack) {
    listStack.top = Nil;
}

/* ====== Alokasi & Dealokasi Node ====== */

address alokasi(int angka) {
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

/* ====== Operasi Dasar Stack ====== */

void push(stack &listStack, address nodeBaru) {
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka
         << " berhasil ditambahkan ke dalam stack!" << endl;
}

void pop(stack &listStack) {
    if (isEmpty(listStack)) {
        cout << "Stack kosong!" << endl;
    } else {
        address nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node " << data
             << " berhasil dihapus dari stack!" << endl;
    }
}

/* ====== Update Node Berdasarkan Posisi ====== */

void update(stack &listStack, int posisi) {
    if (isEmpty(listStack)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    if (posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    address nodeBantu = listStack.top;
    int count = 1;
    bool found = false;

    while (nodeBantu != Nil) {
        if (count == posisi) {
            cout << "Update node posisi ke-" << posisi << endl;
            cout << "Masukkan angka baru : ";
            cin >> nodeBantu->dataAngka;
            cout << "Data berhasil diupdate!" << endl << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
        count++;
    }

    if (!found) {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
    }
}

/* ====== Menampilkan Isi Stack ====== */

void view(stack listStack) {
    if (isEmpty(listStack)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        cout << "[TOP] ";
        while (nodeBantu != Nil) {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

/* ====== Mencari Data dalam Stack ====== */

void searchData(stack listStack, int data) {
    if (isEmpty(listStack)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeBantu = listStack.top;
    int posisi = 1;
    bool found = false;

    cout << "Mencari data " << data << "..." << endl;

    while (nodeBantu != Nil) {
        if (nodeBantu->dataAngka == data) {
            cout << "Data " << data
                 << " ditemukan pada posisi ke-" << posisi << endl << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
        posisi++;
    }

    if (!found) {
        cout << "Data " << data << " tidak ditemukan di dalam stack!" << endl << endl;
    }
}
```

```C++
file stack.h
#ifndef STACK_H
#define STACK_H

#define Nil nullptr

#include <iostream>
using namespace std;

typedef struct node* address;

struct node {
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

```C++
file main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    stack listStack;
    createStack(listStack);

    address nodeA = alokasi(1);
    address nodeB = alokasi(2);
    address nodeC = alokasi(3);
    address nodeD = alokasi(4);
    address nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi **struktur data Stack berbasis Linked List** yang digunakan untuk menyimpan dan mengelola data secara dinamis dengan prinsip **LIFO (Last In, First Out)**, yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Setiap elemen dalam stack direpresentasikan sebagai sebuah **node** yang berisi data bertipe integer (`dataAngka`) dan pointer `next` yang menunjuk ke node berikutnya di bawahnya.

Proses inisialisasi stack dilakukan melalui fungsi `createStack()`, yang bertugas mengatur agar pointer `top` bernilai `Nil` menandakan stack dalam keadaan kosong. Pembuatan node baru dilakukan dengan fungsi `alokasi()`, sedangkan fungsi `dealokasi()` digunakan untuk menghapus node dari memori secara dinamis guna mencegah kebocoran memori.

Operasi dasar stack terdiri dari:

- **`push()`**, untuk menambahkan elemen baru ke bagian paling atas stack. Node baru akan menunjuk ke node yang sebelumnya berada di posisi top, kemudian dijadikan top yang baru.
- **`pop()`**, untuk menghapus elemen teratas dari stack dan menampilkan data yang berhasil dihapus.
- **`update()`**, untuk memperbarui nilai data pada posisi tertentu di dalam stack.
- **`view()`**, untuk menampilkan seluruh isi stack dari elemen teratas hingga terbawah.
- **`searchData()`**, untuk mencari dan menampilkan posisi suatu data tertentu dalam stack.

Pada fungsi `main()`, program menguji seluruh operasi tersebut. Pertama, lima node baru dengan nilai 1 hingga 5 dibuat menggunakan fungsi `alokasi()` dan ditambahkan ke dalam stack dengan `push()`. Setelah itu, program menampilkan isi stack, kemudian menghapus dua elemen teratas menggunakan `pop()`. Selanjutnya, beberapa elemen di posisi tertentu diperbarui menggunakan `update()`, dan hasil akhir stack kembali ditampilkan. Terakhir, fungsi `searchData()` digunakan untuk mencari data tertentu di dalam stack, baik yang ada maupun yang tidak ditemukan.

#### 2. Guided 2
```C++
file stack.cpp
#include "stack.h"
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {                 // Cek apakah stack belum penuh
        S.top++;                      // Increment nilai top
        S.info[S.top] = x;            // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;            // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1);
        CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }   // Pindahkan semua elemen ke temp1 (urutan terbalik)
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }      // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

```C++
file stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top;              //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);     //menambahkan elemen ke stack
infotype pop(Stack &S);              //mengambil elemen teratas dari stack
void printInfo(Stack S);             //menampilkan isi stack
void balikStack(Stack &S);           //membalik urutan elemen stack

#endif
```

```C++
file main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);
    cout << endl;

    cout << "Balik stack..." << endl;
    balikStack(S);
    cout << endl;

    cout << "Stack Setelah Dibalik:" << endl;
    printInfo(S);
    cout << endl;

    return 0;
}
```

##### Penjelasan Singkat
Program di atas merupakan implementasi **struktur data Stack berbasis array statis** dengan prinsip **LIFO (Last In, First Out)** — elemen terakhir yang dimasukkan akan keluar pertama. Stack direpresentasikan oleh array `info` dan variabel `top` sebagai penanda elemen teratas.

Fungsi `CreateStack()` menginisialisasi stack kosong (`top = Nil`), `push()` menambah elemen ke atas stack, dan `pop()` menghapus elemen teratas. Fungsi `printInfo()` menampilkan isi stack dari atas ke bawah, sedangkan `balikStack()` membalik urutan elemen menggunakan dua stack sementara.

Pada fungsi `main()`, dilakukan serangkaian operasi push dan pop, kemudian isi stack ditampilkan sebelum dan sesudah dibalik. Program ini menunjukkan cara kerja stack array dalam mengelola data secara **LIFO** dengan operasi yang sederhana dan efisien.
 ___
## Unguided
___
#### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”
```C++
file stack.cpp
#include "stack.h"
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {      // Cek apakah stack belum penuh
        S.top++;           // Increment nilai top
        S.info[S.top] = x; // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;     // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {     // Cek apakah stack tidak kosong
        x = S.info[S.top]; // Ambil nilai teratas
        S.top--;           // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;              // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {          // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";      // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";       // Tampilkan setiap elemen
        }
        cout << endl;          // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {     // Cek apakah stack tidak kosong
        Stack temp1, temp2;        // Deklarasi dua stack temporary
        CreateStack(temp1);
        CreateStack(temp2);

        while (!isEmpty(S)) {
            push(temp1, pop(S));   // Pindahkan semua elemen ke temp1 (urutan terbalik)
        }

        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));   // Pindahkan ke temp2 (urutan terbalik lagi)
        }

        while (!isEmpty(temp2)) {
            push(S, pop(temp2));   // Kembalikan ke stack asal (urutan sudah benar)
        }
    }
}
```

```C++
file stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];   // array untuk menyimpan elemen stack
    int top;                // indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);     // menambahkan elemen ke stack
infotype pop(Stack &S);              // mengambil elemen teratas dari stack
void printInfo(Stack S);             // menampilkan isi stack
void balikStack(Stack &S);           // membalik urutan elemen stack

#endif
```

```C++
file main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "Hello world!" << endl;

    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}```

##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan7/output/output1.png)
##### Penjelasan Unguided 1
Program ini merupakan implementasi **struktur data Stack berbasis array statis** yang menyimpan data bertipe _integer_ dengan prinsip **LIFO (Last In, First Out)**, di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan.  
Data disimpan ke dalam array `info`, sedangkan posisi elemen teratas ditunjukkan oleh variabel `top`.

Fungsi `CreateStack()` digunakan untuk membuat stack kosong dengan menginisialisasi `top = Nil`.  
Untuk pengecekan kondisi stack, tersedia fungsi `isEmpty()` untuk memeriksa apakah stack kosong, dan `isFull()` untuk mengetahui apakah stack sudah penuh.

Operasi dasar stack dilakukan melalui dua fungsi:

- `push()` untuk **menambahkan elemen baru ke bagian teratas** stack selama kapasitas belum penuh.
- `pop()` untuk **mengambil dan menghapus elemen teratas** selama stack tidak kosong.

Selain itu, fungsi `printInfo()` digunakan untuk menampilkan seluruh isi stack mulai dari elemen teratas hingga elemen terbawah.

Program juga menyediakan fungsi tambahan `balikStack()` yang berfungsi untuk **membalik urutan elemen di dalam stack**.  
Proses pembalikan ini dilakukan dengan menggunakan dua stack sementara (`temp1` dan `temp2`) untuk memastikan urutan elemen kembali dengan posisi yang terbalik dari sebelumnya.

Pada bagian utama program (`main()`), beberapa operasi `push()` dan `pop()` dilakukan untuk memodifikasi isi stack.  
Setelah itu, isi stack ditampilkan menggunakan `printInfo()`, kemudian urutannya dibalik dengan memanggil `balikStack()` sebelum dicetak kembali.
#### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer
```C++
file stack.cpp
#include "stack.h"
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1);
        CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }   // Pindahkan semua elemen ke temp1 (urutan terbalik)
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }      // Kembalikan ke stack asal (urutan sudah benar)
    }
}

// Fungsi untuk menambah elemen ke stack secara ascending
void pushAscending(Stack &S, infotype x) {
    // stack sementara
    Stack temp;
    CreateStack(temp);

    // selama S tidak kosong dan elemen teratas lebih besar dari x,
    // pindahin dulu ke temp
    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    // sekarang posisi masukin x sudah pas
    push(S, x);

    // balikin lagi elemen yang tadi dipindah
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```

```C++
file stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top;              //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);         //menambahkan elemen ke stack
infotype pop(Stack &S);                  //mengambil elemen teratas dari stack
void printInfo(Stack S);                 //menampilkan isi stack
void balikStack(Stack &S);               //membalik urutan elemen stack
void pushAscending(Stack &S, infotype X); //menambahkan elemen ke stack secara ascending

#endif
```

```C++
file main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
}```

##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan7/output/output2.png)
##### Penjelasan Unguided 2
Program ini merupakan implementasi **struktur data Stack berbasis array statis** untuk menyimpan data bilangan bulat (_integer_) dengan prinsip **LIFO (Last In, First Out)**, yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan.  
Setiap elemen disimpan dalam array `info`, dan posisi elemen teratas ditunjukkan oleh variabel `top`.

Fungsi `CreateStack()` digunakan untuk membuat stack kosong dengan menginisialisasi `top = Nil`.  
Fungsi `push()` menambahkan data ke dalam stack selama belum penuh, sedangkan `pop()` menghapus elemen teratas dari stack.  
Fungsi `isEmpty()` dan `isFull()` digunakan untuk memeriksa kondisi stack apakah kosong atau sudah penuh.  
Selain itu, fungsi `printInfo()` menampilkan seluruh isi stack dari elemen teratas hingga terbawah.

Program juga memiliki dua fungsi tambahan, yaitu `balikStack()` dan `pushAscending()`.  
Fungsi `balikStack()` digunakan untuk **membalik urutan elemen dalam stack** dengan bantuan dua stack sementara.  
Sedangkan `pushAscending()` berfungsi untuk **memasukkan elemen ke stack dalam urutan menaik (ascending)** dengan cara memindahkan sementara elemen-elemen yang lebih besar dari nilai baru, lalu mengembalikannya setelah elemen baru dimasukkan.

Pada bagian utama program (`main()`), beberapa data ditambahkan ke stack menggunakan `pushAscending()`.  
Setelah itu, isi stack ditampilkan dengan `printInfo()`, kemudian dibalik urutannya menggunakan `balikStack()`.

#### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter.

```C++
file stack.cpp
#include "stack.h"
using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// // Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1);
        CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

void getInputStream(Stack &S) {
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') break;

        if (!isFull(S)) {
            // konversi '4' -> 4
            if (ch >= '0' && ch <= '9') {
                push(S, ch - '0');
            } else {
               //skip
            }
        } else {
            cout << "\nStack penuh, input dihentikan!" << endl;
            break;
        }
    }
}

```

```C++
file stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top;              //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);       //menambahkan elemen ke stack
infotype pop(Stack &S);                //mengambil elemen teratas dari stack
void printInfo(Stack S);               //menampilkan isi stack
void balikStack(Stack &S);             //membalik urutan elemen stack
void getInputStream(Stack &S);         //mengisi stack dari input stream

#endif
```

```C++
file main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}```

##### Output 3
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan7/output/output3.png)
##### Penjelasan Unguided 3
Program ini merupakan implementasi **struktur data Stack berbasis array statis** dengan prinsip **LIFO (Last In, First Out)**, di mana elemen terakhir yang masuk akan keluar pertama. Stack disimpan dalam array `info` dengan variabel `top` sebagai penanda elemen teratas.

Fungsi `CreateStack()` menginisialisasi stack kosong, `push()` menambah data ke atas stack, dan `pop()` menghapus elemen teratas. Fungsi `isEmpty()` dan `isFull()` memeriksa kondisi stack, sedangkan `printInfo()` menampilkan isi stack dari atas ke bawah.

Selain itu, `balikStack()` digunakan untuk membalik urutan elemen dengan dua stack sementara, dan `getInputStream()` memungkinkan pengguna memasukkan data dari keyboard hingga menekan _Enter_. Pada fungsi `main()`, stack diisi, ditampilkan, lalu dibalik untuk menunjukkan cara kerja konsep **LIFO** secara sederhana.
___
## Kesimpulan
**stack** adalah struktur data yang sangat cocok untuk kasus yang membutuhkan pengolahan data secara **LIFO (Last In, First Out)**. Operasi dasarnya hanya melalui satu sisi (top), sehingga proses **push**, **pop**, dan **lihat isi stack** menjadi sederhana dan terkontrol.

Implementasi stack bisa dibuat dengan dua cara, yaitu **menggunakan linked list** (lebih fleksibel karena dinamis) dan **menggunakan array** (lebih mudah dan terstruktur karena ukuran sudah ditentukan). Fitur tambahan seperti `balikStack()`, `pushAscending()`, dan `getInputStream()` menunjukkan bahwa stack tidak hanya bisa menyimpan data, tetapi juga bisa dimodifikasi sesuai kebutuhan algoritma.

Dengan memahami operasi dasar dan penerapan stack, kita bisa menggunakannya pada kasus nyata seperti undo/redo, pembalikan data, maupun pengolahan input bertahap.
___
## Referensi
[1] Selamet, R. (2016). Implementasi struktur data list, queue dan stack dalam java. _Media Informatika_, _15_(3), 18-25.
[2] Dharmayanti, D. (2011). Stack.