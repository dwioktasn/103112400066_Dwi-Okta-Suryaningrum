<h1 align = "center">Laporan Praktikum Modul 3<br>ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
_Abstract Data Type (ADT)_ adalah sekumpulan objek beserta operasi-operasi yang terkait dengannya. ADT menekankan tiga prinsip utama, yaitu abstraksi, enkapsulasi, dan information hiding (penyembunyian informasi). Konsep ini bertujuan untuk menjaga _representational independence_ — artinya, pengguna cukup mengetahui apa yang dapat dilakukan suatu tipe data tanpa harus tahu bagaimana tipe tersebut diimplementasikan[1]. Tipe data rekaman atau _record/struct_ merupakan tipe data terstruktur yang terdiri atas sejumlah elemen dengan tipe data yang tidak harus sama. Sebuah _record_ berfungsi sebagai wadah penyimpanan data yang memiliki berbagai jenis tipe data berbeda, namun dikumpulkan dalam satu kesatuan struktur. Struktur ini memungkinkan pemrogram untuk mengelompokkan beberapa variabel yang berbeda jenis, seperti `int`, `float`, dan `char`, menjadi satu kesatuan logis agar lebih mudah diakses dan dikelola dalam program.[2].
___
## Guided
___
#### 1. Guided 1
```C++
-- file mahasiswa.cpp --

#include <iostream>
#include "mahasiswa.h"
using namespace std;

//realisasi dari fungsi inputmhs
void inputMhs(mahasiswa &m){
	cout << "Masukkan NIM: ";
	cin >> m.nim;
	cout << "Masukkan nilai 1: ";
	cin >> m.nilai1;
	cout << "Masukkan nilai 2: ";
	cin >> m.nilai2;
}

//realisasi dari fungsi rata2
float rata2(mahasiswa m){
	return(float)(m.nilai1 + m.nilai2) / 2;
}
```

```C++
-- file mahasiswa.h --

#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe
struct mahasiswa {
	char nim[10];
	int nilai1, nilai2;
};

//deklarasi primitid
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++
-- file main.cpp --

#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main(){
	mahasiswa mhs;
	inputMhs(mhs);

	cout << "Data-rata nilai adalah :" << rata2(mhs) << endl;
	system("read -p 'Press Enter to continue...' var");

	return 0;
}
```
##### Penjelasan Singkat
Program ini berfungsi untuk memasukkan data mahasiswa dan menghitung rata-rata dari dua nilai yang dimasukkan. Program dibagi menjadi tiga file, yaitu `mahasiswa.h`, `mahasiswa.cpp`, dan `main.cpp`.

Pada file **`mahasiswa.h`**, dibuat struktur bernama `mahasiswa` yang menyimpan NIM, nilai pertama, dan nilai kedua. Di file ini juga ada deklarasi dua fungsi, yaitu `inputMhs()` untuk input data dan `rata2()` untuk menghitung rata-rata nilai.

File **`mahasiswa.cpp`** berisi isi dari kedua fungsi tersebut. Fungsi `inputMhs()` digunakan untuk meminta pengguna mengetik NIM dan dua nilai, sedangkan `rata2()` digunakan untuk menghitung rata-rata dari dua nilai tersebut.

File **`main.cpp`** adalah program utamanya. Di sini dibuat satu variabel bertipe `mahasiswa`, lalu program memanggil fungsi `inputMhs()` untuk mengisi data, dan hasil rata-ratanya ditampilkan ke layar dengan memanggil fungsi `rata2()`.

Secara singkat, program ini menunjukkan cara menggunakan **struct** dan **fungsi** secara terpisah dalam beberapa file agar kode lebih teratur dan mudah dibaca.

#### 2. Struct
```C++
#include <iostream>
using namespace std;

struct mahasiswa {
	char nim[10];
	float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
	cout << "Masukkan NIM: ";
	cin >> m.nim;
	cout << "Masukkan nilai 1: ";
	cin >> m.nilai1;
	cout << "Masukkan nilai 2: ";
	cin >> m.nilai2;
}

float rata2(mahasiswa m){
	return(float)(m.nilai1 + m.nilai2) / 2;
}
 
int main(){
	mahasiswa mhs;
	inputMhs(mhs);

	cout << "Data-rata nilai adalah :" << rata2(mhs) << endl;
	system("read -p 'Press Enter to continue...' var");
	
	return 0;
}
```
##### Penjelasan Singkat
Program ini digunakan untuk memasukkan data seorang mahasiswa dan menghitung rata-rata dari dua nilai yang dimasukkan.

