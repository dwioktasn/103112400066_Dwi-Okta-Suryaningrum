#include <iostream>
using namespace std;

int main(){
    int angka1, angka2; //deklarasi variabel
    cout << "Masukkan angka 1: "; 
    cin >> angka1; //masukin input 1
    cout << "Masukkan angka 2: ";
    cin >> angka2; //masukin input 2

    cout << "Hasil Penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil Pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil Perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil Pembagian: " << angka1 / angka2 << endl;
    cout << "Sisa Bagi: " << angka1 % angka2 << endl;
    return 0;
}

// long itu buat naikin range nya
// b