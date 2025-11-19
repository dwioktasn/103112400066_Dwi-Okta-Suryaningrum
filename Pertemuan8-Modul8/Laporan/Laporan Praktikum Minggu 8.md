<h1 align = "center">Laporan Praktikum Modul 8<br>QUEUE</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
**Queue** adalah struktur data linear yang menerapkan prinsip **First In, First Out (FIFO)**, yaitu elemen yang pertama masuk akan menjadi elemen pertama yang keluar[1]. Konsep ini mirip dengan antrean pada kehidupan sehari-hari, di mana orang yang datang lebih dulu akan dilayani terlebih dahulu. Queue banyak digunakan dalam sistem komputasi yang membutuhkan pengolahan data secara berurutan, seperti sistem antrian proses, penjadwalan CPU, buffer pesan, dan manajemen print spooler.

Secara umum, queue memiliki dua operasi utama, yaitu **enqueue** dan **dequeue**.

- **Enqueue** adalah operasi untuk menambahkan elemen ke bagian belakang antrian.
- **Dequeue** adalah operasi untuk menghapus elemen dari bagian depan antrian[2].

Selain operasi dasar tersebut, terdapat juga operasi **peek/front**, yaitu untuk melihat elemen paling depan tanpa menghapusnya. Queue dapat diimplementasikan menggunakan **array** atau **linked list**. Implementasi berbasis array biasanya lebih sederhana, tetapi memiliki keterbatasan kapasitas sehingga sering memanfaatkan teknik **circular array** untuk memaksimalkan pemakaian ruang[2]. Sementara itu, queue berbasis linked list tidak memiliki batasan ukuran karena node dapat dialokasikan secara dinamis selama memori masih tersedia.

Queue sangat penting dalam berbagai algoritma dan aplikasi komputer modern, seperti pemrosesan data streaming, breadth-first search (BFS), dan komunikasi antar proses. Struktur data ini memastikan bahwa aliran data dapat dikelola secara teratur dan efisien dengan kompleksitas waktu operasi dasar yang umumnya **O(1)** karena proses penambahan dan penghapusan hanya melibatkan akses pada ujung depan atau belakang antrian[1].
___
## Guided
___
#### 1. Guided 1
```C++
file queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

bool isEmpty(queue Q) {
    return (Q.head == Nil);
}

void createQueue(queue &Q) {
    Q.head = Q.tail = Nil;
}

address alokasi(int angka) {
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
}

void enQueue(queue &Q, address nodeBaru) {
    if (isEmpty(Q)) {
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka 
         << " berhasil ditambahkan ke dalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    address nodeHapus = Q.head;
    Q.head = Q.head->next;

    if (Q.head == Nil) {
        Q.tail = Nil;
    }

    cout << "Node " << nodeHapus->dataAngka 
         << " berhasil dihapus dari queue!" << endl;

    dealokasi(nodeHapus);
}

void updateQueue(queue &Q, int posisi) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    if (posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    address nodeBantu = Q.head;
    int count = 1;
    bool found = false;

    while (nodeBantu != Nil) {
        if (count == posisi) {
            cout << "Update node posisi ke-" << posisi << endl;
            cout << "Masukkan angka baru: ";
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

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    address nodeBantu = Q.head;
    while (nodeBantu != Nil) {
        cout << nodeBantu->dataAngka << " ";
        nodeBantu = nodeBantu->next;
    }
    cout << endl;
}

void searchData(queue Q, int data) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    address nodeBantu = Q.head;
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
        posisi++;
        nodeBantu = nodeBantu->next;
    }

    if (!found) {
        cout << "Data " << data << " tidak ditemukan di dalam queue!" << endl << endl;
    }
}
```

```C++
file queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define Nil NULL
#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &P);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```

