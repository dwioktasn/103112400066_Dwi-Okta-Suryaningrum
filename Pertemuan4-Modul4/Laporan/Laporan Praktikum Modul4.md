<h1 align = "center">Laporan Praktikum Modul 4<br>SINGLY LINKED LIST (BAGIAN PERTAМА)</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
**Singly Linked List** merupakan salah satu bentuk struktur data dinamis yang setiap _node_-nya memiliki dua bagian utama, yaitu **field data** yang menyimpan nilai, dan **field pointer** yang menunjuk ke _node_ berikutnya. Akhir dari _linked list_ ditandai dengan _node_ terakhir yang menunjuk ke nilai **`NULL`**, yang digunakan sebagai kondisi berhenti saat proses pembacaan atau penelusuran _linked list_ [1].

Pointer itu sendiri merupakan **alamat elemen data** yang tersimpan di dalam memori. Penggunaan pointer untuk mengacu suatu elemen menyebabkan elemen-elemen dalam _linked list_ dapat tersusun bersebelahan secara logis, meskipun tidak bersebelahan secara fisik di memori [2].
___
## Guided
___
#### 1. Guided 1
```C++
-- file list.cpp --

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
	if(List.first == Nil){
		return true;
	} else {
		return false;
	}
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
	/* I.S. sembarang
	F.S. terbentuk list kosong */
	List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
	/* I.S. sembarang
	F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
	address nodeBaru = new node;
	nodeBaru->isidata.nama = nama;
	nodeBaru->isidata.nim = nim;
	nodeBaru->isidata.umur = umur;
	nodeBaru->next = Nil;
	return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
	/* I.S. P terdefinisi
	F.S. memori yang digunakan node dikembalikan ke sistem */
	node->next = Nil;
	delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
	/* I.S. sembarang, P sudah dialokasikan
	F.S. menempatkan elemen list (node) pada awal list */
	nodeBaru->next = List.first;
	List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
	/* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
	F.S. menempatkan elemen (node) sesudah elemen node Prev */
	if (Prev != Nil) {
		nodeBaru->next = Prev->next;
		Prev->next = nodeBaru;
	} else {
		cout << "Node sebelumnya tidak valid!" << endl;
	}
}

void insertLast(linkedlist &List, address nodeBaru) {
	/* I.S. sembarang, nodeBaru sudah dialokasikan
	F.S. menempatkan elemen nodeBaru pada akhir list */
	if (isEmpty(List) == true) {
		List.first = nodeBaru;
	} else {
		address nodeBantu = List.first;
		while (nodeBantu->next != Nil) {
			nodeBantu = nodeBantu->next;
		}
		nodeBantu->next = nodeBaru;
	}
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
	/* I.S. list mungkin kosong
	F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
	if (isEmpty(List) == true) {
		cout << "List kosong." << endl;
	} else {
		address nodeBantu = List.first;
		while (nodeBantu != Nil) {
			cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
			nodeBantu = nodeBantu->next;
		}
	}
}
```

```C++
-- file list.h --

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL
#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
	string nama;
	string nim;
	int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.
typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
	dataMahasiswa isidata;
	address next;
};

struct linkedlist{ //ini linked list nya
	address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

```C++
-- file main.cpp --

#include "list.h"
#include<iostream>
using namespace std;

