<h1 align = "center">Laporan Praktikum Modul 2<br>PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">Dwi Okta Suryaningrum - 103112400066</p>
## Dasar Teori
___
Pointer adalah sebuah variabel yang isinya bukan data biasa (seperti angka atau teks), melainkan sebuah alamat memori. Pointer merupakan variabel penunjuk yang menyimpan alamat suatu memori sebagai lokasi penyimpanan data di RAM. Sedangkan Fungsi merupakan blok program yang melakukan suatu aksi tertentu berdasarkan input yang diterima dan mengembalikan sebuah nilai ketika deklarasinya dipanggil dalam sebuah program[1]. Selain pointer dan fungsi, dalam pemrograman C++ juga dikenal berbagai algoritma pengurutan (_sorting_). _Sorting_ merupakan proses penting dalam pengolahan data agar data tersusun secara sistematis dan lebih mudah digunakan dalam pencarian maupun penyimpanan. Terdapat banyak metode _sorting_, seperti _Insertion Sort_, _Selection Sort_, _Bubble Sort_, _Merge Sort_, dan _Quick Sort_ [2].

**Bubble Sort**  
Bubble Sort merupakan algoritma pengurutan sederhana yang bekerja dengan cara membandingkan elemen-elemen berdekatan dan menukarnya apabila tidak sesuai urutan. Proses ini dilakukan secara berulang hingga semua elemen dalam array terurut. Nama _Bubble_ diambil karena pergerakan elemen kecil yang “mengapung” ke atas layaknya gelembung sabun. Namun, kekurangan Bubble Sort adalah kompleksitasnya yang relatif lambat karena membutuhkan banyak perbandingan (O(n²)) [2].

**Quick Sort**  
Quick Sort termasuk algoritma pengurutan cepat yang menggunakan prinsip _Divide and Conquer_. Data dibagi menjadi dua bagian berdasarkan pivot, yaitu nilai acuan. Elemen yang lebih kecil dari pivot dipindahkan ke sebelah kiri, sedangkan elemen yang lebih besar ditempatkan di sebelah kanan. Proses ini dilakukan secara rekursif pada tiap sub-array hingga data benar-benar terurut. Quick Sort lebih efisien dibanding Bubble Sort, terutama untuk jumlah data besar, dengan rata-rata kompleksitas O(n log n) [2].
___
## Guided
___
#### 1. ARRAY POINTER
```C++

# include <iostream>
using namespace std;

int main(){
	int arr[] = {10, 20, 30, 40, 50};
	int *ptr = arr; // pointer yang menunjuk ke elemen pertama array

//mengakses elemen array menggunakan pointer
	for(int i = 0; i < 5; i++){
		cout << "Elemen array ke-" << i+1 << " menggunakan pointer: " << *(ptr+i) <<endl;
	}

// mengakses elemem array meneggunakan indeks
	for(int i = 0; i < 5; i++){
		cout << "Elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
	}
	return 0;
}

```
##### Penjelasan Singkat
program ini mengurutkan sebuah array angka dari yang terkecil hingga terbesar menggunakan metode **Selection Sort**.
Cara kerjanya sangat sederhana, seperti merapikan barisan:

1. Cari angka **paling kecil** di seluruh daftar, lalu **pindahkan** ke posisi paling depan.
2. Abaikan posisi pertama. Cari lagi angka **paling kecil** dari sisa daftar, lalu **pindahkan** ke posisi kedua.
3. Ulangi terus proses ini sampai semua angka terurut.
 ___
## Unguided
___
#### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini : 
matriksA = [ 7 12 22 31 6 41 15 19 36 ] MatriksB = [ 11 34 7 3 25 41 5 18 33 ] Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini : 
--- Menu Program Matriks --- 
1. Penjumlahan matriks 
2. Pengurangan matriks 
3. Perkalian matriks
4. Keluar
```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			arrC[i][j] = arrA[i][j] + arrB[i][j];
		}
	}
	cout << "Hasil penjumlahan: " << endl;
	tampilkanHasil(arrC);
}

void kurangMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			arrC[i][j] = arrA[i][j] - arrB[i][j];
		}
	}
	cout << "Hasil pengurangan: " << endl;
	tampilkanHasil(arrC);
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int arrD[3][3]){
	for(int i = 0; i < 3; i++){ //perulangan baris
		for(int j = 0; j < 3; j++){ //perulangan kolom
			for (int k =0; k < 3; k++){ //perulangan perkalian
				arrD[i][j] += arrA[i][k] * arrB[k][j];
			}
		}
	}
	cout << "Hasil perkalian: " << endl;
	tampilkanHasil(arrD);
}

int main(){
	int arrA[3][3]={
		{7, 12, 22},
		{31, 6, 41},
		{15, 19, 36}
	};
	
	int arrB[3][3]={
		{11, 34, 7},
		{3, 25, 41},
		{5, 18, 33}
	};
	
	int arrC[3][3]={0};
	int arrD[3][3]={0};


	int pilihan;
	cout << " --- Menu Program Matriks --- " << endl;
	cout << "1. Penjumlahan Matriks" << endl;
	cout << "2. Pengurangan Matriks" << endl;
	cout << "3. Perkalian Matriks" << endl;
	cout << "4. Keluar " << endl;

	cout << "Masukkan pilihan : ";
	cin >> pilihan;
	switch (pilihan)
	{
	case 1:
		jumlahMatriks(arrA, arrB, arrC);
		break;
	case 2:
		kurangMatriks(arrA, arrB, arrC);
		break;
	case 3:
		kaliMatriks(arrA, arrB, arrD);
		break;
	default:
		break;
	}
}

```
##### Output 1
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan2/output/output-unguided-1.png)