Di dalam program terdapat **struct bernama `mahasiswa`** yang berisi tiga data, yaitu `nim`, `nilai1`, dan `nilai2`. Struct ini berfungsi untuk menampung data mahasiswa dalam satu kesatuan.

Fungsi **`inputMhs()`** dipakai untuk meminta pengguna memasukkan NIM serta dua nilai. Data yang dimasukkan akan disimpan ke dalam variabel bertipe `mahasiswa` yang dikirim ke fungsi tersebut lewat **referensi** (`&m`).

Fungsi **`rata2()`** digunakan untuk menghitung nilai rata-rata dari dua nilai yang ada di dalam struct mahasiswa. Hasil perhitungan dikembalikan dalam bentuk bilangan desimal (`float`).

Pada bagian **`main()`**, program membuat satu variabel `mhs` bertipe `mahasiswa`. Lalu program memanggil fungsi `inputMhs()` untuk mengisi datanya, dan setelah itu menampilkan hasil rata-rata dengan memanggil fungsi `rata2()`.

Secara singkat, program ini menunjukkan cara **menggunakan struct dan fungsi** dalam C++ untuk mengolah data mahasiswa dan menghitung nilai rata-ratanya dengan input dari pengguna.
 ___
## Unguided
___
#### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
	string nama;
	char nim[10];
	float uts, uas, tugas, nilaiAkhir;
};

void inputMhs(mahasiswa &m){
	cout << "Masukkan NIM: ";
	cin >> m.nim;
	cout << "Masukkan nama: ";
	cin >> m.nama;
	cout << "Masukkan nilai UTS: ";
	cin >> m.uts;
	cout << "Masukkan nilai UAS: ";
	cin >> m.uas;
	cout << "Masukkan nilai Tugas: ";
	cin >> m.tugas;
}

float nilaiAkhir(mahasiswa m){
	return(float)(0.3*m.uts) + (0.4*m.uas) * (0.3*m.tugas);
}

int main(){
	mahasiswa mhs[10];
	int n;

	cout << "Masukkan jumlah mahasiswa: ";
	cin >> n;

	if(n > 10){
		cout << "Jumlah mahasiswa melebihi batas! Otomatis diatur ke 10." << endl;
	n = 10;
	}

	for(int i=0; i<n; i++){
		cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
		inputMhs(mhs[i]);
		mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
	}

	cout << "Data Mahasiswa:" << endl;
	for(int i=0; i<n; i++){
		cout << "NIM: " << mhs[i].nim << ", Nama: " << mhs[i].nama << ", Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
	}

	system("read -p 'Press Enter to continue...' var");

return 0;
}

```
##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan3/output/unguided1.png)

##### Penjelasan Unguided 1
Program ini digunakan untuk menyimpan dan menampilkan data maksimal 10 mahasiswa. Setiap mahasiswa memiliki data berupa nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir.

Struktur `mahasiswa` digunakan untuk menampung data tiap mahasiswa. Fungsi `inputMhs()` berfungsi meminta input data dari pengguna, sedangkan fungsi `nilaiAkhir()` digunakan untuk menghitung nilai akhir berdasarkan rumus yang diberikan.

Pada bagian `main()`, program meminta jumlah mahasiswa yang akan dimasukkan. Jika jumlahnya lebih dari 10, program otomatis membatasi hanya 10 data. Setelah semua data diinput, program menampilkan daftar mahasiswa beserta nilai akhirnya ke layar.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file"pelajaran.h": 
Type pelajaran < namaMapel : string kodeMapel : string function create_pelajaran( namapel : string, kodepel: string ) → pelajaran procedure tampil_pelajaran( input pel: pelajaran 

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp" 
Cobalah hasil implementasi ADT pada file "main.cpp" 
using namespace std; int main() { string namapel = "Struktur Data"; string kodepel = "STD"; pelajaran pel = create_pelajaran (namapel,kodepel); tampil_pelajaran(pel); return 0; }
```C++
--- file pelajaran.cpp ---
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(std::string namapel, std::string kodepel) {
	pelajaran p;
	p.namaMapel = namapel;
	p.kodeMapel = kodepel;
	return p;
}

void tampil_pelajaran(pelajaran pel) {
	cout << "nama pelajaran : " << pel.namaMapel << endl;
	cout << "nilai : " << pel.kodeMapel << endl;
}
```

```C++
--- file pelajaran.h ---
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
	string namaMapel;
	string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

