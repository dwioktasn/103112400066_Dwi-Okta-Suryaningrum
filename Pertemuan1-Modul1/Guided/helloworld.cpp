#include <iostream>
using namespace std;

int main(){
    int angka1, angka2; //deklarasi variabel
    cout << "Masukkan angka 1: "; 
    cin >> angka1; //masukin input 1
    cout << "Masukkan angka 2: ";
    cin >> angka2; //masukin input 2

    if(angka1 <angka2){
        cout <<  angka1 << " kurang dari " << angka2 << endl;
    } else{
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if(angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if(angka1 != angka2){
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "Masukkan pilihan : " << endl;
    cin >> pilihan;

    int penjumlahan = angka1 + angka2;

    switch (pilihan){
        case 1:
            cout << "Hasil Penjumlahan: " << penjumlahan << endl;
            break;
        case 2:
            cout << "Hasil Pengurangan: " << angka1 - angka2 << endl;
            break;
        default:
            cout << "Pilihan salah" << endl;
            break;
    }
    return 0;
}
//prosedur pakainya void