```C++
file main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE;

    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi **struktur data Queue berbasis Linked List**, yaitu struktur data dinamis yang menyimpan elemen dalam urutan tertentu dengan prinsip **FIFO (First In, First Out)**. Pada queue, elemen yang **pertama dimasukkan** akan menjadi elemen **pertama yang dikeluarkan**. Setiap elemen queue direpresentasikan sebagai sebuah **node** yang terdiri dari data bertipe integer (`dataAngka`) dan pointer `next` yang menunjuk ke node berikutnya.

Inisialisasi queue dilakukan melalui fungsi `createQueue()`, yang mengatur pointer `head` dan `tail` menjadi `Nil` sebagai tanda bahwa queue masih kosong. Pembuatan node baru dilakukan melalui fungsi `alokasi()`, sementara penghapusan node dari memori dilakukan oleh `dealokasi()` untuk mencegah kebocoran memori.

Operasi dasar queue terdiri dari:

- **`enQueue()`**, untuk menambahkan elemen baru ke bagian belakang queue. Jika queue kosong, node baru akan menjadi `head` dan `tail`. Jika tidak, node baru ditautkan ke node `tail` saat ini dan kemudian dijadikan `tail` yang baru.
- **`deQueue()`**, untuk menghapus elemen paling depan queue. Node pada posisi `head` dihapus dari memori, dan `head` dipindahkan ke node berikutnya. Jika setelah penghapusan queue menjadi kosong, `tail` juga diatur menjadi `Nil`.
- **`updateQueue()`**, untuk memperbarui nilai data pada node di posisi tertentu. Proses dilakukan dengan menelusuri node dari `head` hingga posisi yang dimaksud.
- **`viewQueue()`**, untuk menampilkan seluruh isi queue dari `head` hingga `tail`.
- **`searchData()`**, untuk mencari apakah suatu nilai tertentu terdapat di dalam queue, sekaligus menampilkan posisi ditemukannya data tersebut.

Pada fungsi `main()`, program menguji seluruh operasi queue. Lima node dengan nilai 1 hingga 5 dialokasikan dan dimasukkan ke dalam queue menggunakan `enQueue()`. Setelah itu, isi queue ditampilkan dengan `viewQueue()`. Dua elemen paling depan kemudian dihapus menggunakan `deQueue()`, dan hasil perubahan ditampilkan kembali. Selanjutnya, fungsi `updateQueue()` digunakan untuk memperbarui nilai pada beberapa posisi tertentu. Pada tahap akhir, program memanggil `searchData()` untuk mencari data yang ada maupun yang tidak ada di dalam queue.

#### 2. Guided 2
```C++
file queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return (Q.count == 0);
}

bool isFull(Queue Q) {
    return (Q.count == MAX_QUEUE);
}

void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++;
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--;
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";

    if (!isEmpty(Q)) {
        int i = Q.head;
        int n = 0;

        while (n < Q.count) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
            n++;
        }
    }

    cout << "]" << endl;
}
```

```C++
file queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