int main(){
	linkedlist List;
	address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
	createList(List);

	dataMahasiswa mhs;

	nodeA = alokasi("Dhimas", "2311102151", 20);
	nodeB = alokasi("Arvin", "2211110014", 21);
	nodeC = alokasi("Rizal", "2311110029", 20);
	nodeD = alokasi("Satrio", "2211102173", 21);
	nodeE = alokasi("Joshua", "2311102133", 21);

	insertFirst(List, nodeA);
	insertLast(List, nodeB);
	insertAfter(List, nodeC, nodeA);
	insertAfter(List, nodeD, nodeC);
	insertLast(List, nodeE);
	
	cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
	printList(List);

	return 0;
}
```
##### Penjelasan Singkat
Program di atas merupakan implementasi struktur data **Singly Linked List** untuk menyimpan dan menampilkan data mahasiswa yang terdiri atas nama, NIM, dan umur. 

Pada awalnya, list diinisialisasi sebagai list kosong menggunakan fungsi `createList()`. Setiap data mahasiswa dimasukkan ke dalam node baru dengan fungsi `alokasi()`, yang mengatur agar setiap node memiliki field data dan pointer `next` yang menunjuk ke node berikutnya. Proses penambahan node ke dalam list dilakukan dengan tiga cara: `insertFirst()` untuk menambah di awal list, `insertAfter()` untuk menambah setelah node tertentu, dan `insertLast()` untuk menambah di akhir list. 

Struktur list diatur sedemikian rupa sehingga setiap node terhubung secara logis meskipun tidak bersebelahan secara fisik di memori. Setelah semua data mahasiswa dimasukkan, fungsi `printList()` digunakan untuk menampilkan seluruh isi list secara berurutan. Program ini menggambarkan konsep dasar operasi _linked list_, seperti inisialisasi, alokasi memori dinamis, penyisipan node, dan penelusuran data menggunakan pointer.

#### 2. Guided 2
```C++
-- file list.cpp --
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
	if(List.first == Nil){
		return true;
	} else {
		return false;
	}
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
	List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) {
	address nodeBaru = new node;
	nodeBaru->isidata.nama = nama;
	nodeBaru->isidata.nim = nim;
	nodeBaru->isidata.umur = umur;
	nodeBaru->next = Nil;
	return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
	node->next = Nil;
	delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
	nodeBaru->next = List.first;
	List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
	if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
		nodeBaru->next = Prev->next;
		Prev->next = nodeBaru;
	} else {
		cout << "Node sebelumnya tidak valid!" << endl;
	}
}

void insertLast(linkedlist &List, address nodeBaru) {
	if (isEmpty(List)) {
		List.first = nodeBaru;
	} else {
		address nodeBantu = List.first;
		while (nodeBantu->next != Nil) {
			nodeBantu = nodeBantu->next;
		}
		nodeBantu->next = nodeBaru;
	}
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
	address nodeHapus;
	if (isEmpty(List) == false) {
		nodeHapus = List.first;
		List.first = List.first->next;
		nodeHapus->next = Nil;
		dealokasi(nodeHapus);
	} else {
		cout << "List kosong!" << endl;
	}
}

void delLast(linkedlist &List){
	address nodeHapus, nodePrev;
	if(isEmpty(List) == false){
		nodeHapus = List.first;
		if(nodeHapus->next == Nil){
			List.first->next = Nil;
			dealokasi(nodeHapus);
		} else {
			while(nodeHapus->next != Nil){
				nodePrev = nodeHapus;
				nodeHapus = nodeHapus->next;
			}
			nodePrev->next = Nil;
			dealokasi(nodeHapus);
		}
	} else {
		cout << "list kosong" << endl;
	}
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
	if(isEmpty(List) == true){
		cout << "List kosong!" << endl;
	} else { //jika list tidak kosong
		if (nodePrev != Nil && nodePrev->next != Nil) {
			nodeHapus = nodePrev->next;
			nodePrev->next = nodeHapus->next;
			nodeHapus->next = Nil;
			dealokasi(nodeHapus);
		} else {
			cout << "Node sebelumnya (prev) tidak valid!" << endl;
		}
	}
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
	if (isEmpty(List)) {
		cout << "List kosong." << endl;
	} else {
		address nodeBantu = List.first;
		while (nodeBantu != Nil) {
			cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
			nodeBantu = nodeBantu->next;
		}
	}
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
	int count = 0;
	address nodeBantu = List.first;
	while (nodeBantu != Nil) {
		count++;
		nodeBantu = nodeBantu->next;
	}
	return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
	address nodeBantu, nodeHapus;
	nodeBantu = List.first;
	while(nodeBantu != Nil){
		nodeHapus = nodeBantu;
		nodeBantu = nodeBantu->next;
		dealokasi(nodeHapus);
	}
	List.first = Nil;
	cout << "List sudah terhapus!" << endl;
}
```

```C++
-- file list.h --
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL
#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
	string nama;
	string nim;
	int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.
typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
	dataMahasiswa isidata;
	address next;
};

struct linkedlist{ //ini linked list nya
	address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);
#endif
```

```C++
-- file main.cpp --

#include "list.h"
#include<iostream>
using namespace std;

int main(){
	linkedlist List;
	address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
	createList(List);

	dataMahasiswa mhs;

	nodeA = alokasi("Dhimas", "2311102151", 20);
	nodeB = alokasi("Arvin", "2211110014", 21);
	nodeC = alokasi("Rizal", "2311110029", 20);
	nodeD = alokasi("Satrio", "2211102173", 21);
	nodeE = alokasi("Joshua", "2311102133", 21);
	
	insertFirst(List, nodeA);
	insertLast(List, nodeB);
	insertAfter(List, nodeC, nodeA);
	insertAfter(List, nodeD, nodeC);
	insertLast(List, nodeE);

	cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
	printList(List);
	cout << "jumlah node : " << nbList(List) << endl;
	cout << endl;

	delFirst(List);
	delLast(List);
	delAfter(List, nodeD, nodeC);

	cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
	printList(List);
	cout << "jumlah node : " << nbList(List) << endl;
	cout << endl;

	deleteList(List);
	cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
	printList(List);
	cout << "jumlah node : " << nbList(List) << endl;
	cout << endl;

	return 0;
}
```
##### Penjelasan Singkat
Program ini berfungsi untuk mengelola data mahasiswa menggunakan struktur singly linked list. Tiap data mahasiswa disimpan dalam _node_ yang berisi `nama`, `nim`, dan `umur`, serta pointer `next` yang menunjuk ke node berikutnya. 

File `list.h` berisi deklarasi struktur dan fungsi, sedangkan `list.cpp` berisi implementasinya. Program menyediakan fitur untuk membuat list kosong (`createList`), menambah data di awal, tengah, atau akhir (`insertFirst`, `insertAfter`, `insertLast`), serta menghapus data dari posisi tertentu (`delFirst`, `delAfter`, `delLast`). 

Selain itu, terdapat fungsi `printList` untuk menampilkan seluruh isi list, `nbList` untuk menghitung jumlah node, dan `deleteList` untuk menghapus seluruh data sekaligus. File `main.cpp` berfungsi untuk menguji semua operasi tersebut dengan membuat beberapa data mahasiswa, menampilkan hasil setelah proses penambahan dan penghapusan, lalu mengosongkan list sepenuhnya.
 ___
## Unguided
___
#### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :

```C++
-- file Singlylist.cpp --
#include "Singlylist.h"
using namespace std;

void createList(list &L) {
	L.first = Nil;
}

bool isEmpty(const list &L) {
	return L.first == Nil;
}

address alokasi(int value) {
	address nodeBaru = new node;
	nodeBaru->isidata.info = value;
	nodeBaru->next = Nil;
	return nodeBaru;
}

void dealokasi(address &P) {
	if (P != Nil) {
		delete P;
		P = Nil;
	}
}

void insertFirst(list &L, address P) {
	if (P == Nil) return;
		P->next = L.first;
		L.first = P;
	}

void printInfo(const list &L) {
	if (isEmpty(L)) {
		cout << "List kosong.\n";
		return;
	}
	address bantu = L.first;
	while (bantu != Nil) {
		cout << bantu->isidata.info << " ";
		bantu = bantu->next;
	}
	cout << "\n";
}
```

```C++
-- file Singlylist.h --
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
#define Nil nullptr

// data yang disimpan per node (satu bilangan)
struct dataList {
	int info;
};

// deklarasi maju
struct node;
using address = node*;

struct node {
	dataList isidata;
	address next;
};

struct list {
	address first;
};