```C++
--- file main.cpp ---
#include <iostream>
#include "pelajaran.h"
#include <cstdlib>
using namespace std;

int main(){
	string namapel = "Struktur Data";
	string kodepel = "STD";

	pelajaran pel = create_pelajaran(namapel, kodepel);
	tampil_pelajaran(pel);

	system("read -p 'Press Enter to continue...' var");
	return 0;
}
```
##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan3/output/unguided2.png)

##### Penjelasan Unguided 2
Program ini digunakan untuk menampilkan data pelajaran dengan nama dan kode pelajaran.
File **`pelajaran.h`** berisi **struktur `pelajaran`** yang menyimpan dua data, yaitu `namaMapel` dan `kodeMapel`, serta deklarasi dua fungsi: `create_pelajaran()` dan `tampil_pelajaran()`.

File **`pelajaran.cpp`** berisi **implementasi fungsi**:
- `create_pelajaran()` digunakan untuk membuat dan mengisi data pelajaran berdasarkan nama dan kode yang diberikan.
- `tampil_pelajaran()` berfungsi untuk menampilkan data pelajaran ke layar.
File **`main.cpp`** adalah **program utama** yang membuat objek `pelajaran`, mengisi datanya dengan memanggil `create_pelajaran()`, dan menampilkan hasilnya menggunakan `tampil_pelajaran()`.

#### 3. Buatlah program dengan ketentuan : 
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu 
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

// fungsi untuk menampilkan isi array
void tampilArray(int arr[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// fungsi untuk menukar nilai
void tukarNilai(int *ptrA, int *ptrB){
	int temp = *ptrA;
	*ptrA = *ptrB;
	*ptrB = temp;
}

int main(){
	int arrA[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int arrB[3][3] = {
		{9, 8, 7},
		{6, 5, 4},
		{3, 2, 1}
	};

	cout << "--- SEBELUM DITUKAR ---" << endl;
	cout << "Array A :" << endl;
	tampilArray(arrA);
	cout << "Array B :" << endl;
	tampilArray(arrB);

	// penukaran setiap elemen
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			tukarNilai(&arrA[i][j], &arrB[i][j]);
		}
	}

	cout << "\n--- SETELAH DITUKAR ---" << endl;
	cout << "Array A :" << endl;
	tampilArray(arrA);
	cout << "Array B :" << endl;
	tampilArray(arrB);

	return 0;
}
```
##### Output 3
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan3/output/unguided3.png)

##### Penjelasan Unguided 3
Program ini digunakan untuk menukar isi dari dua array dua dimensi berukuran 3×3.

Fungsi **`tampilArray()`** digunakan untuk menampilkan seluruh elemen array ke layar dalam bentuk matriks. Fungsi **`tukarNilai()`** berfungsi menukar dua nilai dengan memanfaatkan **pointer**, yaitu menukar nilai dari alamat memori yang ditunjuk oleh `ptrA` dan `ptrB`.

Di dalam fungsi **`main()`**, terdapat dua array (`arrA` dan `arrB`) yang masing-masing berisi angka berbeda. Program pertama menampilkan isi kedua array sebelum ditukar, lalu melakukan proses penukaran seluruh elemen dengan memanggil fungsi `tukarNilai()` di dalam dua perulangan bersarang (`for`). Setelah itu, hasil penukaran ditampilkan kembali ke layar.
___
## Kesimpulan
Dari praktikum Modul 3 tentang _Abstract Data Type (ADT)_, dapat disimpulkan bahwa ADT berfungsi untuk memisahkan antara **definisi data** dan **operasi yang dapat dilakukan terhadap data tersebut**, tanpa perlu mengetahui detail implementasinya.

Melalui beberapa latihan program, mahasiswa mempelajari cara membuat dan mengimplementasikan **struktur data (`struct`)** sebagai bentuk sederhana dari ADT di C++. Penerapan ini meliputi:

- Pembuatan **record/struct** untuk menyimpan data dengan berbagai tipe (seperti data mahasiswa dan pelajaran).
- Penggunaan **fungsi terpisah** untuk melakukan operasi terhadap data, seperti menghitung nilai rata-rata atau menampilkan informasi.
- Pemanfaatan **pointer** untuk mengakses dan menukar nilai pada alamat memori tertentu.
___
## Referensi
[1] Schmidt, D. C., ADTs, D. O. U., & ADTs, B. I. C++ Support for Abstract Data Types.
[2] Zani, M. (2019, April 12). TIPE DATA REKAMAN. https://doi.org/10.31219/osf.io/jvx3y.