```C++
file main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\nEnqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    cout << "\nDequeue 1 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\nEnqueue 1 elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\nDequeue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

##### Penjelasan Singkat
Program di atas merupakan implementasi **struktur data Queue berbasis array dengan metode Circular Queue**, yaitu struktur data antrian yang bekerja menggunakan prinsip **FIFO (First In, First Out)**, di mana elemen yang pertama masuk akan menjadi elemen pertama yang keluar. Berbeda dengan queue linear biasa, Circular Queue memungkinkan proses **perputaran indeks** sehingga ruang dalam array dapat digunakan secara optimal tanpa membuang slot kosong di depan.

Struktur queue direpresentasikan melalui tiga variabel penting, yaitu:

- **`head`** → menunjuk ke indeks elemen terdepan,
- **`tail`** → menunjuk ke posisi untuk memasukkan elemen baru,
- **`count`** → menyimpan jumlah elemen yang sedang berada dalam antrian.

Proses inisialisasi queue dilakukan dengan fungsi `createQueue()`, yang mengatur semua variabel (`head`, `tail`, dan `count`) menjadi 0 sehingga antrian berada dalam kondisi kosong. Operasi pemeriksaan kondisi queue dilakukan melalui fungsi `isEmpty()` dan `isFull()` yang mengembalikan nilai _true_ apabila queue kosong atau penuh sesuai nilai `count`.

Operasi dasar Circular Queue terdiri dari:

- **`enqueue()`**, untuk menambahkan elemen baru ke dalam antrian. Data disimpan pada indeks `tail`, kemudian nilai `tail` digeser menggunakan operasi modulo (`(tail + 1) % MAX_QUEUE`) sehingga indeks dapat berputar kembali ke awal ketika mencapai batas array. Variabel `count` ditambah satu untuk mencatat bertambahnya elemen.
- **`dequeue()`**, untuk menghapus elemen paling depan dari antrian. Nilai di posisi `head` diambil sebagai elemen yang keluar, lalu `head` diputar menggunakan operasi modulo. Variabel `count` dikurangi satu.
- **`printInfo()`**, untuk menampilkan seluruh elemen queue dengan cara menelusuri array mulai dari posisi `head` sebanyak `count` elemen sambil menggunakan modulo agar traversal dapat berputar secara circular.

Pada fungsi `main()`, program mendemonstrasikan seluruh operasi queue. Pertama, queue diinisialisasi dan tiga elemen awal dimasukkan melalui `enqueue()`. Kemudian satu elemen dikeluarkan menggunakan `dequeue()`, setelah itu satu elemen baru kembali ditambahkan. Program juga menguji kondisi dequeue berulang dan menampilkan isi queue setiap dilakukan operasi, sehingga tampak jelas bagaimana indeks `head` dan `tail` bergerak secara melingkar.
 ___
## Unguided
___
#### 1. Alternatif 1
```C++
file queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

// QUEUE ALTERNATIF 1 (HEAD DIAM, TAIL BERGERAK)

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    // Jika hanya satu elemen, reset queue
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        // Geser elemen ke kiri
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }

    cout << endl;
}
```

```C++
file queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

```C++
file main.cpp
##include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    cout << "Hello World" << endl;

    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}
```