// API
void createList(list &L);
bool isEmpty(const list &L);
address alokasi(int value);
void dealokasi(address &P);
void printInfo(const list &L);
void insertFirst(list &L, address P);

#endif
```

```C++
-- file main.cpp --
#include "Singlylist.h"
#include <cstdlib>
#include<iostream>
using namespace std;

int main(){
	list L;
	address P1, P2, P3, P4, P5 = Nil;
	createList(L);

	dataList data;

	P1 = alokasi(2);
	insertFirst(L, P1);
	P2 = alokasi(0);
	insertFirst(L, P2);
	P3 = alokasi(8);
	insertFirst(L, P3);
	P4 = alokasi(12);
	insertFirst(L, P4);
	P5 = alokasi(9);
	insertFirst(L, P5);

	printInfo(L);

	system("read -p 'Press any key to continue...' var");
	return 0;
}
```
##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan4/output/output-unguided1.png)

##### Penjelasan Unguided 1
Program ini merupakan implementasi sederhana dari **Singly Linked List** untuk menyimpan data berupa bilangan bulat. File `Singlylist.h` berisi deklarasi struktur dan fungsi yang digunakan, sedangkan `Singlylist.cpp` berisi implementasinya. Struktur `list` hanya memiliki satu pointer `first` yang menunjuk ke node pertama. Setiap `node` menyimpan data bertipe `int` dan pointer `next` yang menunjuk ke node berikutnya.

Fungsi `createList()` digunakan untuk menginisialisasi list kosong dengan mengatur `first = Nil`. Fungsi `isEmpty()` memeriksa apakah list kosong atau tidak. Proses pembuatan node baru dilakukan oleh `alokasi()`, yang mengembalikan alamat node baru dengan data yang diberikan dan pointer `next` bernilai `Nil`. Fungsi `dealokasi()` digunakan untuk menghapus node dari memori agar tidak terjadi kebocoran. Prosedur `insertFirst()` berfungsi menambahkan node baru di bagian awal list dengan cara menghubungkan node baru ke node pertama yang sudah ada. Sedangkan `printInfo()` digunakan untuk menampilkan seluruh isi list secara berurutan sampai node terakhir.

Pada `main.cpp`, program membuat list kosong, lalu menambahkan lima node dengan nilai 9, 12, 8, 0, dan 2 menggunakan `insertFirst()`, sehingga urutannya menjadi 9 → 12 → 8 → 0 → 2. Setelah itu, `printInfo()` dipanggil untuk menampilkan isi list ke layar.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
--- file Singlylist.cpp ---
#include "Singlylist.h"
using namespace std;

void createList(list &L) { L.first = Nil; }
bool isEmpty(const list &L) { return L.first == Nil; }

address alokasi(int value) {
	address nodeBaru = new node;
	nodeBaru->isidata.info = value;
	nodeBaru->next = Nil;
	return nodeBaru;
}

void dealokasi(address &P) {
	if (P != Nil) { delete P; P = Nil; }
}

void insertFirst(list &L, address P) {
	if (P == Nil) return;
	P->next = L.first;
	L.first = P;
}

void printInfo(const list &L) {
	address q = L.first;
	while (q != Nil) { cout << q->isidata.info << " "; q = q->next; }
	cout << "\n";
}

address findByValue(const list &L, int value) {
	address q = L.first;
	while (q != Nil) {
		if (q->isidata.info == value) return q;
		q = q->next;
	}
	return Nil;
}

void deleteFirst(list &L, address &P) {
	P = Nil;
	if (isEmpty(L)) return;
	P = L.first;
	L.first = L.first->next;
	P->next = Nil;
}

void deleteLast(list &L, address &P) {
	P = Nil;
	if (isEmpty(L)) return;

	// satu elemen
	if (L.first->next == Nil) {
		P = L.first;
		L.first = Nil;
		P->next = Nil;
		return;
	}

	// cari last & prev
	address prev = L.first;
	address cur = L.first->next;
	while (cur->next != Nil) { prev = cur; cur = cur->next; }
	prev->next = Nil;
	P = cur;
	P->next = Nil;
}

void deleteAfter(list &L, address Prec, address &P) {
	P = Nil;
	if (Prec == Nil || Prec->next == Nil) return; // ga ada yang dihapus
	P = Prec->next;
	Prec->next = P->next;
	P->next = Nil;
}

int nbList(const list &L) {
	int n = 0;
	for (address q = L.first; q != Nil; q = q->next) ++n;
	return n;
}

void deleteList(list &L) {
	address p;
	while (!isEmpty(L)) {
		deleteFirst(L, p);
		dealokasi(p);
	}
}
```