##### Penjelasan Unguided 1
Program mempunyai dua tabel angka yang berbentuk matriks yaitu matriks arrA dan arrB. terdapat dua tabel kosong juga yaitu arrC dan arrD yang nantinya digunakan untuk menampung hasil perhitungan. ketika di run, program akan menampilkan menu pilihan, nanti user menginputkan menu yang diinginkan.
- Jika pilih 1 (Penjumlahan): Program akan mengambil setiap angka di tabel A dan menambahkannya dengan angka di posisi yang sama persis di tabel B. Hasilnya ditaruh di tabel kosong tadi.
- Jika pilih 2 (Pengurangan): Sama seperti penjumlahan, tapi operasinya dikurangi.
- Jika pilih 3 (Perkalian): Program akan melakukan proses perkalian matriks yang sedikit lebih rumit, yaitu mengalikan setiap baris di tabel A dengan setiap kolom di tabel B.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut: 
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0). 
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar. 
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 
4) Cetak nilai luas ke layar. 
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar. 
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.
```C++
#include <iostream>
using namespace std;

void ubahNilai(int *ptrPanjang, int *ptrLebar, int &refLuas, int &refKeliling){
	refLuas = (*ptrPanjang) * (*ptrLebar); //menghitung luas
	refKeliling = 2 * ((*ptrPanjang) + (*ptrLebar)); //menghitung keliling
}

int main(){
	int panjang = 10;
	int lebar = 5;
	int luas = 0;
	int keliling = 0;

	cout << "--- Nilai Awal : ---" << endl;
	cout << "Panjang : " << panjang << endl;
	cout << "Lebar : " << lebar << endl;
	cout << endl;

	ubahNilai(&panjang, &lebar, luas, keliling);
	cout << "--- Hasil Perhitungan ---" << endl;
	cout << "Luas Persegi Panjang : " << luas << endl;
	cout << "Keliling Persegi Panjang : " << keliling << endl;
	cout << endl;

	cout << "--- Nilai Setelah Perhitungan ---" << endl;
	cout << "Panjang baru : ";
	cin >> panjang;
	cout << "Lebar baru : ";
	cin >> lebar;
	ubahNilai(&panjang, &lebar, luas, keliling);
	cout << "Luas Baru: " << luas << endl;
	cout << "Keliling Baru: " << keliling << endl;
}
```
##### Output 2
>![](103112400066_Dwi%20Okta%20Suryaningrum/Laporan2/output/output-unguided-2.png)

##### Penjelasan Unguided 2
menunjukkan bagaimana sebuah fungsi ubahNilai bisa mengubah nilai variabel (luas dan keliling) yang berada di main secara langsung.
menggunakan pointer untuk varibel panjang, dan lebar, jadi fungsi ubahNilai tidak menerima nilai (misalnya 10) tapi menerima alamat memori dari variabel tersebut. sedangkan reference untuk variabel luas dan keliling itu seperti nama panggilan. refLuas menjadi nama lain untuk luas, jadi saat fungsi mengubah refLuas, ia sebenarnya sedang mengubah variabel luas yang asli.

___
## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa pointer dalam C++ berperan penting karena mampu mengakses dan mengubah nilai variabel melalui alamat memori, sehingga lebih efisien saat digunakan bersama fungsi. Fungsi sendiri membantu program menjadi lebih terstruktur karena setiap operasi bisa dipisahkan ke dalam blok tersendiri.

Percobaan pada array pointer menunjukkan bahwa data bisa diakses baik lewat indeks maupun pointer dengan hasil yang sama. Pada operasi matriks, penggunaan prosedur membuat perhitungan penjumlahan, pengurangan, dan perkalian menjadi lebih mudah dan rapi. Sedangkan pada program persegi panjang, penggunaan pointer dan reference terbukti dapat langsung memengaruhi nilai variabel utama.

Selain itu, dari kajian teori tentang algoritma pengurutan, terlihat bahwa Bubble Sort cukup sederhana tetapi kurang efisien, sementara Quick Sort lebih cepat karena menggunakan metode _Divide and Conquer_. Secara keseluruhan, materi ini menjadi dasar penting untuk memahami pemrograman lanjutan di C++.
___
## Referensi
[1] Dwi Putra, Muhammad T., et al. _BELAJAR PEMROGRAMAN LANJUT DENGAN C++_. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA, 2023.
[2] Arifin, R. W., & Setiyadi, D. (2020). Algoritma Metode Pengurutan Bubble Sort dan Quick Sort Dalam Bahasa Pemrograman C++. _Information System For Educators And Professionals: Journal of Information System_, _4_(2), 178-â.