##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan8/output/output1.png)
##### Penjelasan Unguided 1
Program di atas merupakan implementasi **Queue Alternatif 1 berbasis array**, yaitu bentuk antrian linear yang bekerja dengan prinsip **FIFO (First In, First Out)** di mana elemen yang masuk pertama akan keluar terlebih dahulu. Queue direpresentasikan menggunakan indeks `head` dan `tail`, dengan `head` selalu berada di posisi awal dan `tail` bergerak ke kanan setiap kali terjadi operasi `enqueue()`. Saat `dequeue()` dilakukan, elemen paling depan diambil dan seluruh elemen lainnya **digeser ke kiri** agar `head` tetap berada di posisi 0. Program menguji operasi dasar queue seperti menambahkan elemen (`enqueue`), menghapus elemen (`dequeue`), dan menampilkan isi antrian (`printInfo`), sehingga terlihat bagaimana posisi `head` dan `tail` berubah sesuai proses antrian yang dilakukan.
#### 2. Alternatif 2
```C++
file queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

// QUEUE ALTERNATIF 2 (HEAD BERGERAK, TAIL BERGERAK)

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);   // tidak circular, tail mentok di ujung array
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;                      // tail bergerak maju
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;                   // queue jadi kosong
    } else {
        Q.head++;                      // head bergerak maju (TANPA geser elemen)
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }

    cout << endl;
}
```
##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan8/output/output1.png)
##### Penjelasan Unguided 2
Program ini merupakan implementasi **Queue Alternatif 2**, yaitu queue linear berbasis array yang bekerja dengan prinsip **FIFO (First In, First Out)** tetapi berbeda dari alternatif pertama karena **head dan tail sama-sama bergerak ke kanan tanpa melakukan pergeseran elemen**. Saat operasi `enqueue()`, data baru dimasukkan ke posisi `tail` lalu `tail` bertambah satu, sedangkan pada `dequeue()`, elemen diambil dari posisi `head` dan `head` ikut bertambah tanpa menggeser isi array. Konsekuensinya, ruang kosong di bagian depan array **tidak dapat digunakan kembali**, sehingga queue dianggap penuh ketika `tail` mencapai indeks terakhir meskipun masih ada slot kosong sebelumnya. Fungsi `printInfo()` menampilkan elemen mulai dari `head` hingga `tail`, sehingga terlihat dengan jelas bagaimana head terus bergerak maju setiap dilakukan `dequeue()`.
#### 3. Alternatif 3
```C++
file queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

// QUEUE ALTERNATIF 3 (CIRCULAR QUEUE: HEAD & TAIL BERPUTAR)

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    if (isEmptyQueue(Q)) return false;
    return ((Q.tail + 1) % MAX_QUEUE == Q.head);   // posisi berikutnya bertemu head
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX_QUEUE;         // tail berputar
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;                               // queue kosong kembali
    } else {
        Q.head = (Q.head + 1) % MAX_QUEUE;         // head berputar
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE;                   // maju melingkar
    }

    cout << endl;
}
```
##### Output 3
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan8/output/output1.png)
##### Penjelasan Unguided 3
Program ini merupakan implementasi **Queue Alternatif 3 menggunakan Circular Queue**, yaitu antrian berbasis array yang memanfaatkan operasi modulo sehingga **head dan tail dapat berputar (melingkar)** dan ruang array dapat digunakan kembali secara efisien. Circular queue tetap mengikuti prinsip **FIFO (First In, First Out)**, namun berbeda dengan versi linear karena posisi `tail` akan kembali ke indeks 0 ketika mencapai batas array. Pada operasi `enqueue()`, data dimasukkan ke posisi `tail` yang bergerak secara circular, sementara pada `dequeue()`, data diambil dari `head` yang juga berputar menggunakan modulo. Queue dianggap penuh ketika posisi `tail` berikutnya sama dengan `head`, dan fungsi `printInfo()` menampilkan elemen dengan cara menelusuri array mulai dari head hingga tail secara melingkar. Struktur ini membuat seluruh slot array dapat dimanfaatkan tanpa pemborosan ruang.
___
## Kesimpulan
Berdasarkan hasil praktikum pada Modul 8 mengenai struktur data **Queue**, dapat disimpulkan bahwa queue merupakan struktur data linear yang bekerja dengan prinsip **FIFO (First In, First Out)**, di mana elemen pertama yang masuk akan menjadi elemen pertama yang keluar. Melalui implementasi yang dilakukan, mahasiswa dapat memahami tiga jenis mekanisme queue, yaitu **Alternatif 1 (head diam, tail bergerak)**, **Alternatif 2 (head dan tail bergerak tanpa pergeseran)**, dan **Alternatif 3 (circular queue)**. Setiap alternatif memiliki cara kerja dan karakteristik yang berbeda, mulai dari kebutuhan penggeseran elemen hingga pemanfaatan ruang array secara melingkar. Implementasi queue menggunakan linked list pada guided juga memberikan gambaran bahwa struktur dinamis lebih fleksibel dibandingkan array statis. Secara keseluruhan, praktikum ini memberikan pemahaman menyeluruh tentang bagaimana operasi dasar queue—**enqueue**, **dequeue**, **update**, **view**, dan **search**—dilakukan, serta bagaimana masing-masing metode berpengaruh terhadap efisiensi memori dan waktu eksekusi program.
___
## Referensi
[1] Siregar, Rafika Dwi., Siregar, Robbi., Hasibuan, Robi Yanto. (2022). “Implementasi Struktur Data Queue dalam Pengolahan Antrian Pelayanan Klinik”. _Jurnal Teknologi dan Sistem Informasi_, 3(2), 45–52. Diakses pada 19 November 2025 melalui  
https://jurnal.stmikroyal.ac.id/index.php/jtsi/article/view/1061

[2] Pratama, Rino., Utami, Mei, Fadil, Arif. (2023). “Analisis Kinerja Queue Menggunakan Array dan Linked List pada Sistem Antrian Pelayanan”. _Jurnal Sistem Informasi dan Sains Teknologi_, 5(1), 12–20. Diakses pada 19 November 2025 melalui  
https://jurnal.ustjogja.ac.id/index.php/jsist/article/view/4210