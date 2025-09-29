#include <iostream>
using namespace std;


int main(){
    float a, b, penjumlahan, pengurangan, perkalian, pembagian;

    //inputan
    cout << "Masukkan angka pertama : ";
    cin >> a;
    cout << "Masukkan angka kedua : ";
    cin >> b;

    //operasi
    penjumlahan = a + b;
    pengurangan = a - b;
    perkalian = a * b;
    pembagian = a / b;

    //output
    cout << "Hasil Penjumlahan : " << penjumlahan << endl;
    cout << "Hasil Pengurangan : " << pengurangan << endl;
    cout << "Hasil Perkalian : " << perkalian << endl;
    cout << "Hasil Pembagian : " << pembagian << endl;
    return 0;
}