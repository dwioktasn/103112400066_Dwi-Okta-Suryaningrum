#include <iostream>
using namespace std;

//fungsi
float penjumlahan(float x, float y){
    return x + y;
}

float pengurangan(float x, float y){
    return x - y;
}

float perkalian(float x, float y){
    return x * y;
}
float pembagian(float x, float y){
    return x / y;
}

int main(){
    float a, b;

    //inputan
    cout << "Masukkan angka pertama : ";
    cin >> a;
    cout << "Masukkan angka kedua : ";
    cin >> b;

    cout << "Hasil Penjumlahan : " << penjumlahan(a,b) << endl;
    cout << "Hasil Pengurangan : " << pengurangan(a,b) << endl;
    cout << "Hasil Perkalian : " << perkalian(a,b) << endl;
    cout << "Hasil Pembagian : " << pembagian(a,b) << endl;

    return 0;
}