```C++
--- file Singlylist.h ---
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
#define Nil nullptr

struct dataList { int info; };

// deklarasi maju
struct node;
using address = node*;

struct node {
	dataList isidata;
	address next;
};  

struct list { address first; };

void createList(list &L);
bool isEmpty(const list &L);
address alokasi(int value);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void printInfo(const list &L);

void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address Prec, address &P);
int nbList(const list &L);
void deleteList(list &L);

address findByValue(const list &L, int value);

#endif
```

```C++
--- file main.cpp ---
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
```
##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan4/output/output-unguided2.png)

##### Penjelasan Unguided 2
Program ini merupakan implementasi lengkap dari **Singly Linked List** untuk menyimpan data berupa bilangan bulat dengan operasi tambah, hapus, dan hitung jumlah node. File `Singlylist.h` berisi deklarasi struktur data dan fungsi, sedangkan `Singlylist.cpp` berisi implementasinya.

Pada struktur data, setiap `node` menyimpan satu nilai (`info`) dan pointer `next` yang menunjuk ke node berikutnya. Struktur `list` hanya berisi pointer `first` sebagai penanda node awal. Fungsi `createList()` digunakan untuk menginisialisasi list kosong, dan `isEmpty()` untuk memeriksa apakah list kosong. Fungsi `alokasi()` membuat node baru dengan nilai tertentu, sedangkan `dealokasi()` digunakan untuk menghapus node dari memori. Prosedur `insertFirst()` menambahkan node di awal list, dan `printInfo()` menampilkan seluruh isi list.

Fungsi penghapusan terdiri dari `deleteFirst()` untuk menghapus node pertama, `deleteLast()` untuk menghapus node terakhir, dan `deleteAfter()` untuk menghapus node setelah node tertentu. Fungsi `findByValue()` membantu mencari node berdasarkan nilai yang diberikan, `nbList()` menghitung jumlah node dalam list, sedangkan `deleteList()` menghapus seluruh node hingga list kosong.

Pada `main.cpp`, program membuat list berisi data `9 → 12 → 8 → 0 → 2`, lalu melakukan beberapa operasi penghapusan: menghapus node pertama (9), node terakhir (2), dan node setelah nilai 12 (yaitu 8). Setelah penghapusan, list berisi `12 → 0`, kemudian jumlah node ditampilkan. Terakhir, `deleteList()` dipanggil untuk menghapus seluruh isi list agar memori kembali bersih.
___
## Kesimpulan
Dari praktikum **Singly Linked List (Bagian Pertama)** ini, dapat dipelajari bahwa _linked list_ merupakan salah satu struktur data dinamis yang memungkinkan penyimpanan dan pengelolaan data secara fleksibel. Dengan memanfaatkan pointer, elemen-elemen dalam list dapat saling terhubung meskipun tidak bersebelahan di memori. Melalui implementasi berbagai operasi seperti pembuatan list, penambahan, penghapusan, dan penelusuran node, mahasiswa memahami konsep dasar manajemen memori dinamis serta cara kerja hubungan antar-node pada struktur data _linked list_. Praktikum ini juga membantu memperkuat pemahaman mengenai perbedaan antara struktur data statis dan dinamis dalam pemrograman.
___
## Referensi
[1] Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. _INFOKOM (Informatika & Komputer)_, _7_(2), 15-24.
[2] SUDARSO, S. T. I. K. Y. LAPORAN PRAKTIKUM PROGRAM POINTER & LINKED LIST PADA PHP.